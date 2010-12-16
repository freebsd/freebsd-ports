--- ./Ft/Lib/DistExt/InstallText.py.orig	2010-12-16 23:05:48.000000000 +0100
+++ ./Ft/Lib/DistExt/InstallText.py	2010-12-16 23:09:04.000000000 +0100
@@ -27,9 +27,10 @@
                                    ('install_docs', 'install_dir'),
                                    ('force', 'force'))
 
+        portdocs = not os.environ.has_key('NOPORTDOCS')
         self.files = [ f for f in self.distribution.doc_files
-                       if isinstance(f, Structures.File) ]
-        if self.distribution.license_file:
+                       if isinstance(f, Structures.File) and portdocs ]
+        if self.distribution.license_file and portdocs:
             self.files.append(Structures.File(self.distribution.license_file))
         return
 
