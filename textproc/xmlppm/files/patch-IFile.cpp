--- IFile.cpp.orig	Wed Jul 23 04:32:54 2003
+++ IFile.cpp	Wed Jul 23 04:35:43 2003
@@ -100,7 +100,7 @@
   while(insz > 0) {
     size_t result;
     outsz = BUFFSIZE;
-    result = iconv(ifile->iconv, &(char*)inptr, &insz, &outptr, &outsz);
+    result = iconv(ifile->iconv, &inptr, &insz, &outptr, &outsz);
     total += fwrite(outbuf, sizeof(char), BUFFSIZE-outsz, ifile->file);
     if(result == (size_t)-1 && errno != E2BIG) {
       return total;
