--- src/sbus/sbus_errors.c.orig	2023-05-05 08:11:07 UTC
+++ src/sbus/sbus_errors.c
@@ -53,7 +53,7 @@ static const struct {
     { DBUS_ERROR_LIMITS_EXCEEDED,   ERANGE},
     { DBUS_ERROR_ACCESS_DENIED,     EPERM},
     { DBUS_ERROR_AUTH_FAILED,       EACCES},
-    { DBUS_ERROR_NO_NETWORK,        ENONET},
+    { DBUS_ERROR_NO_NETWORK,        EHOSTDOWN},
     { DBUS_ERROR_DISCONNECTED,      ERR_OFFLINE},
     { DBUS_ERROR_INVALID_ARGS,      EINVAL},
 
