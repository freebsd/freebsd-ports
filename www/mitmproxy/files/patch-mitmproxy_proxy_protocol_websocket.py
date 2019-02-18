--- mitmproxy/proxy/protocol/websocket.py.orig	2019-02-14 21:03:58 UTC
+++ mitmproxy/proxy/protocol/websocket.py
@@ -4,8 +4,9 @@ from OpenSSL import SSL
 
 
 import wsproto
-from wsproto import events
-from wsproto.connection import ConnectionType, WSConnection
+from wsproto import events, WSConnection
+from wsproto.connection import ConnectionType
+from wsproto.events import AcceptConnection, CloseConnection, Message, Ping, Request
 from wsproto.extensions import PerMessageDeflate
 
 from mitmproxy import exceptions
@@ -52,51 +53,52 @@ class WebSocketLayer(base.Layer):
 
         self.connections: dict[object, WSConnection] = {}
 
-        extensions = []
+        client_extensions = []
+        server_extensions = []
         if 'Sec-WebSocket-Extensions' in handshake_flow.response.headers:
             if PerMessageDeflate.name in handshake_flow.response.headers['Sec-WebSocket-Extensions']:
-                extensions = [PerMessageDeflate()]
-        self.connections[self.client_conn] = WSConnection(ConnectionType.SERVER,
-                                                          extensions=extensions)
-        self.connections[self.server_conn] = WSConnection(ConnectionType.CLIENT,
-                                                          host=handshake_flow.request.host,
-                                                          resource=handshake_flow.request.path,
-                                                          extensions=extensions)
-        if extensions:
-            for conn in self.connections.values():
-                conn.extensions[0].finalize(conn, handshake_flow.response.headers['Sec-WebSocket-Extensions'])
+                client_extensions = [PerMessageDeflate()]
+                server_extensions = [PerMessageDeflate()]
+        self.connections[self.client_conn] = WSConnection(ConnectionType.SERVER)
+        self.connections[self.server_conn] = WSConnection(ConnectionType.CLIENT)
 
-        data = self.connections[self.server_conn].bytes_to_send()
-        self.connections[self.client_conn].receive_bytes(data)
+        if client_extensions:
+            client_extensions[0].finalize(handshake_flow.response.headers['Sec-WebSocket-Extensions'])
+        if server_extensions:
+            server_extensions[0].finalize(handshake_flow.response.headers['Sec-WebSocket-Extensions'])
 
+        request = Request(extensions=client_extensions, host=handshake_flow.request.host, target=handshake_flow.request.path)
+        data = self.connections[self.server_conn].send(request)
+        self.connections[self.client_conn].receive_data(data)
+
         event = next(self.connections[self.client_conn].events())
-        assert isinstance(event, events.ConnectionRequested)
+        assert isinstance(event, events.Request)
 
-        self.connections[self.client_conn].accept(event)
-        self.connections[self.server_conn].receive_bytes(self.connections[self.client_conn].bytes_to_send())
-        assert isinstance(next(self.connections[self.server_conn].events()), events.ConnectionEstablished)
+        data = self.connections[self.client_conn].send(AcceptConnection(extensions=server_extensions))
+        self.connections[self.server_conn].receive_data(data)
+        assert isinstance(next(self.connections[self.server_conn].events()), events.AcceptConnection)
 
     def _handle_event(self, event, source_conn, other_conn, is_server):
-        if isinstance(event, events.DataReceived):
-            return self._handle_data_received(event, source_conn, other_conn, is_server)
-        elif isinstance(event, events.PingReceived):
-            return self._handle_ping_received(event, source_conn, other_conn, is_server)
-        elif isinstance(event, events.PongReceived):
-            return self._handle_pong_received(event, source_conn, other_conn, is_server)
-        elif isinstance(event, events.ConnectionClosed):
-            return self._handle_connection_closed(event, source_conn, other_conn, is_server)
+        if isinstance(event, events.Message):
+            return self._handle_message(event, source_conn, other_conn, is_server)
+        elif isinstance(event, events.Ping):
+            return self._handle_ping(event, source_conn, other_conn, is_server)
+        elif isinstance(event, events.Pong):
+            return self._handle_pong(event, source_conn, other_conn, is_server)
+        elif isinstance(event, events.CloseConnection):
+            return self._handle_close_connection(event, source_conn, other_conn, is_server)
 
         # fail-safe for unhandled events
         return True  # pragma: no cover
 
