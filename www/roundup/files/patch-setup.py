--- ./setup.py.orig	2009-03-18 04:35:22.000000000 +0100
+++ ./setup.py	2009-05-14 22:29:50.000000000 +0200
@@ -71,9 +71,6 @@
     data_files = [
         ('share/roundup/cgi-bin', ['frontends/roundup.cgi']),
     ]
-    # install man pages on POSIX platforms
-    if os.name == 'posix':
-        data_files.append(include('share/man/man1', '*'))
 
     # add the templates to the data files lists
     from roundup.init import listTemplates
@@ -88,9 +85,6 @@
         data_files.append((os.path.dirname(_mo_file),
                            [os.path.join("build", _mo_file)]))
 
-    # add docs
-    data_files.append(include('share/doc/roundup/html', '*'))
-
     # perform the setup action
     from roundup import __version__
 
