--- lib/avifile/AVIReadHandler2.cpp.orig	Thu Jan 11 03:01:12 2001
+++ lib/avifile/AVIReadHandler2.cpp	Sun Dec  7 02:30:26 2003
@@ -456,7 +456,7 @@
 ///////////////////////////////////////////////////////////////////////////
 
 class AVIReadStream2 : public IvAVIReadStream {
-	friend AVIReadHandler2;
+	friend class AVIReadHandler2;
 
 public:
 	AVIReadStream2(AVIReadHandler2 *, ASFStreamNode *, int);
