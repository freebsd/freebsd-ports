--- src/module/e_mod_source_rss.c.orig	Thu Jul  6 23:28:58 2006
+++ src/module/e_mod_source_rss.c	Thu Jul  6 23:29:14 2006
@@ -108,7 +108,7 @@
         snprintf(buf, sizeof(buf),
                  _("<hilight>Unable to open link</hilight><br><br>"
                    "Feed '%s' has no link associated !"), source->devian->conf->rss_doc->name);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
@@ -128,7 +128,7 @@
                  _("<hilight>Viewer %s not found !</hilight><br><br>"
                    "You can change the viewer for http in DEVIANN configuration panel (Advanced view)"),
                  DEVIANM->conf->viewer_http);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
