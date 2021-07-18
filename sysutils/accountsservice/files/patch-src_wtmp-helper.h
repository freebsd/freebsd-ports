--- src/wtmp-helper.h.orig	2016-09-06 19:48:50 UTC
+++ src/wtmp-helper.h
@@ -23,7 +23,6 @@
 
 #include <glib.h>
 #include <pwd.h>
-#include <shadow.h>
 
 const gchar *           wtmp_helper_get_path_for_monitor                (void);
 void                    wtmp_helper_update_login_frequencies            (GHashTable *users);
