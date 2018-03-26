--- mqttwarn.py.orig	2018-03-26 20:00:37 UTC
+++ mqttwarn.py
@@ -83,6 +83,8 @@ class Config(RawConfigParser):
         self.cleansession = False
         self.protocol     = 3
 
+        self.libdir       = ''
+
         self.logformat    = '%(asctime)-15s %(levelname)-5s [%(module)s] %(message)s'
         self.logfile      = LOGFILE
         self.loglevel     = 'DEBUG'
@@ -999,7 +1001,7 @@ def load_services(services):
         modulefile = 'services/%s.py' % module
 
         try:
-            service_plugins[service]['module'] = load_module(modulefile)
+            service_plugins[service]['module'] = load_module(cf.libdir + '/' + modulefile)
             logging.debug("Service %s loaded" % (service))
         except Exception, e:
             logging.error("Can't load %s service (%s): %s" % (service, modulefile, str(e)))
