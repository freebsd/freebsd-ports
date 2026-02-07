--- simUtil/src/ddcMalloc.c.orig	2022-08-24 19:49:58 UTC
+++ simUtil/src/ddcMalloc.c
@@ -381,6 +381,8 @@ void printHeapInfo(FILE* file)
 {
 #ifdef __APPLE__
  fprintf(file, "In routine printHeapInfo no mallinfo on OS X. Sorry.\n");
+#elif defined(__FreeBSD__)
+ fprintf(file, "In routine printHeapInfo no mallinfo on FreeBSD. Sorry.\n");
 #else
    struct mallinfo minfo;
    minfo = mallinfo();
@@ -397,6 +399,8 @@ void printHeapInfo_pio(PFILE* file)
 {
 #ifdef __APPLE__
    Pprintf(file, "No mallinfo on OS X.  Sorry.\n");
+#elif defined(__FreeBSD__)
+   Pprintf(file, "No mallinfo on FreeBSD.  Sorry.\n");
 #else
    struct mallinfo minfo;
    minfo = mallinfo();
