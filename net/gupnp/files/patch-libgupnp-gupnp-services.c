--- libgupnp/gupnp-service.c.orig	2014-05-04 20:49:23.000000000 +0800
+++ libgupnp/gupnp-service.c	2014-05-28 13:01:03.041207000 +0800
@@ -45,6 +45,8 @@
 
 #ifdef G_OS_WIN32
 #include <rpc.h>
+#elsif defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#include <uuid.h>
 #else
 #include <uuid/uuid.h>
 #endif
@@ -1110,9 +1112,19 @@
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
