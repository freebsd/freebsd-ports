--- applications/papif/papif.c.orig	Sat Aug 21 18:29:42 2004
+++ applications/papif/papif.c	Sat Aug 21 18:31:17 2004
@@ -244,6 +244,17 @@
 #define	lpd_REPRINT	1	/* forces a reprint */
 #define lpd_ERRORS	2	/* printed with errors */
 
+#ifndef USEVPRINTF
+/* Bletch - gotta do it because pyramids don't work the other way */
+/* (using _doprnt and &args) and don't have vprintf */
+/* of course, there will be something that is just one arg larger :-) */
+/* VARARGS1 */
+dolog(fmt, a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,af);
+char *fmt;
+#else
+dolog(register char *fmt, ...);
+#endif
+
 #ifdef USESYSLOG
 #ifdef __STDC__
 log_i(fmt, a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,af)
