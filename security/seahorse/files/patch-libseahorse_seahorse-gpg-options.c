--- libseahorse/seahorse-gpg-options.c.orig	Wed Jan 26 12:11:42 2005
+++ libseahorse/seahorse-gpg-options.c	Wed Jan 26 12:11:57 2005
@@ -31,7 +31,7 @@
 #include "seahorse-gpg-options.h"
 
 #define  GPG_CONF_HEADER    "# FILE CREATED BY SEAHORSE\n\n"
-#define  GPG_VERSION_PREFIX   "1.2."
+#define  GPG_VERSION_PREFIX   "1.4."
 
 static gchar gpg_homedir[MAXPATHLEN];
 static gboolean gpg_options_inited = FALSE;
