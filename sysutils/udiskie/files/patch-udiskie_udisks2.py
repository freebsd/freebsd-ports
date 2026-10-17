--- udiskie/udisks2.py.orig	2026-09-29 14:53:20 UTC
+++ udiskie/udisks2.py
@@ -734,8 +734,14 @@ class Daemon(Emitter):
                    '/org/freedesktop/UDisks2/Manager',
                    Interface['Properties'])
         manager = await dbus.connect_service(*service)
-        version = await dbus.call(manager._proxy, 'Get', '(ss)', (
-            Interface['Manager'], 'Version'))
+        try:
+            version = await dbus.call(manager._proxy, 'Get', '(ss)', (
+                Interface['Manager'], 'Version'))
+        except GLib.Error:
+            # Some UDisks2 implementations, such as bsdisks on FreeBSD, do
+            # not export the Manager object. Treat the version as unknown,
+            # which also disables the keyfile support check.
+            return '0'
         return version
 
     async def loop_setup(self, fd, options):
