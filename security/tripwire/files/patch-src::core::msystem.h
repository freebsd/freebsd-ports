--- src/core/msystem.h.orig	Fri Oct 27 18:15:20 2000
+++ src/core/msystem.h	Fri Feb 22 13:53:33 2002
@@ -114,7 +114,11 @@
 #	define GID_RESET	-2		/* reset EGID to RGID */
 #endif
 #ifndef DEF_PATH
-#	define DEF_PATH	"PATH=/bin:/usr/bin:/usr/ucb"  /* default search path */
+#ifdef __FreeBSD_cc_version
+#	define DEF_PATH	"PATH=/sbin:/usr/sbin:/bin:/usr/bin"  /* default search path */
+#else
+#	define DEF_PATH "PATH=/bin:/usr/bin:/usr/ucb"	/* default search path */
+#endif
 #endif
 #ifndef DEF_SHELL
 #	define DEF_SHELL	"SHELL=/bin/sh"	/* default shell */
