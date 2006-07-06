--- src/module/e_mod_config_dialog_devian.c.orig	Thu Jul  6 23:32:48 2006
+++ src/module/e_mod_config_dialog_devian.c	Thu Jul  6 23:33:02 2006
@@ -789,7 +789,7 @@
         snprintf(buf, sizeof(buf),
                  _("<hilight>Rss '%s' is in use !</hilight><br><br>"
                    "You can't delete it while its in use.<br><br>" "Owner is %s"), doc->name, doc->user->source->devian->id);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
      }
 }
 #endif
