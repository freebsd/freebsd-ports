
$FreeBSD$

--- src/xmlrpc_http.erl.orig	Wed Apr 23 21:06:45 2003
+++ src/xmlrpc_http.erl	Fri May 23 11:59:38 2003
@@ -142,7 +142,14 @@
 
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
@@ -190,6 +197,7 @@
     Response =
 	["HTTP/1.1 ", integer_to_list(StatusCode), " ",
 	 reason_phrase(StatusCode), "\r\n",
+	 "Content-Type: text/xml\r\n",
 	 "Content-Length: ", integer_to_list(lists:flatlength(Payload)),
 	 "\r\n",
 	 "Server: Erlang/1.13\r\n",
