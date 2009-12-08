--- src/subreader.c.orig	2006-06-01 06:04:50.000000000 +0200
+++ src/subreader.c	2009-12-08 14:59:15.649467455 +0100
@@ -1079,8 +1079,8 @@
   int char_set_num;
   fribidi_boolean log2vis;
   if(flip_hebrew) { // Please fix the indentation someday
-  fribidi_set_mirroring (FRIBIDI_TRUE);
-  fribidi_set_reorder_nsm (FRIBIDI_FALSE);
+  fribidi_set_mirroring (1);
+  fribidi_set_reorder_nsm (0);
 
   if( sub_utf8 == 0 ) {
     char_set_num = fribidi_parse_charset (fribidi_charset?fribidi_charset:"ISO8859-8");
