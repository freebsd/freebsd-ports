--- installer/pluginhandler.py.orig	2022-02-23 07:41:04 UTC
+++ installer/pluginhandler.py
@@ -80,7 +80,7 @@ class PluginHandle(object):
         DOCDIR = sys_conf.get('dirs', 'doc')
         CUPSBACKENDDIR = sys_conf.get('dirs', 'cupsbackend')
         CUPSFILTERDIR = sys_conf.get('dirs', 'cupsfilter')
-        RULESDIR = '/etc/udev/rules.d'
+        RULESDIR = '/usr/local/etc/udev/rules.d'
         BIN = sys_conf.get('dirs', 'bin')
 
         # Copying plugin.spec file to home dir.
@@ -97,11 +97,11 @@ class PluginHandle(object):
             ARCH = 'x86_%d' % BITNESS
 
         if BITNESS == 64:
-            SANELIBDIR = '/usr/lib64/sane'
-            LIBDIR = '/usr/lib64'
+            SANELIBDIR = '/usr/local/lib/sane'
+            LIBDIR = '/usr/local/lib'
         else:
-            SANELIBDIR = '/usr/lib/sane'
-            LIBDIR = '/usr/lib'
+            SANELIBDIR = '/usr/local/lib/sane'
+            LIBDIR = '/usr/local/lib'
 
         copies = []
 
@@ -239,8 +239,8 @@ class PluginHandle(object):
     def __setPluginConfFile(self):
         home = sys_conf.get('dirs', 'home')
 
-        if os.path.exists('/etc/hp/plugin.conf'):
-            self.__plugin_conf_file = "file:///etc/hp/plugin.conf"
+        if os.path.exists('/usr/local/etc/hp/plugin.conf'):
+            self.__plugin_conf_file = "file:///usr/local/etc/hp/plugin.conf"
 
         elif os.path.exists(os.path.join(home, 'plugin.conf')):
             self.__plugin_conf_file = "file://" + os.path.join(home, 'plugin.conf')
@@ -268,7 +268,7 @@ class PluginHandle(object):
         log.debug("Downloading %s plug-in file from '%s' to '%s'..." % (self.__required_version, src, self.__plugin_path))
         plugin_file = os.path.join(self.__plugin_path, self.__plugin_name)
         try:
-            os.umask(0)
+            os.umask(0o022)
             if not os.path.exists(self.__plugin_path):
                 os.makedirs(self.__plugin_path, 0o755)
             if os.path.exists(plugin_file):
@@ -373,7 +373,7 @@ class PluginHandle(object):
     def copyFiles(self, src_dir):
 
         copies = self.__getPluginFilesList(src_dir)
-        os.umask(0)
+        os.umask(0o022)
 
         for src, trg, link in copies:
 
