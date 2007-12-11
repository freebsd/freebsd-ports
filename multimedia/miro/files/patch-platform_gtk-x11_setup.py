--- platform/gtk-x11/setup.py.orig	2007-10-31 17:05:49.000000000 +0100
+++ platform/gtk-x11/setup.py	2007-11-01 12:44:27.000000000 +0100
@@ -46,6 +46,7 @@
 ###############################################################################
 
 BOOST_LIB = 'boost_python'
+BOOST_LIB_PATH = '/usr/local/lib'
 
 USE_XINE_HACK = True #use_xine_hack_default()
 
@@ -200,6 +201,9 @@
             options_dict['library_dirs'].append(rest)
         elif prefix == '-l':
             options_dict['libraries'].append(rest)
+        elif prefix == '-W':
+            # throw away, it breaks cc1
+            continue
         else:
             options_dict['extra_compile_args'].append(comp)
     return options_dict
@@ -209,6 +213,7 @@
     Extension("miro.fasttypes", 
         sources = [os.path.join(portable_dir, 'fasttypes.cpp')],
         libraries = [BOOST_LIB],
+        library_dirs = [BOOST_LIB_PATH],
     )
 
 #### MozillaBrowser Extension ####
@@ -219,12 +224,15 @@
 if re.search("^xulrunner-xpcom", packages, re.MULTILINE):
     xpcom = 'xulrunner-xpcom'
     gtkmozembed = 'xulrunner-gtkmozembed'
-elif re.search("^mozilla-xpcom", packages, re.MULTILINE):
-    xpcom = 'mozilla-xpcom'
-    gtkmozembed = 'mozilla-gtkmozembed'
 elif re.search("^firefox-xpcom", packages, re.MULTILINE):
     xpcom = 'firefox-xpcom'
     gtkmozembed = 'firefox-gtkmozembed'
+elif re.search("^seamonkey-xpcom", packages, re.MULTILINE):
+    xpcom = 'seamonkey-xpcom'
+    gtkmozembed = 'seamonkey-gtkmozembed'
+elif re.search("^mozilla-xpcom", packages, re.MULTILINE):
+    xpcom = 'mozilla-xpcom'
+    gtkmozembed = 'mozilla-gtkmozembed'
 else:
     sys.exit("Can't find xulrunner-xpcom, mozilla-xpcom or firefox-xpcom")
 
@@ -334,7 +342,7 @@
     data_files.append((dest_dir, listfiles(source_dir)))
 # add the desktop file, icons, mime data, and man page.
 
-rv = os.system ("gcc %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine`" % (os.path.join(platform_dir, "xine/xine_extractor.c"), os.path.join(platform_dir, "xine/xine_extractor")))
+rv = os.system ("gcc %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine` %%PTHREAD_LIBS%%" % (os.path.join(platform_dir, "xine/xine_extractor.c"), os.path.join(platform_dir, "xine/xine_extractor")))
 
 if rv != 0:
     raise RuntimeError("xine_extractor compilation failed.  Possibly missing libxine, gdk-pixbuf-2.0, or glib-2.0.")
@@ -342,11 +350,11 @@
 data_files += [
     ('/usr/share/pixmaps', 
      glob(os.path.join(platform_dir, 'miro-*.png'))),
-    ('/usr/share/applications', 
+    ('/usr/local/share/applications', 
      [os.path.join(platform_dir, 'miro.desktop')]),
-    ('/usr/share/mime/packages', 
+    ('/usr/local/share/mime/packages', 
      [os.path.join(platform_dir, 'miro.xml')]),
-    ('/usr/share/man/man1',
+    ('/usr/local/man/man1',
      [os.path.join(platform_dir, 'miro.1.gz')]),
     ('/usr/libexec/',
      [os.path.join(platform_dir, 'xine/xine_extractor')]),
