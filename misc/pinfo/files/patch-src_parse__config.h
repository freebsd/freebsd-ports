--- src/parse_config.h.orig	2021-07-01 13:25:26 UTC
+++ src/parse_config.h
@@ -85,7 +85,7 @@ typedef struct colours
 colours;
 #endif /* HAVE_CURSES_COLOR */
 
-int use_manual;
+extern int use_manual;
 
 int parse_config (void);
 int parse_line (char *line);
