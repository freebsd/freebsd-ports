--- src/continuation.h.orig	2011-02-18 16:29:10.000000000 +0000
+++ src/continuation.h	2011-02-20 17:50:37.000000000 +0000
@@ -21,6 +21,7 @@
 #ifndef _CONTINUATION_H_
 #define _CONTINUATION_H_
 
+#include <sys/types.h>
 #include <ucontext.h>
 
 struct continuation
