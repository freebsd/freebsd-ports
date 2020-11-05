11.x does not have getrandom(2) (or getentropy(3))

--- lib/ephy-sync-utils.c.orig	2020-10-04 22:15:55 UTC
+++ lib/ephy-sync-utils.c
@@ -24,6 +24,7 @@
 #include "ephy-settings.h"
 
 #include <errno.h>
+#include <fcntl.h>
 #include <glib/gi18n.h>
 #include <inttypes.h>
 #include <json-glib/json-glib.h>
@@ -189,7 +190,13 @@ ephy_sync_utils_generate_random_bytes (v
   }
 #else
   do {
-    ret = getrandom (out, num_bytes, 0);
+    int fd = open("/dev/urandom", O_RDONLY|O_CLOEXEC);
+    if (fd != -1) {
+      ret = read(fd, out, num_bytes);
+      (void)close(fd);
+    }
+    else
+      g_error ("Failed to open /dev/urandom to generate randomness: %s", g_strerror (errno));
   } while (ret < (gssize)num_bytes && errno == EINTR);
 
   if (ret != (gssize)num_bytes)
