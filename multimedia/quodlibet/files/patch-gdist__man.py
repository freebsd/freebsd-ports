--- gdist/man.py.orig	2010-02-18 02:56:24.000000000 -0500
+++ gdist/man.py	2010-02-18 02:56:58.000000000 -0500
@@ -36,7 +36,7 @@
                 raise SystemExit("%r has no section" % man_page)
 
     def run(self):
-        basepath = os.path.join(self.prefix, 'share', 'man')
+        basepath = os.path.join(self.prefix, 'man')
         if self.root != None:
           basepath = change_root(self.root, basepath)
         self.mkpath(basepath)
