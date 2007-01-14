--- setup.py.orig	Sat Dec 16 22:39:23 2006
+++ setup.py	Sat Dec 16 22:35:49 2006
@@ -7,7 +7,7 @@
     name = 'flup',
     version = '0.5',
     packages = find_packages(),
-    zip_safe = True, # Despite flup.resolver.importingmodule
+#    zip_safe = True, # Despite flup.resolver.importingmodule
     
     entry_points = """
     [paste.server_factory]
