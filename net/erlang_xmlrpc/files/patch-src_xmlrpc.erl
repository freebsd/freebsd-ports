
$FreeBSD$

--- src/xmlrpc.erl.orig	Fri May 23 10:47:55 2003
+++ src/xmlrpc.erl	Fri May 23 10:47:57 2003
@@ -164,7 +164,14 @@
 
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
