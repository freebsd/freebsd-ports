--- src/command.c.orig	Mon Oct 24 09:38:24 2005
+++ src/command.c	Sun May 27 14:08:14 2007
@@ -732,7 +732,7 @@
 }
 
 
-static int command_count;
+int command_count;
 
 commandtyp command_list[] = {
 	{"quit",c_quit,do_quit},
