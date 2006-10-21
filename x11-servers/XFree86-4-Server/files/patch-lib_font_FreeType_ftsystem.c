$NetBSD: patch-bk,v 1.3 2006/06/01 22:44:09 tron Exp $

--- lib/font/FreeType/ftsystem.c.orig	2005-07-09 07:36:10.000000000 +0100
+++ lib/font/FreeType/ftsystem.c	2006-06-01 23:21:53.000000000 +0100
@@ -32,7 +32,9 @@
 #endif
 #include <ft2build.h>
 #include FT_CONFIG_CONFIG_H
-#include FT_INTERNAL_DEBUG_H
+#define FT_TRACE( level, varformat )  do ; while ( 0 )      /* nothing */
+#define FT_TRACE1( varformat )  FT_TRACE( 1, varformat )
+#define FT_ERROR( varformat )  do ; while ( 0 )      /* nothing */
 #include FT_SYSTEM_H
 #include FT_ERRORS_H
 #include FT_TYPES_H
