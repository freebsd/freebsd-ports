--- yum/__init__.py.orig	2010-07-30 21:59:10.000000000 +0200
+++ yum/__init__.py	2010-08-22 13:33:50.000000000 +0200
@@ -92,7 +92,7 @@
        you tweak it here, and when yb.conf does it's thing ... it happens. """
 
     def __init__(self):
-        self.fn = '/etc/yum/yum.conf'
+        self.fn = '@PREFIX@/etc/yum/yum.conf'
         self.root = '/'
         self.init_plugins = True
         self.plugin_types = (plugins.TYPE_CORE,)
@@ -208,7 +208,7 @@
         self.preconf.init_plugins = False
         self.conf.cache = cache
 
-    def doConfigSetup(self, fn='/etc/yum/yum.conf', root='/', init_plugins=True,
+    def doConfigSetup(self, fn='@PREFIX@/etc/yum/yum.conf', root='/', init_plugins=True,
             plugin_types=(plugins.TYPE_CORE,), optparser=None, debuglevel=None,
             errorlevel=None):
         warnings.warn(_('doConfigSetup() will go away in a future version of Yum.\n'),
@@ -270,9 +270,9 @@
 
         # TODO: Remove this block when we no longer support configs outside
         # of /etc/yum/
-        if fn == '/etc/yum/yum.conf' and not os.path.exists(fn):
+        if fn == '@PREFIX@/etc/yum/yum.conf' and not os.path.exists(fn):
             # Try the old default
-            fn = '/etc/yum.conf'
+            fn = '@PREFIX@/etc/yum.conf'
 
         startupconf = config.readStartupConfig(fn, root)
         startupconf.arch = arch
