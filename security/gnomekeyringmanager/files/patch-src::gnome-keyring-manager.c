--- src/gnome-keyring-manager.c.orig	Sun Jun 13 22:16:43 2004
+++ src/gnome-keyring-manager.c	Thu Dec 16 22:58:42 2004
@@ -312,7 +312,8 @@
     { "manager", 'm', POPT_ARG_NONE, NULL, OPTION_MANAGER, 
       N_("Open the keyring manager"), NULL },
     { "keyring", 'k', POPT_ARG_STRING, NULL, OPTION_KEYRING, 
-      N_("Open the keyring editor for KEYRING"), N_("KEYRING") }
+      N_("Open the keyring editor for KEYRING"), N_("KEYRING") },
+    { NULL, '\0', 0, NULL, 0, NULL, NULL }
 };
 
 int
