--- config_files.c.orig	Tue Jan 30 12:58:08 2001
+++ config_files.c	Sat Feb 24 15:14:46 2001
@@ -16,6 +16,12 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
 
+#include<sys/param.h>
+#if defined(__FreeBSD_version)
+    #define CP_HELP "cp /usr/X11R6/share/vide/vide%s.txt %s"
+#else
+    #define CP_HELP "cp /usr/local/share/vide/vide%s.txt %s"
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
@@ -60,8 +66,7 @@
 {
 	gchar command[PATH_MAX];
 
-	g_snprintf(command, sizeof(command), "cp /usr/local/share/vide/vide%s.txt %s",
-			VERSION, help_file);
+	g_snprintf(command, sizeof(command), CP_HELP, VERSION, help_file);
 	file_exec(command);
 
 }
