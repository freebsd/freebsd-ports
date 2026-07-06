--- src/manage_sql.c.orig	2026-06-22 01:59:08.000000000 -0700
+++ src/manage_sql.c	2026-06-22 23:13:07.804612000 -0700
@@ -85,7 +85,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
@@ -97,12 +96,12 @@
 #include <gpgme.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <gvm/base/gvm_sentry.h>
 #include <gvm/base/hosts.h>
 #include <gvm/base/pwpolicy.h>
 #include <gvm/base/logging.h>
-#include <bsd/unistd.h>
 
 #if ENABLE_JWT_AUTH
 #include <gvm/auth/gvm_auth.h>
@@ -3361,8 +3360,6 @@
 
   cleanup_iterator (&nvts);
   cleanup_iterator (&prefs);
-
-  malloc_trim (0);
 }
 
 /**
