--- config/hal.c.orig	2008-11-14 16:27:05.000000000 -0500
+++ config/hal.c	2009-02-08 01:17:28.000000000 -0500
@@ -467,11 +467,10 @@
     info->system_bus = NULL;
 }
 
-static void
-connect_hook(DBusConnection *connection, void *data)
+static BOOL
+connect_and_register(DBusConnection *connection, struct config_hal_info *info)
 {
     DBusError error;
-    struct config_hal_info *info = data;
     char **devices;
     int num_devices, i;
 
@@ -479,8 +478,10 @@
 
     dbus_error_init(&error);
 
-    if (!info->hal_ctx)
-        info->hal_ctx = libhal_ctx_new();
+    if (info->hal_ctx)
+        return TRUE; /* already registered, pretend we did something */
+
+    info->hal_ctx = libhal_ctx_new();
     if (!info->hal_ctx) {
         LogMessage(X_ERROR, "config/hal: couldn't create HAL context\n");
         goto out_err;
@@ -512,7 +513,7 @@
 
     dbus_error_free(&error);
 
-    return;
+    return TRUE;
 
 out_ctx2:
     if (!libhal_ctx_shutdown(info->hal_ctx, &error))
@@ -526,6 +527,104 @@
     info->hal_ctx = NULL;
     info->system_bus = NULL;
 
+    return FALSE;
+}
+
+
+/**
+ * Handle NewOwnerChanged signals to deal with HAL startup at X server runtime.
+ *
+ * NewOwnerChanged is send once when HAL shuts down, and once again when it
+ * comes back up. Message has three arguments, first is the name
+ * (org.freedesktop.Hal), the second one is the old owner, third one is new
+ * owner.
+ */
+static DBusHandlerResult
+ownerchanged_handler(DBusConnection *connection, DBusMessage *message, void *data)
+{
+    int ret = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
+
+    if (dbus_message_is_signal(message,
+                               "org.freedesktop.DBus",
+                               "NameOwnerChanged")) {
+        DBusError error;
+        char *name, *old_owner, *new_owner;
+
+        dbus_error_init(&error);
+        dbus_message_get_args(message, &error,
+                              DBUS_TYPE_STRING, &name,
+                              DBUS_TYPE_STRING, &old_owner,
+                              DBUS_TYPE_STRING, &new_owner,
+                              DBUS_TYPE_INVALID);
+
+        if (dbus_error_is_set(&error)) {
+            ErrorF("[config/hal] failed to get NameOwnerChanged args: %s (%s)\n",
+                   error.name, error.message);
+        } else if (name && strcmp(name, "org.freedesktop.Hal") == 0) {
+
+            if (!old_owner || !strlen(old_owner)) {
+                DebugF("[config/hal] HAL startup detected.\n");
+                if (connect_and_register(connection, (struct config_hal_info*)data))
+                    dbus_connection_unregister_object_path(connection,
+                                                     "/org/freedesktop/DBus");
+                else
+                    ErrorF("[config/hal] Failed to connect to HAL bus.\n");
+            }
+
+            ret = DBUS_HANDLER_RESULT_HANDLED;
+        }
+        dbus_error_free(&error);
+    }
+
+    return ret;
+}
+
+/**
+ * Register a handler for the NameOwnerChanged signal.
+ */
+static BOOL
+listen_for_startup(DBusConnection *connection, void *data)
+{
+    DBusObjectPathVTable vtable = { .message_function = ownerchanged_handler, };
+    DBusError error;
+    const char MATCH_RULE[] = "sender='org.freedesktop.DBus',"
+                              "interface='org.freedesktop.DBus',"
+                              "type='signal',"
+                              "path='/org/freedesktop/DBus',"
+                              "member='NameOwnerChanged'";
+    int rc = FALSE;
+
+    dbus_error_init(&error);
+    dbus_bus_add_match(connection, MATCH_RULE, &error);
+    if (!dbus_error_is_set(&error)) {
+        if (dbus_connection_register_object_path(connection,
+                                                  "/org/freedesktop/DBus",
+                                                  &vtable,
+                                                  data))
+            rc = TRUE;
+        else
+            ErrorF("[config/hal] cannot register object path.\n");
+    } else {
+        ErrorF("[config/hal] couldn't add match rule: %s (%s)\n", error.name,
+                error.message);
+        ErrorF("[config/hal] cannot detect a HAL startup.\n");
+    }
+
+    dbus_error_free(&error);
+
+    return rc;
+}
+
+static void
+connect_hook(DBusConnection *connection, void *data)
+{
+    struct config_hal_info *info = data;
+
+    if (listen_for_startup(connection, data) &&
+        connect_and_register(connection, info))
+        dbus_connection_unregister_object_path(connection,
+                                               "/org/freedesktop/DBus");
+
     return;
 }
 
