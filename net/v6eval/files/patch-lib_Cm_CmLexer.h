--- lib/Cm/CmLexer.h.orig	2003-12-04 13:59:47.000000000 +0900
+++ lib/Cm/CmLexer.h	2013-06-16 10:32:18.000000000 +0900
@@ -49,10 +49,8 @@
 #include "CmToken.h"
 #include <stdio.h>
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 4)
-
-const int32_t	YYERRCODE=256;
-
+#ifndef YYERRCODE
+#define	YYERRCODE	256
 #endif
 
 class PObject;
