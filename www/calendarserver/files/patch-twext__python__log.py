--- twext/python/log.py.orig	2013-09-17 23:08:55 UTC
+++ twext/python/log.py
@@ -932,24 +932,29 @@
         # Don't patch this module
         if moduleName is __name__:
             continue
-
-        for name, obj in module.__dict__.iteritems():
-            newLogger = Logger(namespace=module.__name__)
-            legacyLogger = LegacyLogger(logger=newLogger)
-
-            if obj is twisted.python.log:
-                log.info("Replacing Twisted log module object {0} in {1}"
-                         .format(name, module.__name__))
-                setattr(module, name, legacyLogger)
-            elif obj is twisted.python.log.msg:
-                log.info("Replacing Twisted log.msg object {0} in {1}"
-                         .format(name, module.__name__))
-                setattr(module, name, legacyLogger.msg)
-            elif obj is twisted.python.log.err:
-                log.info("Replacing Twisted log.err object {0} in {1}"
-                         .format(name, module.__name__))
-                setattr(module, name, legacyLogger.err)
-
+    
+        try:
+            for name, obj in module.__dict__.iteritems():
+                newLogger = Logger(namespace=module.__name__)
+                legacyLogger = LegacyLogger(logger=newLogger)
+    
+                if obj is twisted.python.log:
+                    log.info("Replacing Twisted log module object {0} in {1}"
+                             .format(name, module.__name__))
+                    setattr(module, name, legacyLogger)
+                elif obj is twisted.python.log.msg:
+                    log.info("Replacing Twisted log.msg object {0} in {1}"
+                             .format(name, module.__name__))
+                    setattr(module, name, legacyLogger.msg)
+                elif obj is twisted.python.log.err:
+                    log.info("Replacing Twisted log.err object {0} in {1}"
+                             .format(name, module.__name__))
+                    setattr(module, name, legacyLogger.err)
+        except (AttributeError, RuntimeError,):
+            # Can't look up __name__.  A hack in the "six" module causes
+            # this.  Skip the module.
+            # See https://trac.calendarserver.org/ticket/832
+            continue
 
 
 ######################################################################
