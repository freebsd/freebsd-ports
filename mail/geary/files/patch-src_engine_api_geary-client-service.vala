--- src/engine/api/geary-client-service.vala.orig	2023-07-05 12:44:13 UTC
+++ src/engine/api/geary-client-service.vala
@@ -25,9 +25,9 @@ public abstract class Geary.ClientService : BaseObject
     private const int BECAME_REACHABLE_TIMEOUT_SEC = 3;
     private const int BECAME_UNREACHABLE_TIMEOUT_SEC = 1;
 
-    private const string LOGIND_DBUS_NAME = "org.freedesktop.login1";
-    private const string LOGIND_DBUS_PATH = "/org/freedesktop/login1";
-    private const string LOGIND_DBUS_INTERFACE = "org.freedesktop.login1.Manager";
+    private const string LOGIND_DBUS_NAME = "org.freedesktop.ConsoleKit";
+    private const string LOGIND_DBUS_PATH = "/org/freedesktop/ConsoleKit/Manager";
+    private const string LOGIND_DBUS_INTERFACE = "org.freedesktop.ConsoleKit.Manager";
 
     /**
      * Denotes the service's current status.
