--- setup.py.orig	2009-01-03 06:18:54.000000000 +0100
+++ setup.py	2009-01-03 09:35:47.000000000 +0100
@@ -15,6 +15,6 @@
       scripts=['pythonfilter', 'pythonfilter-quarantine'],
       packages=['courier', 'pythonfilter'],
       package_dir={'pythonfilter': 'filters'},
-      data_files=[('/etc/', ['pythonfilter.conf',
-                             'pythonfilter-modules.conf'])]
+      data_files=[(os.environ['PREFIX'] + '/etc/', ['pythonfilter.conf.sample',
+                                                    'pythonfilter-modules.conf.sample'])]
      )
