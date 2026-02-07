--- service/realm-provider.c.orig	2022-09-29 11:05:56 UTC
+++ service/realm-provider.c
@@ -28,9 +28,15 @@
 #include <glib/gi18n.h>
 #include <gio/gio.h>
 
+#include <unistd.h>
 #include <errno.h>
 
 #define TIMEOUT_SECONDS 15
+
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
 
 G_DEFINE_TYPE (RealmProvider, realm_provider, G_TYPE_DBUS_OBJECT_SKELETON);
 
