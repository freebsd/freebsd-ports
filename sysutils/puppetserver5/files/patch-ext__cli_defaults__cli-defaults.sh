--- ext/cli_defaults/cli-defaults.sh.orig	2018-08-21 16:07:05 UTC
+++ ext/cli_defaults/cli-defaults.sh
@@ -1,6 +1,6 @@
-INSTALL_DIR="/opt/puppetlabs/server/apps/puppetserver"
+INSTALL_DIR="%%DATADIR%%"
 
-JRUBY_JAR="${JRUBY_JAR:-${INSTALL_DIR}/jruby-1_7.jar}"
+JRUBY_JAR="${JRUBY_JAR:-${INSTALL_DIR}/jruby-9k.jar}"
 
 if [ ! -e "$JRUBY_JAR" ]; then
   echo "Unable to find specified JRUBY_JAR: ${JRUBY_JAR}" 1>&2
