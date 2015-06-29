--- src/xmlrpc_http.erl.orig	2003-04-23 19:06:45 UTC
+++ src/xmlrpc_http.erl
@@ -142,7 +142,14 @@ handle_payload(Socket, Timeout, Handler,
 
 get_payload(Socket, Timeout, ContentLength) ->
     inet:setopts(Socket, [{packet, raw}]),
-    gen_tcp:recv(Socket, ContentLength, Timeout).
+    get_payload(Socket, Timeout, ContentLength, []).
+
+get_payload(Socket, Timeout, 0, Payload) ->
+    {ok, lists:concat(lists:reverse(Payload))};
+
+get_payload(Socket, Timeout, ContentLength, Payload) ->
+    {ok, Bin} = gen_tcp:recv(Socket, 0, Timeout),
+    get_payload(Socket, Timeout, ContentLength - length(Bin), [Bin|Payload]).
 
 eval_payload(Socket, Timeout, {M, F} = Handler, State, Connection, Payload) ->
     case catch M:F(State, Payload) of
@@ -190,6 +197,7 @@ send(Socket, StatusCode, ExtraHeader, Pa
     Response =
 	["HTTP/1.1 ", integer_to_list(StatusCode), " ",
 	 reason_phrase(StatusCode), "\r\n",
+	 "Content-Type: text/xml\r\n",
 	 "Content-Length: ", integer_to_list(lists:flatlength(Payload)),
 	 "\r\n",
 	 "Server: Erlang/1.13\r\n",
