--- src/colors.c.orig	Fri Oct 22 19:03:40 2004
+++ src/colors.c	Fri Oct 22 19:04:16 2004
@@ -53,12 +53,6 @@
 
 int read_colors()
 {
-
-#ifdef DEBUG
-	if (read_config_file(expand_filename("~/.cdfrc")) != 0)
-		(void)fprintf(stderr, "Using default color theme\n");
-#endif /* DEBUG */
-	
 	bracket_color = (char *)malloc(64);
 	gauge_color = (char *)malloc(64);
 	header_color = (char *)malloc(64);
