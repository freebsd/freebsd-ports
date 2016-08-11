--- setup.py.orig	2006-07-20 17:08:15 UTC
+++ setup.py
@@ -9,8 +9,8 @@ setup (
         packages = ['tracgantt'],
         package_data={'tracgantt': ['templates/*.cs', 'htdocs/*.css']},
 
-        #install_requires = ['trac>=0.9'],
-        #entry_points = {'trac.plugins': ['module_name = gantt']},
+        install_requires = ['trac>=0.11'],
+        entry_points = {'trac.plugins': ['tracgantt = tracgantt']},
         
         author = "Will Barton",
         author_email = "wbb4@opendarwin.org",
