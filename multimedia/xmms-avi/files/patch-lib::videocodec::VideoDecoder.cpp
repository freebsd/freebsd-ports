--- lib/videocodec/VideoDecoder.cpp.orig	Sun Feb  4 14:19:47 2001
+++ lib/videocodec/VideoDecoder.cpp	Sun Dec  7 02:30:26 2003
@@ -44,7 +44,7 @@
     void clear(){handle=0;}
 };
 
-IVideoDecoder* IVideoDecoder::Create(const BITMAPINFOHEADER& bh, int depth=24, int flip=0)
+IVideoDecoder* IVideoDecoder::Create(const BITMAPINFOHEADER& bh, int depth, int flip)
 {
     vector<CodecInfo>::iterator it;
     vector<int>::iterator iv;
@@ -327,7 +327,7 @@
 	}    
 	return 0;
 }
-int VideoDecoder::SetDestFmt(int bits=24, int csp=0)
+int VideoDecoder::SetDestFmt(int bits, int csp)
 {
     if(m_iState==0)
 	return -1;
