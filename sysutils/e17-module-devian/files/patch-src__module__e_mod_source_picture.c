--- src/module/e_mod_source_picture.c.orig	Thu Jul  6 23:29:20 2006
+++ src/module/e_mod_source_picture.c	Thu Jul  6 23:29:41 2006
@@ -174,7 +174,7 @@
                  _("<hilight>File %s doesnt exists.</hilight><br><br>"
                    "This file is in dEvian's picture list, but it seems you removed it from the disk<br>"
                    "It cant be set as background, sorry."), file);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
@@ -201,7 +201,7 @@
                         "%s is not an edje file !<br>"
                         "dEvian need e17setroot util from e_utils package to set you're picture as background"
                         "Please install it and try again"), file);
-             e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+             e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
              return 0;
           }
      }
@@ -261,7 +261,7 @@
                  _("<hilight>File %s doesnt exists !</hilight><br><br>"
                    "This file is in dEvian's picture list, but it seems you removed it from the disk.<br>"
                    "It cant be set opened in a viewer, sorry."), file);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
@@ -281,7 +281,7 @@
                  _("<hilight>Viewer %s not found !</hilight><br><br>"
                    "You can change the viewer for images in dEvian configuration panel (Advanced view)"),
                  DEVIANM->conf->viewer_image);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
