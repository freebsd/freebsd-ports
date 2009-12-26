--- libgupnp/gupnp-service.c.orig	2009-12-02 15:27:43.000000000 +0100
+++ libgupnp/gupnp-service.c	2009-12-26 14:30:23.000000000 +0100
@@ -30,7 +30,11 @@
 #include <gobject/gvaluecollector.h>
 #include <gmodule.h>
 #include <libsoup/soup-date.h>
+#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#include <uuid.h>
+#else
 #include <uuid/uuid.h>
+#endif
 #include <string.h>
 #include "gupnp-service.h"
 #include "gupnp-root-device.h"
@@ -867,9 +871,19 @@
 {
         uuid_t id;
         char out[39];
-
+#if defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+	char *myout;
+#endif
+
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
 }
