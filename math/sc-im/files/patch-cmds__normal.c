--- cmds_normal.c.orig	2019-02-22 18:41:46 UTC
+++ cmds_normal.c
@@ -70,7 +70,7 @@ extern int cmd_multiplier;
 extern void start_visualmode(int tlrow, int tlcol, int brrow, int brcol);
 extern void ins_in_line(wint_t d);
 
-wchar_t interp_line[BUFFERSIZE];
+extern wchar_t interp_line[BUFFERSIZE];
 
 #ifdef HISTORY_FILE
 extern struct history * commandline_history;
