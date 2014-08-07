--- defines.h.orig	Mon Feb 24 12:45:37 1992
+++ defines.h	Sat Feb  2 10:57:31 1996
@@ -40,14 +40,21 @@
  * If TERMIO is 0 your system must have /usr/include/sgtty.h.
  * This is normally the case for BSD.
  */
-/*#define	TERMIO		1*/
+#include <sys/param.h>
+#ifdef BSD4_4
+#define	TERMIO		1
+#endif
 
 /*
  * SIGSETMASK is 1 if your system has the sigsetmask() call.
  * This is normally the case only for BSD 4.2,
  * not for BSD 4.1 or System 5.
  */
+#ifdef BSD4_4
+#define	SIGSETMASK	1
+#else
 #define	SIGSETMASK	0
+#endif
 
 /*
  * REGCMP is 1 if your system has the regcmp() function.
@@ -73,7 +80,7 @@
  * EDIT_PGM is the name of the (default) editor to be invoked.
  */
 #define	EDITOR		1
-#define	EDIT_PGM	"/usr/local/bin/vi"
+#define	EDIT_PGM	"/usr/bin/vi"
 
 /*
  * TAGS is 1 if you wish to support tag files.
