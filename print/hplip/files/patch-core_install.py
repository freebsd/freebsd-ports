--- installer/core_install.py.old	2010-04-30 05:23:48.000000000 -0500
+++ installer/core_install.py	2010-04-30 05:24:07.000000000 -0500
@@ -897,7 +897,7 @@
 
 
     def check_sane_devel(self):
-        return len(locate_file_contains("sane.h", '/usr/include', 'extern SANE_Status sane_init'))
+        return len(locate_file_contains("sane.h", '/usr/local/include/sane', 'extern SANE_Status sane_init'))
 
 
     def check_xsane(self):
