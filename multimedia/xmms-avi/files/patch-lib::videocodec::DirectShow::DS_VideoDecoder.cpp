--- lib/videocodec/DirectShow/DS_VideoDecoder.cpp.orig	Sat Jan 20 06:00:54 2001
+++ lib/videocodec/DirectShow/DS_VideoDecoder.cpp	Sun Dec  7 02:30:26 2003
@@ -368,7 +368,7 @@
 
     return 0;
 }
-int DS_VideoDecoder::SetDestFmt(int bits=24, int csp=0)
+int DS_VideoDecoder::SetDestFmt(int bits, int csp)
 {
     if(m_iState==0)
 	return -1;
