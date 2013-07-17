--- ./setup.py.orig	2013-07-17 12:52:04.000000000 -0400
+++ ./setup.py	2013-07-17 12:51:52.000000000 -0400
@@ -10,7 +10,8 @@
                                     name='yara', 
                                     sources=['yara-python.c'],
                                     libraries=['yara','pcre'],
-                                    include_dirs=['/usr/local/include']
+                                    include_dirs=['%%LOCALBASE%%/include'],
+                                    library_dirs=['%%LOCALBASE%%/lib']
                                     )])
      
  
