--- color.h.orig	2019-02-22 18:41:46 UTC
+++ color.h
@@ -57,7 +57,7 @@ struct ucolor {
     int blink;
 };
 
-struct ucolor ucolors[N_INIT_PAIRS];
+extern struct ucolor ucolors[N_INIT_PAIRS];
 
 struct dictionary * get_d_colors_param();
 void start_default_ucolors();
