--- libao2/ao_arts.c.orig	Fri Dec 27 14:35:07 2002
+++ libao2/ao_arts.c	Mon Mar  3 17:10:38 2003
@@ -102,8 +102,14 @@
 
 static void uninit()
 {
-	arts_close_stream(stream);
+	if (stream != NULL) {
+		arts_close_stream(stream);
+		stream = NULL;
+        }
+/* XXX - we get "MPlayer interrupted by signal 11 in module:
+   exit_player" unless commented :(
 	arts_free();
+*/ 
 }
 
 static int play(void* data,int len,int flags)
