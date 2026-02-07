Do not ask an interactive question during the install phase.

--- src/xim/install.sh.orig	2018-08-25 14:18:57 UTC
+++ src/xim/install.sh
@@ -1,4 +1,5 @@
 #!/bin/sh
+exit 0
 echo 
 echo "To use UniKey, certain environment variables must be set."
 echo "Do you want to set these variables in /etc/profile? (y/N)"
