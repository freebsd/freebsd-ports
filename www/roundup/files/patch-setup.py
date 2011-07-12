--- ./setup.py.orig	2011-05-13 11:20:33.000000000 +0200
+++ ./setup.py	2011-07-11 23:52:17.000000000 +0200
@@ -71,9 +71,6 @@
     data_files = [
         ('share/roundup/cgi-bin', ['frontends/roundup.cgi']),
     ]
-    # install man pages on POSIX platforms
-    if os.name == 'posix':
-        data_files.append(include('share/man/man1', '*'))
 
     # add the templates to the data files lists
     from roundup.init import listTemplates
@@ -83,14 +80,6 @@
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
 
