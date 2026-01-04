--- test/wrapper.py.orig	2026-01-04 14:26:35 UTC
+++ test/wrapper.py
@@ -3,8 +3,13 @@ import os
 import argparse
 import atexit
 import os
+import platform
 import subprocess
+import shutil
 import sys
+import signal
+import time
+import errno
 
 import dbus
 import dbus.mainloop.glib
@@ -17,18 +22,85 @@ def setup_test_namespace(data_dir):
     # Setup a new mount & user namespace, so we can use mount() unprivileged (see user_namespaces(7))
     euid = os.geteuid()
     egid = os.getegid()
-    os.unshare(os.CLONE_NEWNS|os.CLONE_NEWUSER)
-    # Map root to the original EUID and EGID, so we can actually call mount() inside our namespace
-    with open("/proc/self/uid_map", "w") as f:
-        f.write(f"0 {euid} 1")
-    with open("/proc/self/setgroups", "w") as f:
-        f.write("deny")
-    with open("/proc/self/gid_map", "w") as f:
-        f.write(f"0 {egid} 1")
+    try:
+        os.unshare(os.CLONE_NEWNS|os.CLONE_NEWUSER)
+        # Map root to the original EUID and EGID, so we can actually call mount() inside our namespace
+        with open("/proc/self/uid_map", "w") as f:
+            f.write(f"0 {euid} 1")
+        with open("/proc/self/setgroups", "w") as f:
+            f.write("deny")
+        with open("/proc/self/gid_map", "w") as f:
+            f.write(f"0 {egid} 1")
 
-    # Overmount /etc with our own version
-    subprocess.check_call(["mount", "--bind", os.path.join(data_dir, "etc"), "/etc"])
+        # Overmount /etc with our own version
+        subprocess.check_call(["mount", "--bind", os.path.join(data_dir, "etc"), "/etc"])
+    except PermissionError:
+        print("Lacking permissions to set up test harness, skipping")
+        return False
+    except AttributeError:
+        print("Python 3.12 is required for os.unshare(), skipping")
+        return False
+    return True
 
+
+def stop_dbus(pid: int) -> None:
+    """Stop a D-Bus daemon
+
+    If DBus daemon is not explicitly killed in the testing environment
+    the test times out and reports as failed.
+    This is a backport of a function dropped from DBusMock source (99c4800e9eed).
+    """
+    signal.signal(signal.SIGTERM, signal.SIG_IGN)
+    for _ in range(50):
+        try:
+            os.kill(pid, signal.SIGTERM)
+            os.waitpid(pid, os.WNOHANG)
+        except ChildProcessError:
+            break
+        except OSError as e:
+            if e.errno == errno.ESRCH:
+                break
+            raise
+        time.sleep(0.1)
+    else:
+        sys.stderr.write("ERROR: timed out waiting for bus process to terminate\n")
+        os.kill(pid, signal.SIGKILL)
+        try:
+            os.waitpid(pid, 0)
+        except ChildProcessError:
+            pass
+    signal.signal(signal.SIGTERM, signal.SIG_DFL)
+
+
+def setup_test_unconstrained_linux(data_dir):
+    shutil.copytree(os.path.join(data_dir, "etc"), "/etc", dirs_exist_ok=True)
+
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
@@ -39,12 +111,20 @@ if __name__ == "__main__":
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
         dbusmock.DBusTestCase.start_system_bus()
-        atexit.register(dbusmock.DBusTestCase.stop_dbus, dbusmock.DBusTestCase.system_bus_pid)
+        atexit.register(stop_dbus, dbusmock.DBusTestCase.system_bus_pid)
 
     print(f"Executing '{args.test_executable}'")
     sys.stdout.flush()
