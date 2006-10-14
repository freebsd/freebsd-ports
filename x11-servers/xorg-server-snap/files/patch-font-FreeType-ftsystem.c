$NetBSD: patch-bk,v 1.3 2006/06/01 22:44:09 tron Exp $

--- lib/font/FreeType/ftsystem.c.orig	2005-07-09 07:36:10.000000000 +0100
+++ lib/font/FreeType/ftsystem.c	2006-06-01 23:21:53.000000000 +0100
@@ -35,7 +35,6 @@
 #endif
 #include <ft2build.h>
 #include FT_CONFIG_CONFIG_H
-#include FT_INTERNAL_DEBUG_H
 #include FT_SYSTEM_H
 #include FT_ERRORS_H
 #include FT_TYPES_H
