--- tclUnixPort.h.orig	Wed Jan 17 13:14:18 2007
+++ tclUnixPort.h	Wed Jan 17 13:08:39 2007
@@ -628,6 +628,9 @@
 EXTERN struct tm *     	TclpLocaltime(CONST time_t *);
 EXTERN struct tm *     	TclpGmtime(CONST time_t *);
 EXTERN char *          	TclpInetNtoa(struct in_addr);
+#ifdef inet_ntoa
+#	undef inet_ntoa
+#endif
 /* #define localtime(x)	TclpLocaltime(x)
  * #define gmtime(x)	TclpGmtime(x)    */
 #   undef inet_ntoa
