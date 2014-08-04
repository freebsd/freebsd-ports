--- ffs.h.orig	2014-02-22 05:39:33.000000000 +0900
+++ ffs.h	2014-06-29 01:21:32.000000000 +0900
@@ -27,7 +27,7 @@
 #ifdef HAVE_ENDIAN_H
 #include <endian.h>
 #endif
-
+#include <stdint.h>
 
 #ifdef HAVE_FFS
 # define myffs(x) ffs(x)
@@ -50,7 +50,7 @@
 # define myffsl(x) myffsl_c(x)
 #endif
 
-#ifndef __BYTE_ORDER
+#ifndef BYTE_ORDER
 # error Need to define __BYTE_ORDER
 #endif
 #ifndef __WORDSIZE
@@ -88,7 +88,7 @@
 }
 #endif
 
-#if __BYTE_ORDER == __BIG_ENDIAN || defined(TEST)
+#if BYTE_ORDER == BIG_ENDIAN || defined(TEST)
 /** Find last (highest) bit set in word val, returns a val b/w __WORDSIZE and 1, 0 if no bit is set */
 static int myflsl(unsigned long val)
 {
@@ -117,6 +117,8 @@
 	}
 	return res;
 }
+#else
+# define myflsl(x) flsl(x)
 #endif
 
 void probe_sse42();
