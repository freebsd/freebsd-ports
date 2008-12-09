--- ./setup.py.orig	2008-12-09 11:20:48.000000000 -0500
+++ ./setup.py	2008-12-09 11:17:27.000000000 -0500
@@ -4,6 +4,8 @@
     name = 'TracTweakUI',
     version = '0.1',
     packages = ['tractweakui'],
+    package_dir = {'tractweakui': 'tractweakui'},
+    package_data = {'tractweakui': ['templates/*.html']},
     include_package_data = True,
     author = "Richard Liao",
     author_email = 'richard.liao.i@gmail.com',
@@ -18,4 +20,4 @@
     ],
     install_requires = [],
     entry_points = {'trac.plugins': ['tractweakui = tractweakui.web_ui']},
-)
\ No newline at end of file
+)
