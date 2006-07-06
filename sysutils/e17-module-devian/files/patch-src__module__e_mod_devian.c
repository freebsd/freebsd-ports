--- src/module/e_mod_devian.c.orig	Thu Jul  6 23:34:34 2006
+++ src/module/e_mod_devian.c	Thu Jul  6 23:34:41 2006
@@ -443,7 +443,7 @@
 
         snprintf(buf, sizeof(buf),
                  _("<hilight>Error !</hilight><br>" "Did not find <hilight>theme</hilight> %s group %s"), path, part);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return NULL;
      }
    DMAIN(("Edje loaded %s group %s", path, part));
