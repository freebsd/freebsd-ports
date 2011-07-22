--- ./setup.py.orig	2011-07-22 16:18:25.000000000 +0200
+++ ./setup.py	2011-07-22 16:19:10.000000000 +0200
@@ -72,9 +72,6 @@
     data_files = [
         ('share/roundup/cgi-bin', ['frontends/roundup.cgi']),
     ]
-    # install man pages on POSIX platforms
-    if os.name == 'posix':
-        data_files.append(include('share/man/man1', '*'))
 
     # add the templates to the data files lists
     from roundup.init import listTemplates
@@ -84,14 +81,6 @@
         for idir in '. detectors extensions html'.split():
             data_files.append(include(os.path.join(tdir, idir), '*'))
 
-    # add message files
-    for (_dist_file, _mo_file) in list_message_files():
-        data_files.append((os.path.dirname(_mo_file),
-                           [os.path.join("build", _mo_file)]))
-
-    # add docs
-    data_files.append(include('share/doc/roundup/html', '*'))
-
     # perform the setup action
     from roundup import __version__
 
