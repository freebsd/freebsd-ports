--- setup.py.orig	Fri Mar  4 16:06:45 2005
+++ setup.py	Fri Mar  4 16:07:37 2005
@@ -32,7 +32,8 @@
             'ext/xmlextra.c',
             ],
             libraries =     ['xml2'],
-            include_dirs =  ['libxml2addon','/usr/include/libxml2','/usr/local/include/libxml2'],
+            include_dirs =  ['libxml2addon','/usr/include/libxml2','/usr/local/include/libxml2','/usr/local/include'],
+            library_dirs = ['/usr/local/lib'],
             extra_compile_args = ['-g2'],
         ),
     ],
