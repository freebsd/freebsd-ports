--- vide.c.orig	Sun Feb 18 15:43:10 2001
+++ vide.c	Sat Feb 24 15:14:47 2001
@@ -16,7 +16,14 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
 
-
+#include<sys/param.h>
+#if defined(__FreeBSD_version)
+    #define RXVT_VIM "xterm -e vim"
+    #define RXVT "xterm"
+#else
+    #define RXVT_VIM "rxvt -e vim"
+    #define RXVT "rxvt"
+#endif
 
 #include <string.h>
 #include <unistd.h>
@@ -280,6 +287,8 @@
 
 	getcwd(current_dir, sizeof(current_dir));
 
+  /* i18n support */
+  gtk_set_locale();
 
   /* Set up handler for sigchild so that we don't get zombies */
   new_action.sa_handler = received_sigchild;
@@ -329,7 +338,7 @@
       cfg.start_with_cwd = FALSE; 
 			strncpy(cfg.vi_clone, "vim", sizeof(cfg.vi_clone));
 			strncpy(cfg.vi_command, "vim", sizeof(cfg.vi_command));
-      strncpy (cfg.viewer_command, "rxvt -e vim",
+      strncpy (cfg.viewer_command, RXVT_VIM,
 	       sizeof (cfg.viewer_command));
       cfg.window_width = 640;
       cfg.window_height = 480;
@@ -337,7 +346,7 @@
       cfg.window_ypos = 0;
       cfg.dir_history_max_length = 15; 
       cfg.command_history_max_length = 10;
-      strncpy (cfg.xterm_command, "rxvt", sizeof (cfg.xterm_command));
+      strncpy (cfg.xterm_command, RXVT, sizeof (cfg.xterm_command));
       chdir (getenv ("HOME"));
       getcwd (app.left_view.dir, PATH_MAX);
       strncpy (app.right_view.dir, app.left_view.dir, PATH_MAX);
