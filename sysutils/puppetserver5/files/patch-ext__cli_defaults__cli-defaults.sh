--- ext/cli_defaults/cli-defaults.sh.orig	2017-08-06 01:24:37.981353156 -0700
+++ ext/cli_defaults/cli-defaults.sh	2017-08-06 01:39:53.280636611 -0700
@@ -1,6 +1,6 @@
-INSTALL_DIR="/opt/puppetlabs/server/apps/puppetserver"
+INSTALL_DIR="%%DATADIR%%"
 
-JRUBY_JAR="${JRUBY_JAR:-${INSTALL_DIR}/jruby-1_7.jar}"
+JRUBY_JAR="${JRUBY_JAR:-${INSTALL_DIR}/jruby-9k.jar}"
 
 if [ ! -e "$JRUBY_JAR" ]; then
   echo "Unable to find specified JRUBY_JAR: ${JRUBY_JAR}" 1>&2
