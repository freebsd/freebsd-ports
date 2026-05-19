--- hermes_cli/main.py.orig	2026-05-16 09:59:15 UTC
+++ hermes_cli/main.py	2026-05-19 11:13:44.567947000 +0200
@@ -9838,7 +9838,7 @@
     gateway_start.add_argument(
         "--system",
         action="store_true",
-        help="Target the Linux system-level gateway service",
+        help="Target the system-level gateway service (Linux only; ignored on FreeBSD/macOS)",
     )
     gateway_start.add_argument(
         "--all",
@@ -9851,7 +9851,7 @@
     gateway_stop.add_argument(
         "--system",
         action="store_true",
-        help="Target the Linux system-level gateway service",
+        help="Target the system-level gateway service (Linux only; ignored on FreeBSD/macOS)",
     )
     gateway_stop.add_argument(
         "--all",
@@ -9866,7 +9866,7 @@
     gateway_restart.add_argument(
         "--system",
         action="store_true",
-        help="Target the Linux system-level gateway service",
+        help="Target the system-level gateway service (Linux only; ignored on FreeBSD/macOS)",
     )
     gateway_restart.add_argument(
         "--all",
@@ -9886,23 +9886,23 @@
     gateway_status.add_argument(
         "--system",
         action="store_true",
-        help="Target the Linux system-level gateway service",
+        help="Target the system-level gateway service (Linux only; ignored on FreeBSD/macOS)",
     )
 
     # gateway install
     gateway_install = gateway_subparsers.add_parser(
-        "install", help="Install gateway as a systemd/launchd background service"
+        "install", help="Install gateway as a systemd/launchd/rc.d background service"
     )
     gateway_install.add_argument("--force", action="store_true", help="Force reinstall")
     gateway_install.add_argument(
         "--system",
         action="store_true",
-        help="Install as a Linux system-level service (starts at boot)",
+        help="Install as a system-level service (Linux only; FreeBSD rc.d is always system-scoped)",
     )
     gateway_install.add_argument(
         "--run-as-user",
         dest="run_as_user",
-        help="User account the Linux system service should run as",
+        help="User account the service should run as (Linux systemd / FreeBSD rc.d)",
     )
 
     # gateway uninstall
@@ -9912,7 +9912,7 @@
     gateway_uninstall.add_argument(
         "--system",
         action="store_true",
-        help="Target the Linux system-level gateway service",
+        help="Target the system-level gateway service (Linux only; ignored on FreeBSD/macOS)",
     )
 
     # gateway list
