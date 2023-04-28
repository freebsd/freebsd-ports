--- ext/cli_defaults/cli-defaults.sh.orig	2019-09-17 14:05:56 UTC
+++ ext/cli_defaults/cli-defaults.sh
@@ -1,7 +1,7 @@
-INSTALL_DIR="/opt/puppetlabs/server/apps/puppetserver"
+INSTALL_DIR="%%DATADIR%%"
 
 if [ -n "$JRUBY_JAR" ]; then
   echo "Warning: the JRUBY_JAR setting is no longer needed and will be ignored." 1>&2
 fi
 
-CLASSPATH="${CLASSPATH}:/opt/puppetlabs/puppet/lib/ruby/vendor_ruby/facter.jar:/opt/puppetlabs/server/data/puppetserver/jars/*"
+CLASSPATH="${CLASSPATH}:/usr/local/lib/ruby/vendor_ruby/facter.jar:/opt/puppetlabs/server/data/puppetserver/jars/*"
