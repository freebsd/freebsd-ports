--- cmds_command.c.orig	2019-02-22 18:41:46 UTC
+++ cmds_command.c
@@ -81,7 +81,7 @@ extern char * rev;
 extern struct dictionary * user_conf_d;
 
 wchar_t inputline[BUFFERSIZE];
-wchar_t interp_line[BUFFERSIZE];
+extern wchar_t interp_line[BUFFERSIZE];
 int inputline_pos; /**< Position in window. Some chars has 2 chars width */
 // see https://en.wikipedia.org/wiki/Halfwidth_and_fullwidth_forms
 int real_inputline_pos; /**<  Real position in inputline */
@@ -853,7 +853,7 @@ void do_commandmode(struct block * sb) {
             exec_cmd(line);
 
         } else if ( inputline[0] == L'w' ) {
-            if (savefile() == 0 && ! wcscmp(inputline, L"wq")) shall_quit = 1;
+            if (savefile() == 0 && ! wcsncmp(inputline, L"wq", 2)) shall_quit = 1;
 
         } else if ( ! wcsncmp(inputline, L"file ", 5) ) {
 
