--- src/geode.h.orig	2020-08-24 18:11:55 UTC
+++ src/geode.h
@@ -343,7 +343,7 @@ typedef struct _geodeRec {
 
 /* option flags are self-explanatory */
 #ifdef HAVE_LX
-enum {
+enum LX_GeodeOpts {
     LX_OPTION_SW_CURSOR,
     LX_OPTION_HW_CURSOR,
     LX_OPTION_NOCOMPRESSION,
@@ -357,11 +357,11 @@ enum {
     LX_OPTION_FBSIZE,
     LX_OPTION_PANEL_MODE,
     LX_OPTION_DONT_PROGRAM
-} LX_GeodeOpts;
+};
 #endif
 
 #ifdef HAVE_GX
-enum {
+enum GX_GeodeOpts {
     GX_OPTION_SW_CURSOR,
     GX_OPTION_HW_CURSOR,
     GX_OPTION_NOCOMPRESSION,
@@ -378,7 +378,7 @@ enum {
     GX_OPTION_FBSIZE,
     GX_OPTION_PANEL_GEOMETRY,
     GX_OPTION_DONT_PROGRAM
-} GX_GeodeOpts;
+};
 #endif
 
 /* geode_dcon.c */
