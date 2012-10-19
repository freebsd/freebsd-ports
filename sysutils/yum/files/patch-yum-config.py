--- yum/config.py.orig	2010-06-17 17:24:18.000000000 +0200
+++ yum/config.py	2010-08-22 13:27:21.000000000 +0200
@@ -614,10 +614,10 @@
 
     distroverpkg = Option('redhat-release')
     installroot = Option('/')
-    config_file_path = Option('/etc/yum/yum.conf')
+    config_file_path = Option('@PREFIX@/etc/yum/yum.conf')
     plugins = BoolOption(False)
-    pluginpath = ListOption(['/usr/share/yum-plugins', '/usr/lib/yum-plugins'])
-    pluginconfpath = ListOption(['/etc/yum/pluginconf.d'])
+    pluginpath = ListOption(['@PREFIX@/share/yum-plugins', '@PREFIX@/lib/yum-plugins'])
+    pluginconfpath = ListOption(['@PREFIX@/etc/yum/pluginconf.d'])
     gaftonmode = BoolOption(False)
     syslog_ident = Option()
     syslog_facility = Option('LOG_USER')
@@ -637,7 +637,7 @@
 
     keepcache = BoolOption(True)
     logfile = Option('/var/log/yum.log')
-    reposdir = ListOption(['/etc/yum/repos.d', '/etc/yum.repos.d'])
+    reposdir = ListOption(['@PREFIX@/etc/yum/repos.d', '@PREFIX@/etc/yum.repos.d'])
 
     commands = ListOption()
     exclude = ListOption()
@@ -733,7 +733,7 @@
 
     rpmverbosity = Option('info')
 
-    protected_packages = ListOption("yum, glob:/etc/yum/protected.d/*.conf",
+    protected_packages = ListOption("yum, glob:@PREFIX@/etc/yum/protected.d/*.conf",
                                     parse_default=True)
     exit_on_lock = BoolOption(False)
     
@@ -898,7 +898,7 @@
     
     # Read the FS yumvars
     try:
-        dir_fsvars = yumconf.installroot + "/etc/yum/vars/"
+        dir_fsvars = yumconf.installroot + "@PREFIX@/etc/yum/vars/"
         fsvars = os.listdir(dir_fsvars)
     except OSError:
         fsvars = []
@@ -936,7 +936,7 @@
     
     return yumconf
 
-def readVersionGroupsConfig(configfile="/etc/yum/version-groups.conf"):
+def readVersionGroupsConfig(configfile="@PREFIX@/etc/yum/version-groups.conf"):
     parser = ConfigParser()
     confpp_obj = ConfigPreProcessor(configfile)
     try:
@@ -1048,7 +1048,7 @@
     fp.close()
 
 #def main():
-#    mainconf = readMainConfig(readStartupConfig('/etc/yum/yum.conf', '/'))
+#    mainconf = readMainConfig(readStartupConfig('@PREFIX@/etc/yum/yum.conf', '/'))
 #    print mainconf.cachedir
 #
 #if __name__ == '__main__':
