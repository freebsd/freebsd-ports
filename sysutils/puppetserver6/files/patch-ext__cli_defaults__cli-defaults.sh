--- ext/cli_defaults/cli-defaults.sh.orig	2018-10-01 20:36:08 UTC
+++ ext/cli_defaults/cli-defaults.sh
@@ -1,4 +1,4 @@
-INSTALL_DIR="/opt/puppetlabs/server/apps/puppetserver"
+INSTALL_DIR="%%DATADIR%%"
 
 if [ -n "$JRUBY_JAR" ]; then
   echo "Warning: the JRUBY_JAR setting is no longer needed and will be ignored." 1>&2
