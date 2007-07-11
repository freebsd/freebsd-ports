--- include/videodecoder.h.orig	Fri Dec 15 09:12:07 2000
+++ include/videodecoder.h	Mon Jul  2 02:47:03 2007
@@ -55,7 +55,7 @@
      CAP_UYVY=8,
      CAP_YVYU=16 };
 
-    static IVideoDecoder* IVideoDecoder::Create(const BITMAPINFOHEADER& bh, int depth=24, int flip=0);
+    static IVideoDecoder* Create(const BITMAPINFOHEADER& bh, int depth=24, int flip=0);
     
     virtual ~IVideoDecoder(){}
     virtual void Start()			=0;