-    def _handle_data_received(self, event, source_conn, other_conn, is_server):
+    def _handle_message(self, event, source_conn, other_conn, is_server):
         fb = self.server_frame_buffer if is_server else self.client_frame_buffer
         fb.append(event.data)
 
         if event.message_finished:
             original_chunk_sizes = [len(f) for f in fb]
 
-            if isinstance(event, events.TextReceived):
+            if isinstance(event, events.TextMessage):
                 message_type = wsproto.frame_protocol.Opcode.TEXT
                 payload = ''.join(fb)
             else:
@@ -127,19 +129,20 @@ class WebSocketLayer(base.Layer):
                             yield (payload[i:i + chunk_size], True if i + chunk_size >= len(payload) else False)
 
                 for chunk, final in get_chunk(websocket_message.content):
-                    self.connections[other_conn].send_data(chunk, final)
-                    other_conn.send(self.connections[other_conn].bytes_to_send())
+                    data = self.connections[other_conn].send(Message(data=chunk, message_finished=final))
+                    other_conn.send(data)
 
         if self.flow.stream:
-            self.connections[other_conn].send_data(event.data, event.message_finished)
-            other_conn.send(self.connections[other_conn].bytes_to_send())
+            data = self.connections[other_conn].send(Message(data=event.data, message_finished=event.message_finished))
+            other_conn.send(data)
         return True
 
-    def _handle_ping_received(self, event, source_conn, other_conn, is_server):
-        # PING is automatically answered with a PONG by wsproto
-        self.connections[other_conn].ping()
-        other_conn.send(self.connections[other_conn].bytes_to_send())
-        source_conn.send(self.connections[source_conn].bytes_to_send())
+    def _handle_ping(self, event, source_conn, other_conn, is_server):
+        # Use event.response to create the approprate Pong response
+        data = self.connections[other_conn].send(Ping())
+        other_conn.send(data)
+        data = self.connections[source_conn].send(event.response())
+        source_conn.send(data)
         self.log(
             "Ping Received from {}".format("server" if is_server else "client"),
             "info",
@@ -147,7 +150,7 @@ class WebSocketLayer(base.Layer):
         )
         return True
 
-    def _handle_pong_received(self, event, source_conn, other_conn, is_server):
+    def _handle_pong(self, event, source_conn, other_conn, is_server):
         self.log(
             "Pong Received from {}".format("server" if is_server else "client"),
             "info",
@@ -155,14 +158,15 @@ class WebSocketLayer(base.Layer):
         )
         return True
 
-    def _handle_connection_closed(self, event, source_conn, other_conn, is_server):
+    def _handle_close_connection(self, event, source_conn, other_conn, is_server):
         self.flow.close_sender = "server" if is_server else "client"
         self.flow.close_code = event.code
         self.flow.close_reason = event.reason
 
-        self.connections[other_conn].close(event.code, event.reason)
-        other_conn.send(self.connections[other_conn].bytes_to_send())
-        source_conn.send(self.connections[source_conn].bytes_to_send())
+        data = self.connections[other_conn].send(CloseConnection(code=event.code, reason=event.reason))
+        other_conn.send(data)
+        data = self.connections[source_conn].send(event.response())
+        source_conn.send(data)
 
         return False
 
@@ -170,8 +174,7 @@ class WebSocketLayer(base.Layer):
         while True:
             try:
                 payload = message_queue.get_nowait()
-                self.connections[endpoint].send_data(payload, final=True)
-                data = self.connections[endpoint].bytes_to_send()
+                data = self.connections[endpoint].send(Message(data=payload, message_finished=True))
                 endpoint.send(data)
             except queue.Empty:
                 break
@@ -197,8 +200,8 @@ class WebSocketLayer(base.Layer):
                     is_server = (source_conn == self.server_conn)
 
                     frame = websockets.Frame.from_file(source_conn.rfile)
-                    self.connections[source_conn].receive_bytes(bytes(frame))
-                    source_conn.send(self.connections[source_conn].bytes_to_send())
+                    data = self.connections[source_conn].receive_data(bytes(frame))
+                    source_conn.send(data)
 
                     if close_received:
                         return
