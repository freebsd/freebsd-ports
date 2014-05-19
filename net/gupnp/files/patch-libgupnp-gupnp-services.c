--- libgupnp/gupnp-service.c.orig	2013-02-20 20:35:57.000000000 +0800
+++ libgupnp/gupnp-service.c	2013-03-15 16:04:28.277418472 +0800
@@ -30,6 +30,7 @@
 #include <gobject/gvaluecollector.h>
 #include <gmodule.h>
 #include <libsoup/soup-date.h>
+#include <libsoup/soup-date.h>
 #include <string.h>
 #include "gupnp-service.h"
 #include "gupnp-root-device.h"
@@ -43,6 +44,8 @@
 
 #ifdef G_OS_WIN32
 #include <rpc.h>
+#elsif defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#include <uuid.h>
 #else
 #include <uuid/uuid.h>
 #endif
@@ -1100,9 +1103,19 @@
 #else
         uuid_t id;
         char out[39];
+#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+	char *myout;
+#endif
 
+#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+	uuid_create(&id, 0);
+	uuid_to_string(&id, &myout, 0);
+	strncpy(out, myout, sizeof(out));
+	free(myout);
+#else
         uuid_generate (id);
         uuid_unparse (id, out);
+#endif
 
         return g_strdup_printf ("uuid:%s", out);
 #endif
