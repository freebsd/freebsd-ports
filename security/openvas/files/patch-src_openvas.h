--- src/openvas.h	2023-08-31 14:23:03.000000000 -0500
+++ src/openvas.h	2023-09-20 23:57:03.842529000 -0500
@@ -12,6 +12,9 @@
 #define OPENVAS_H
 
 int
+#if defined(__FreeBSD__)
+openvas (int, char **);
+#else
 openvas (int, char **, char **);
-
+#endif
 #endif /* not OPENVAS_H */
