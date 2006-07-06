--- src/module/e_mod_container.c.orig	Thu Jul  6 23:33:42 2006
+++ src/module/e_mod_container.c	Thu Jul  6 23:33:53 2006
@@ -248,7 +248,7 @@
              char buf[4096];
 
              snprintf(buf, sizeof(buf), _("<hilight>Invalid theme !</hilight><br><br>" "Failed to switch to %s theme"), *theme);
-             e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+             e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
              evas_stringshare_del(*theme);
              *theme = evas_stringshare_add(DEVIAN_THEME_DEFAULT);
              DEVIANF(container_change) (devian, devian->conf->container_type);
@@ -272,7 +272,7 @@
 
                        snprintf(buf, sizeof(buf),
                                 _("<hilight>Invalid theme !</hilight><br><br>" "Failed to switch to %s theme"), *theme);
-                       e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+                       e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
                        evas_stringshare_del(*theme);
                        *theme = evas_stringshare_add(DEVIAN_THEME_DEFAULT);
                        DEVIANF(container_change) (devian, devian->conf->container_type);
