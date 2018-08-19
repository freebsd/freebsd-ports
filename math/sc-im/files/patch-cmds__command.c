--- cmds_command.c.orig	2018-08-03 06:04:39 UTC
+++ cmds_command.c
@@ -826,7 +826,7 @@ void do_commandmode(struct block * sb) {
             exec_cmd(line);
 
         } else if ( inputline[0] == L'w' ) {
-            if (savefile() == 0 && ! wcscmp(inputline, L"wq")) shall_quit = 1;
+            if (savefile() == 0 && ! wcsncmp(inputline, L"wq", 2)) shall_quit = 1;
 
         } else if ( ! wcsncmp(inputline, L"file ", 5) ) {
 
