--- gdist/man.py.orig	2016-04-22 21:47:37 UTC
+++ gdist/man.py
@@ -40,7 +40,7 @@ class install_man(Command):
         )
 
         if self.mandir is None:
-            self.mandir = os.path.join(self.install_dir, 'share', 'man')
+            self.mandir = os.path.join(self.install_dir, 'man')
 
         self.man_pages = self.distribution.man_pages
         for man_page in self.man_pages:
