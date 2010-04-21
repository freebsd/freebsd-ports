--- libao2/ao_arts.c.orig	2009-03-06 13:43:12.000000000 -0600
+++ libao2/ao_arts.c	2009-07-23 19:57:44.090958744 -0500
@@ -116,8 +116,10 @@
 
 static void uninit(int immed)
 {
-	arts_close_stream(stream);
-	arts_free();
+	if (stream != NULL) {
+	    arts_close_stream(stream);
+	    stream = NULL;
+	}
 }
 
 static int play(void* data,int len,int flags)
