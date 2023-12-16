--- setup.py.orig	2018-02-14 10:21:57 UTC
+++ setup.py
@@ -23,7 +23,7 @@ import pkginfo
 #-- A class describing the features and requirements of OpenLDAP 2.0
 class OpenLDAP2:
   library_dirs = []
-  include_dirs = []
+  include_dirs = ['%%LOCALBASE%%/include']
   extra_compile_args = []
   extra_link_args = []
   extra_objects = []
