--- usr/share/google/boto/boot_setup.py.orig	2014-12-05 20:59:35 UTC
+++ usr/share/google/boto/boot_setup.py
@@ -31,9 +31,9 @@ import urllib2
 
 NUMERIC_PROJECT_ID_URL=('http://169.254.169.254/'
                         'computeMetadata/v1/project/numeric-project-id')
-SYSTEM_BOTO_CONFIG_TEMPLATE='/etc/boto.cfg.template'
-SYSTEM_BOTO_CONFIG='/etc/boto.cfg'
-AUTH_PLUGIN_DIR='/usr/share/google/boto/boto_plugins'
+SYSTEM_BOTO_CONFIG_TEMPLATE='%%PREFIX%%/etc/boto.cfg.template'
+SYSTEM_BOTO_CONFIG='%%PREFIX%%/etc/boto.cfg'
+AUTH_PLUGIN_DIR='%%PREFIX%%/share/google/boto/boto_plugins'
 
 
 def GetNumericProjectId():
