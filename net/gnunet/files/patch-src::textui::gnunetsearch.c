--- src/textui/gnunetsearch.c.orig	Wed Jul 31 10:18:44 2002
+++ src/textui/gnunetsearch.c	Fri Aug  2 18:38:36 2002
@@ -222,7 +222,7 @@
 		&sig.sa_mask,
 		&sig.sa_mask); /* essentially: zero out */
 
-    sig.sa_flags = SA_ONESHOT;
+    sig.sa_flags = SA_RESETHAND;
     
     sigaction(SIGINT,  &sig, &oldsig);
     sigaction(SIGTERM, &sig, &oldsig);
