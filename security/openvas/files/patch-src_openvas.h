--- src/openvas.h	2022-07-31 21:28:34.160685000 -0500
+++ src/openvas.h	2022-07-31 21:29:05.831561000 -0500
@@ -26,6 +26,10 @@
 #define _OPENVAS_H
 
 int
+#if defined(__FreeBSD__)
+openvas (int, char **);
+#else
 openvas (int, char **, char **);
+#endif
 
 #endif /* not _OPENVAS_H */
