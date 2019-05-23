--- cmds_command.c.orig	2019-02-22 18:41:46 UTC
+++ cmds_command.c
@@ -853,7 +853,7 @@ void do_commandmode(struct block * sb) {
             exec_cmd(line);
 
         } else if ( inputline[0] == L'w' ) {
-            if (savefile() == 0 && ! wcscmp(inputline, L"wq")) shall_quit = 1;
+            if (savefile() == 0 && ! wcsncmp(inputline, L"wq", 2)) shall_quit = 1;
 
         } else if ( ! wcsncmp(inputline, L"file ", 5) ) {
 
