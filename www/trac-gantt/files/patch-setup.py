--- setup.py.orig	2008-08-13 08:54:31.000000000 -0400
+++ setup.py	2008-08-13 08:54:44.000000000 -0400
@@ -9,8 +9,8 @@
         packages = ['tracgantt'],
         package_data={'tracgantt': ['templates/*.cs', 'htdocs/*.css']},
 
-        #install_requires = ['trac>=0.9'],
-        #entry_points = {'trac.plugins': ['module_name = gantt']},
+        install_requires = ['trac>=0.11'],
+        entry_points = {'trac.plugins': ['tracgantt = tracgantt']},
         
         author = "Will Barton",
         author_email = "wbb4@opendarwin.org",
