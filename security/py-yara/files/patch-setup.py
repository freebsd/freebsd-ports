--- ./setup.py.orig	2011-03-08 15:18:51.000000000 -0500
+++ ./setup.py	2011-05-22 21:27:25.075485034 -0400
@@ -10,9 +10,10 @@
         ext_modules = [ Extension(
                                     name='yara', 
                                     sources=['yara-python.c'],
-                                    libraries=['yara','pcre'],
-                                    include_dirs=['/usr/local/include']
+                                    libraries=['yara','re2'],
+                                    include_dirs=['%%LOCALBASE%%/include'],
+                                    library_dirs=['%%LOCALBASE%%/lib']
                                     )])
      
  
-                                  
\ No newline at end of file
+                                  
