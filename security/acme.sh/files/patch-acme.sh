Fix sudo issue
https://github.com/acmesh-official/acme.sh/pull/2574

--- acme.sh.orig	2020-08-02 05:02:04 UTC
+++ acme.sh
@@ -6415,10 +6415,10 @@ _checkSudo() {
       #it's root using sudo, no matter it's using sudo or not, just fine
       return 0
     fi
-    if [ "$SUDO_COMMAND" = "/bin/su" ] || [ "$SUDO_COMMAND" = "/bin/bash" ]; then
+    if [ -n "$SUDO_COMMAND" ]; then
       #it's a normal user doing "sudo su", or `sudo -i` or `sudo -s`
-      #fine
-      return 0
+      _endswith "$SUDO_COMMAND" /bin/su || grep "^$SUDO_COMMAND\$" /etc/shells >/dev/null 2>&1
+      return $?
     fi
     #otherwise
     return 1
