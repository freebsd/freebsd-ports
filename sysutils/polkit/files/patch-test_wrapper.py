--- test/wrapper.py.orig	2026-01-07 09:02:36 UTC
+++ test/wrapper.py
@@ -3,7 +3,9 @@ import os
 import argparse
 import atexit
 import os
+import platform
 import subprocess
+import shutil
 import sys
 import signal
 import time
@@ -34,10 +36,11 @@ def setup_test_namespace(data_dir):
         subprocess.check_call(["mount", "--bind", os.path.join(data_dir, "etc"), "/etc"])
     except PermissionError:
         print("Lacking permissions to set up test harness, skipping")
-        sys.exit(77)
+        return False
     except AttributeError:
         print("Python 3.12 is required for os.unshare(), skipping")
-        sys.exit(77)
+        return False
+    return True
 
 
 def stop_dbus(pid: int) -> None:
@@ -69,6 +72,32 @@ def stop_dbus(pid: int) -> None:
     signal.signal(signal.SIGTERM, signal.SIG_DFL)
 
 
+def setup_test_unconstrained_freebsd(data_dir):
+    passwd = os.path.join(data_dir, "etc", "passwd")
+    with open(passwd, 'r') as file:
+        for line in file:
+            fields = line.split(":")
+            if fields[0] == "root":
+                continue
+            subprocess.call(["pw", "useradd", "-n", fields[0], "-u", fields[2], "-c", fields[4], "-d", fields[5], "-s", fields[6].strip()])
+    group = os.path.join(data_dir, "etc", "group")
+    with open(group, 'r') as file:
+        for line in file:
+            fields = line.split(":")
+            cmd = ["pw", "groupadd", "-n", fields[0], "-g", fields[2]]
+            members = fields[3].strip()
+            if len(members) > 0:
+                cmd.append("-M")
+                cmd.append(members)
+            if fields[0] == "root":
+                cmd = ["pw", "groupmod", "-g", "0", "-l", "root"]
+            subprocess.call(cmd)
+    shutil.copy2(os.path.join(data_dir, "etc", "netgroup"), "/etc/netgroup")
+    shutil.copy2("/usr/bin/true", "/bin/true")
+    bus = dbus.SystemBus()
+    consolekit = bus.get_object("org.freedesktop.ConsoleKit", "/org/freedesktop/ConsoleKit/Manager")
+    consolekit.GetSeats(dbus_interface="org.freedesktop.ConsoleKit.Manager")
+
 if __name__ == "__main__":
     parser = argparse.ArgumentParser()
     parser.add_argument("test_executable",
@@ -79,7 +108,15 @@ if __name__ == "__main__":
                         help="set up a mock system D-Bus using dbusmock")
     args = parser.parse_args()
 
-    setup_test_namespace(args.data_dir)
+    if not setup_test_namespace(args.data_dir):
+        if os.getenv("ALLOW_SYSTEM_AFFECTING_TESTS") == "1":
+            if platform.system() == 'FreeBSD':
+                setup_test_unconstrained_freebsd(args.data_dir)
+            else:
+                setup_test_unconstrained_linux(args.data_dir)
+        else:
+            # skip tests
+            sys.exit(77)
 
     if args.mock_dbus:
         dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
