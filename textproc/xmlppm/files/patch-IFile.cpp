--- IFile.cpp.orig	Thu Jun 10 04:16:13 2004
+++ IFile.cpp	Tue Aug 17 23:21:02 2004
@@ -73,7 +73,7 @@
    writing the output.  Then flush the file.  */
 void ifflush(IFILE* ifile) {
   static char outbuf[BUFFSIZE];
-  char* inptr = ifile->buf;
+  const char* inptr = ifile->buf;
   char* outptr = outbuf;
   size_t insz = ifile->bufsiz;
   size_t outsz;
