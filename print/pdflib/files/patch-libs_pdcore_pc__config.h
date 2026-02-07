--- libs/pdcore/pc_config.h.orig	2017-10-04 07:15:35 UTC
+++ libs/pdcore/pc_config.h
@@ -180,7 +180,7 @@
 /* try to identify Mac OS 9 compilers */
 
 #if (defined macintosh || defined __POWERPC__ || defined __CFM68K__) && \
-	!defined MAC && !defined MACOSX && !defined __BEOS__
+	!defined MAC && !defined MACOSX && !defined __BEOS__ && !defined __FreeBSD__
 #define MAC
 #endif
 
