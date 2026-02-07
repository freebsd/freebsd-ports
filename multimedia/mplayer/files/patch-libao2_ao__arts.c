--- libao2/ao_arts.c.orig	2010-02-20 21:02:49 UTC
+++ libao2/ao_arts.c
@@ -116,8 +116,10 @@ static int init(int rate_hz, int channel
 
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
