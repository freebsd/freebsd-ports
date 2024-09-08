--- ffs.h.orig	2024-08-22 17:41:01 UTC
+++ ffs.h
@@ -32,6 +32,16 @@
 #include <sys/reg.h>
 #endif
 
+#include <stdint.h>
+
+#ifndef __WORDSIZE
+#if defined(UINTPTR_MAX) && defined(UINT64_MAX) && (UINTPTR_MAX == UINT64_MAX)
+#define __WORDSIZE 64
+#else
+#define __WORDSIZE 32
+#endif
+#endif
+
 #ifdef HAVE_FFS
 # define myffs(x) ffs(x)
 # if __WORDSIZE == 32
@@ -57,12 +67,9 @@
 # define myffsl(x) myffsl_c(x)
 #endif
 
-#ifndef __BYTE_ORDER
+#ifndef BYTE_ORDER
 # error Need to define __BYTE_ORDER
 #endif
-#ifndef __WORDSIZE
-# error Need to define __WORDSIZE
-#endif
 
 //#ifndef HAVE_FFS
 #ifdef NEED_FFSL_C
@@ -96,7 +103,7 @@ static int myffsl_c(unsigned long val)
 }
 #endif
 
-#if __BYTE_ORDER == __BIG_ENDIAN || defined(TEST)
+#if BYTE_ORDER == BIG_ENDIAN || defined(TEST)
 /** Find last (highest) bit set in word val, returns a val b/w __WORDSIZE and 1, 0 if no bit is set */
 static int myflsl(unsigned long val)
 {
@@ -141,6 +148,8 @@ void probe_sse42();
 int myffs_sse42(unsigned long);
 int myffsl_sse42(unsigned long);
 void probe_sse42();
+#else
+# define myflsl(x) flsl(x)
 #endif
 
 #endif /* _FFS_H */
