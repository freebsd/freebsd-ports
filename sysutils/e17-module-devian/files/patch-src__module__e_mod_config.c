--- src/module/e_mod_config.c.orig	Thu Jul  6 23:32:07 2006
+++ src/module/e_mod_config.c	Thu Jul  6 23:32:25 2006
@@ -100,7 +100,7 @@
                         "has been upgraded<br>"
                         "Your settings were removed<br>"
                         "Sorry for the inconvenience<br><br>" "(%d -> %d)"), cfg_main->conf_version, CONFIG_VERSION);
-             e_module_dialog_show(_(MODULE_NAME " Module version " MODULE_VERSION), buf);
+             e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module version " MODULE_VERSION), buf);
 
              cfg_main = NULL;
           }
@@ -116,7 +116,7 @@
                              "has been downgraded<br>"
                              "Your settings were removed<br>"
                              "Sorry for the inconvenience<br><br>" "(%d ->%d)"), cfg_main->conf_version, CONFIG_VERSION);
-                  e_module_dialog_show(_(MODULE_NAME " Module version " MODULE_VERSION), buf);
+                  e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module version " MODULE_VERSION), buf);
                   cfg_main = NULL;
                }
           }
