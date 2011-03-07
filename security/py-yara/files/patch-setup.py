--- ./setup.py.orig	2011-03-07 12:21:10.504810488 -0500
+++ ./setup.py	2011-03-07 12:21:30.973804718 -0500
@@ -11,8 +11,9 @@
                                     name='yara', 
                                     sources=['yara-python.c'],
                                     libraries=['yara','pcre'],
-                                    include_dirs=['/usr/local/include']
+                                    include_dirs=['/usr/local/include'],
+                                    library_dirs=['/usr/local/lib']
                                     )])
      
  
-                                  
\ No newline at end of file
+                                  
