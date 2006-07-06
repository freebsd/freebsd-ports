--- src/module/e_mod_config_dialog_theme.c.orig	Thu Jul  6 23:33:17 2006
+++ src/module/e_mod_config_dialog_theme.c	Thu Jul  6 23:33:33 2006
@@ -636,7 +636,7 @@
    if (!ecore_file_is_dir(themes_path))
      {
         snprintf(buf, sizeof(buf), _("<hilight>Directory %s doesnt exists.</hilight><br><br>" "No themes found !!!"), themes_path);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return NULL;
      }
 
@@ -644,7 +644,7 @@
    if (ecore_list_is_empty(list) || !list)
      {
         snprintf(buf, sizeof(buf), _("<hilight>Directory %s is empty !</hilight><br><br>" "No themes found !!!"), themes_path);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return NULL;
      }
 
@@ -701,5 +701,5 @@
    snprintf(buf, sizeof(buf),
             _("<hilight>Invalid theme</hilight><br><br>"
               "You have selected an invalid theme.<br>" "A valid theme has a dEvian icon in front of it."));
-   e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+   e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
 }
