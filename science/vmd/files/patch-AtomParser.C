--- src/AtomParser.C-xxx	Fri Dec  5 13:21:53 2003
+++ src/AtomParser.C	Thu Aug 12 00:24:00 2004
@@ -109,7 +109,7 @@
 #define	YYCONST
 #endif
 
-#if !defined(_MSC_VER) && !defined(ARCH_MACOSX)
+#if !defined(_MSC_VER) && !defined(ARCH_MACOSX) && !defined(ARCH_FREEBSD) && !defined(ARCH_FREEBSDAMD64)
 #include <values.h>
 #endif
 
