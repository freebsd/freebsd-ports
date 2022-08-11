- fix of this failure on arm64:
-
- In file included from /wrkdirs/usr/ports/math/reduce/work/Reduce-svn6339-src/generic/newfront/redchild.c:31:
- /wrkdirs/usr/ports/math/reduce/work/Reduce-svn6339-src/generic/newfront/redfront.h:118:12: error: conflicting types for '__wcwidth'
- extern int wcwidth(wchar_t c);
-            ^
- /usr/include/wchar.h:213:21: note: expanded from macro 'wcwidth'
- #define wcwidth(_c)     __wcwidth(_c)
-                         ^
- /usr/include/_ctype.h:161:1: note: previous definition is here
- __wcwidth(__ct_rune_t _c)
- ^
- 1 error generated.

--- generic/newfront/redfront.h.orig	2021-03-16 10:41:22 UTC
+++ generic/newfront/redfront.h
@@ -115,7 +115,9 @@ typedef void (*sig_t)(int);
  */
 #ifndef NATIVE_WINDOWS
 #include "sys.h"
+#  if !defined(__FreeBSD__)
 extern int wcwidth(wchar_t c);
+#  endif
 #include "chartype.h"
 #endif
 
