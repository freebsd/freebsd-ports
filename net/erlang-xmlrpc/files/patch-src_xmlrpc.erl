--- src/xmlrpc.erl.orig	2003-04-23 19:06:45 UTC
+++ src/xmlrpc.erl
@@ -164,7 +164,14 @@ handle_payload(Socket, KeepAlive, Timeou
 
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
 
 %% Exported: start_link/{1,5,6}
 
