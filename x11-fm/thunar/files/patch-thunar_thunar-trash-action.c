--- thunar/thunar-trash-action.c.orig	2015-05-15 08:57:43 UTC
+++ thunar/thunar-trash-action.c
@@ -88,6 +88,9 @@ thunar_trash_action_init (ThunarTrashAct
 
       /* initially update the stock icon */
       thunar_trash_action_changed (trash_action, trash_action->trash_bin);
+
+      /* schedule a reload in idle (fix for bug #9513) */
+      thunar_file_reload_idle (trash_action->trash_bin);
     }
 }
 
