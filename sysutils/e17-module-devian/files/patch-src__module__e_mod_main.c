--- src/module/e_mod_main.c.orig	Thu Jul  6 23:28:34 2006
+++ src/module/e_mod_main.c	Thu Jul  6 23:28:50 2006
@@ -48,7 +48,7 @@
    char buf[4096];
 
    snprintf(buf, sizeof(buf), _("Enlightenment %s Module - version " MODULE_VERSION), MODULE_NAME);
-   e_module_dialog_show(buf, _(
+   e_module_dialog_show(m, buf, _(
 #ifndef HAVE_ALL
                                "This module is part of dEvian module<br><br>"
 #ifdef HAVE_PICTURE
