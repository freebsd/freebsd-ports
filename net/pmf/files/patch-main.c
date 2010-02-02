--- ./main.c.orig	1991-09-21 23:13:43.000000000 -0400
+++ ./main.c	2010-02-02 14:21:04.000000000 -0500
@@ -12,9 +12,9 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sgtty.h>
 #include <signal.h>
 #include <setjmp.h>
+#include <sys/param.h>
 #include "safe_malloc.h"
 #include "str_galore.h"
 #include "config.h"
@@ -37,7 +37,7 @@
     extern int stop_printing();
     extern int continue_printing();
 
-    extern int last_c_pos;
+    extern int _rl_last_c_pos;
 #endif
 
 /* Longjmp buffer, jump there after error() or CTRL-C */
@@ -58,7 +58,7 @@
 	ldisplay("\n");
 	ldisplay("%s", rl_line_buffer);
 	rl_redisplay(count, key);
-	last_c_pos = rl_end;
+	_rl_last_c_pos = rl_end;
     }
 #endif
 
@@ -191,7 +191,11 @@
 #endif
 
     if (debug && exitval) {
+	#if defined(__FreeBSD__) && (__FreeBSD_version >= 500035)
+	signal(SIGABRT, SIG_DFL);
+	#else
 	signal(SIGIOT, SIG_DFL);
+	#endif
 	abort();
     }
     else
