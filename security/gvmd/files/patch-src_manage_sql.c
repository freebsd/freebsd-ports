--- src/manage_sql.c	2025-09-05 02:59:51.000000000 -0700
+++ src/manage_sql.c	2025-10-07 22:42:53.666243000 -0700
@@ -72,7 +72,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
@@ -84,12 +83,12 @@
 #include <gpgme.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <gvm/base/gvm_sentry.h>
 #include <gvm/base/hosts.h>
 #include <gvm/base/pwpolicy.h>
 #include <gvm/base/logging.h>
-#include <bsd/unistd.h>
 #include <gvm/util/fileutils.h>
 #include <gvm/util/serverutils.h>
 #include <gvm/util/uuidutils.h>
@@ -6382,8 +6381,6 @@
 
   cleanup_iterator (&nvts);
   cleanup_iterator (&prefs);
-
-  malloc_trim (0);
 }
 
 /**
