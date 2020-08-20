--- src/parse_config.h.orig	2020-08-21 00:28:18.377783000 +0700
+++ src/parse_config.h	2020-08-21 00:28:12.579209000 +0700
@@ -85,7 +85,7 @@
 colours;
 #endif /* NO_COLOR_CURSES */
 
-int use_manual;
+extern int use_manual;
 
 int parse_config (void);
 int parse_line (char *line);
