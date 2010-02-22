--- src/AtomParser.C-xxx	Fri Dec  5 13:21:53 2003
+++ src/AtomParser.C	Thu Aug 12 00:24:00 2004
@@ -114,7 +114,7 @@
 #define	YYCONST
 #endif
 
-#if !defined(_MSC_VER) && !defined(__APPLE__)
+#if !defined(_MSC_VER) && !defined(__APPLE__) && !defined(ARCH_FREEBSD) && !defined(ARCH_FREEBSDAMD64)
 #include <values.h>
 #endif
 
