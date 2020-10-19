--- gdist/man.py.orig	2019-10-05 20:22:11 UTC
+++ gdist/man.py
@@ -54,7 +54,7 @@ class install_man(Command):
         )
 
         if self.mandir is None:
-            self.mandir = os.path.join(self.install_dir, 'share', 'man')
+            self.mandir = os.path.join(self.install_dir, 'man')
 
         self.man_pages = self.distribution.man_pages
         for man_page in self.man_pages:
