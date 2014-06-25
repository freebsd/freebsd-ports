--- src/shared/CLucene/LuceneThreads.h.orig	2011-03-17 01:21:07.000000000 +0100
+++ src/shared/CLucene/LuceneThreads.h	2013-09-03 18:25:01.380067076 +0200
@@ -7,6 +7,9 @@
 #ifndef _LuceneThreads_h
 #define  _LuceneThreads_h
 
+#if defined(_CL_HAVE_PTHREAD)
+#include <pthread.h>
+#endif
 
 CL_NS_DEF(util)
 class CLuceneThreadIdCompare;
