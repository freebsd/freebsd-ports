--- subliminal/services/__init__.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/__init__.py	2013-04-27 23:33:06.000000000 +0200
@@ -81,7 +81,8 @@
     def init(self):
         """Initialize connection"""
         logger.debug(u'Initializing %s' % self.__class__.__name__)
-        self.session = requests.session(timeout=10, headers={'User-Agent': self.user_agent})
+        self.session = requests.Session()
+        self.session.headers.update({'User-Agent': self.user_agent})
 
     def init_cache(self):
         """Initialize cache, make sure it is loaded from disk"""
