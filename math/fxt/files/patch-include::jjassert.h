--- include/jjassert.h.orig	Sun Feb 23 14:08:38 2003
+++ include/jjassert.h	Sun Feb 23 14:08:56 2003
@@ -2,7 +2,7 @@
 #define      HAVE_JJASSERT_H__
 
 // if you don't have sys/cdefs.h just uncomment the next line:
-//#include <sys/cdefs.h>  // __STRING()
+#include <sys/cdefs.h>  // __STRING()
 
 // aux0/jjassert.cc:
 // options for last action of jjassert_fail():
