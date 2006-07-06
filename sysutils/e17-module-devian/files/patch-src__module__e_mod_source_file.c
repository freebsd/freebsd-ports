--- src/module/e_mod_source_file.c.orig	Thu Jul  6 23:29:46 2006
+++ src/module/e_mod_source_file.c	Thu Jul  6 23:29:54 2006
@@ -24,7 +24,7 @@
       snprintf(buf, sizeof(buf),
 	       _("<hilight>dEvian's Log feature isn't stable yet !</hilight><br><br>"
 		 "It's disabled for now"));
-      e_module_dialog_show(_(MODULE_NAME " Module error"), buf);
+      e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module error"), buf);
       return 0;
    }
 #endif
