$NetBSD: patch-bj,v 1.3 2006/06/01 22:44:09 tron Exp $

--- lib/font/FreeType/ftfuncs.h.orig	2005-07-07 15:59:47.000000000 +0100
+++ lib/font/FreeType/ftfuncs.h	2006-06-01 23:21:39.000000000 +0100
@@ -47,6 +47,7 @@
     char *filename;
     FT_Face face;
     int bitmap;
+    FT_UInt num_hmetrics;
     struct _FTInstance *instances;
     struct _FTInstance *active_instance;
     struct _FTFace *next;       /* link to next face in bucket */
