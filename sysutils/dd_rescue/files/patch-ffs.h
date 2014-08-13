--- ffs.h.orig	2014-02-22 05:39:33.000000000 +0900
+++ ffs.h	2014-08-13 22:46:51.000000000 +0900
@@ -27,7 +27,15 @@
 #ifdef HAVE_ENDIAN_H
 #include <endian.h>
 #endif
+#include <stdint.h>
 
+#ifndef __WORDSIZE
+#if defined(UINTPTR_MAX) && defined(UINT64_MAX) && (UINTPTR_MAX == UINT64_MAX)
+#define __WORDSIZE 64
+#else
+#define __WORDSIZE 32
+#endif
+#endif
 
 #ifdef HAVE_FFS
 # define myffs(x) ffs(x)
@@ -50,12 +58,9 @@
 # define myffsl(x) myffsl_c(x)
 #endif
 
-#ifndef __BYTE_ORDER
+#ifndef BYTE_ORDER
 # error Need to define __BYTE_ORDER
 #endif
-#ifndef __WORDSIZE
-# error Need to define __WORDSIZE
-#endif
 
 #ifndef HAVE_FFS
 /** Find first (lowest) bit set in word val, returns a val b/w 1 and __WORDSIZE, 0 if no bit is set */
@@ -88,7 +93,7 @@
 }
 #endif
 
-#if __BYTE_ORDER == __BIG_ENDIAN || defined(TEST)
+#if BYTE_ORDER == BIG_ENDIAN || defined(TEST)
 /** Find last (highest) bit set in word val, returns a val b/w __WORDSIZE and 1, 0 if no bit is set */
 static int myflsl(unsigned long val)
 {
@@ -117,6 +122,8 @@
 	}
 	return res;
 }
+#else
+# define myflsl(x) flsl(x)
 #endif
 
 void probe_sse42();
