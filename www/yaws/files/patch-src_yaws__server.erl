
$FreeBSD$

--- src/yaws_server.erl.orig	Wed Jun 16 17:44:22 2004
+++ src/yaws_server.erl	Wed Jun 16 17:44:33 2004
@@ -122,7 +122,8 @@
 	true ->
 	    {ok, #state{gc = undefined,
 			pairs = [],
-			mnum = 0}}
+			mnum = 0,
+			embedded = Embedded }}
     end.
 
 
