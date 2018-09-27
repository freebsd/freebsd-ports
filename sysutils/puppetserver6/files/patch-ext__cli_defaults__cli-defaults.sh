--- ext/cli_defaults/cli-defaults.sh.orig	2017-08-06 01:24:37.981353156 -0700
+++ ext/cli_defaults/cli-defaults.sh	2017-08-06 01:39:53.280636611 -0700
@@ -1,4 +1,4 @@
-INSTALL_DIR="/opt/puppetlabs/server/apps/puppetserver"
+INSTALL_DIR="%%DATADIR%%"
 
 if [ -n "$JRUBY_JAR" ]; then
   echo "Warning: the JRUBY_JAR setting is no longer needed and will be ignored." 1>&2
