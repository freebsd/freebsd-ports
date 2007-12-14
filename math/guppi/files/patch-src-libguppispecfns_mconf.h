--- src/libguppispecfns/mconf.h.orig	2007-12-13 15:30:12.000000000 +0100
+++ src/libguppispecfns/mconf.h	2007-12-13 15:30:24.000000000 +0100
@@ -139,9 +139,6 @@
 
 int mtherr (const char *fctnam, int code);
 
-/* Variable for error reporting.  See mtherr.c.  */
-extern int merror;
-
 END_GUPPI_DECLS
 
 #endif /* __MCONF_H__ */
