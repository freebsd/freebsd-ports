--- ./hyphen.h.orig	2013-03-18 11:49:03.000000000 +0100
+++ ./hyphen.h	2014-06-30 09:22:00.804214782 +0200
@@ -55,6 +55,8 @@
 extern "C" {
 #endif /* __cplusplus */
 
+#include <stdio.h>
+
 typedef struct _HyphenDict HyphenDict;
 typedef struct _HyphenState HyphenState;
 typedef struct _HyphenTrans HyphenTrans;
