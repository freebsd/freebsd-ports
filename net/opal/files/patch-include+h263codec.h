--- include/h263codec.h.orig	Sat Feb 19 11:29:15 2005
+++ include/h263codec.h	Sat Feb 19 11:38:52 2005
@@ -92,6 +92,7 @@
 struct AVCodec;
 struct AVCodecContext;
 struct AVFrame;
+struct AVCodecParserContext;
 
 ///////////////////////////////////////////////////////////////////////////////
 
@@ -478,7 +479,7 @@
        send. Note that for every encode thread, this 1 method is called. Consequently, 
        code is required to separate out packets from different encode threads.
     */
-    static void RtpCallback(void *data, int size, int packetNumber);
+    static void RtpCallback(AVCodecContext *s, void *data, int size, int packetNumber);
 
   protected:
     BOOL Resize(int width, int height);
