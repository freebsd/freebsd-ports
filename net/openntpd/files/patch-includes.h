
$FreeBSD$

--- includes.h.orig	Sun Jul 11 07:31:31 2004
+++ includes.h	Mon Jul 12 14:25:37 2004
@@ -20,8 +20,12 @@
 # include <stdio.h>
 
 #ifndef IOV_MAX
+#if defined(__FreeBSD__)
+# define IOV_MAX	1024
+#else
 # define __need_IOV_MAX
 # include <bits/stdio_lim.h>
+#endif
 #endif
 
 #include "defines.h"
