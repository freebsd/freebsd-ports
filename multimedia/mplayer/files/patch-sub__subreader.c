--- sub/subreader.c.orig	2011-07-22 23:08:52.000000000 -0400
+++ sub/subreader.c	2011-07-22 23:26:15.000000000 -0400
@@ -2509,8 +2509,10 @@
   strip_markup = 1;
 #endif
   if (!strip_markup) {
+#ifdef CONFIG_ASS
     subassconvert_subrip(txt, buf, MAX_SUBLINE + 1);
     sub->text[sub->lines] = buf;
+#endif 
   } else {
     for (i = 0; i < len && pos < MAX_SUBLINE; i++) {
       char c = txt[i];
