--- salt/ext/tornado/iostream.py.orig	2023-05-16 11:50:28 UTC
+++ salt/ext/tornado/iostream.py
@@ -1116,6 +1116,7 @@ class IOStream(BaseIOStream):
             future = self._connect_future = TracebackFuture()
         try:
             self.socket.connect(address)
+            self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, 524288)
         except socket.error as e:
             # In non-blocking mode we expect connect() to raise an
             # exception with EINPROGRESS or EWOULDBLOCK.
