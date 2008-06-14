--- platform/gtk-x11/setup.py.orig	2008-05-28 16:05:13.000000000 +0200
+++ platform/gtk-x11/setup.py	2008-06-14 15:40:32.000000000 +0200
@@ -61,6 +61,7 @@
 ###############################################################################
 
 BOOST_LIB = 'boost_python'
+BOOST_LIB_PATH = '/usr/local/lib'
 
 USE_XINE_HACK = True #use_xine_hack_default()
 
@@ -222,6 +223,9 @@
             options_dict['library_dirs'].append(rest)
         elif prefix == '-l':
             options_dict['libraries'].append(rest)
+        elif prefix == '-W':
+            # throw away, it breaks cc1
+            continue
         else:
             options_dict['extra_compile_args'].append(comp)
     return options_dict
@@ -231,6 +235,7 @@
     Extension("miro.fasttypes", 
         sources = [os.path.join(portable_dir, 'fasttypes.cpp')],
         libraries = [BOOST_LIB],
+        library_dirs = [BOOST_LIB_PATH],
     )
 
 ##### The libtorrent extension ####
@@ -243,21 +248,17 @@
     sys.exit("Package config error:\n%s" % (error,))
 
 xulrunner19 = False
-if re.search("^libxul", packages, re.MULTILINE):
-    xulrunner19 = True
-    xpcom = 'libxul'
-    gtkmozembed = 'libxul'
-elif re.search("^xulrunner-xpcom", packages, re.MULTILINE):
-    xpcom = 'xulrunner-xpcom'
-    gtkmozembed = 'xulrunner-gtkmozembed'
+if re.search("^firefox-xpcom", packages, re.MULTILINE):
+    xpcom = 'firefox-xpcom'
+    gtkmozembed = 'firefox-gtkmozembed'
+elif re.search("^seamonkey-xpcom", packages, re.MULTILINE):
+    xpcom = 'seamonkey-xpcom'
+    gtkmozembed = 'seamonkey-gtkmozembed'
 elif re.search("^mozilla-xpcom", packages, re.MULTILINE):
     xpcom = 'mozilla-xpcom'
     gtkmozembed = 'mozilla-gtkmozembed'
-elif re.search("^firefox-xpcom", packages, re.MULTILINE):
-    xpcom = 'firefox-xpcom'
-    gtkmozembed = 'firefox-gtkmozembed'
 else:
-    sys.exit("Can't find libxul, xulrunner-xpcom, mozilla-xpcom or firefox-xpcom")
+    sys.exit("Can't find seamonkey-xpcom, mozilla-xpcom or firefox-xpcom")
 
 if not "clean" in sys.argv:
     # build a miro script that wraps the miro.real script with an LD_LIBRARY_PATH
@@ -383,7 +384,7 @@
 # add the desktop file, icons, mime data, and man page.
 
 if not "clean" in sys.argv:
-    rv = os.system ("gcc %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine`" % (os.path.join(platform_dir, "xine/xine_extractor.c"), os.path.join(platform_dir, "xine/xine_extractor")))
+    rv = os.system ("gcc %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine` %%PTHREAD_LIBS%%" % (os.path.join(platform_dir, "xine/xine_extractor.c"), os.path.join(platform_dir, "xine/xine_extractor")))
 
     if rv != 0:
         raise RuntimeError("xine_extractor compilation failed.  Possibly missing libxine, gdk-pixbuf-2.0, or glib-2.0.")
@@ -391,11 +392,11 @@
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
