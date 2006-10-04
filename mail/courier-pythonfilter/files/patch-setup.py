--- setup.py.orig      Mon Mar 13 20:44:45 2006
+++ setup.py   Wed Jul 26 21:21:34 2006
@@ -15,5 +15,5 @@
       scripts=['pythonfilter'],
       packages=['courier', 'pythonfilter'],
       package_dir = {'pythonfilter': 'filters'},
-      data_files=[('/etc/', ['pythonfilter.conf'])]
+      data_files=[('/usr/local/etc/', ['pythonfilter.conf'])]
      )
