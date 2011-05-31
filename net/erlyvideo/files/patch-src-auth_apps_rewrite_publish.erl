--- src/auth/apps_rewrite_publish.erl.orig	2011-03-20 12:57:33.000000000 +0300
+++ src/auth/apps_rewrite_publish.erl	2011-05-30 12:49:42.000000000 +0400
@@ -32,4 +32,4 @@
 
 publish(#rtmp_session{} = State, #rtmp_funcall{args = [null, Name | _Args]} = AMF) when is_binary(Name) ->
   Mod = {apps_rewrite_play, URL},
-  Mod:run_http_request(State, AMF).
+  Mod:play(State, AMF).
