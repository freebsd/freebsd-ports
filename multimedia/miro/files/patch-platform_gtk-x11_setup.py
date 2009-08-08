--- platform/gtk-x11/setup.py.orig	2009-07-25 12:41:12.000000000 +0900
+++ platform/gtk-x11/setup.py	2009-07-30 15:52:08.000000000 +0900
@@ -112,14 +112,15 @@
 # XPCOM_LIB = "firefox-xpcom"
 # GTKMOZEMBED_LIB = "firefox-gtkmozembed"
 # XULRUNNER_19 = False
-XPCOM_LIB = None
-GTKMOZEMBED_LIB = None
-XULRUNNER_19 = None
+XPCOM_LIB = "%%XPCOM_LIB%%"
+GTKMOZEMBED_LIB = "%%GTKMOZEMBED_LIB%%"
+XULRUNNER_19 = %%XULRUNNER_19%%
 
 # The name of the boost python library.  Used for building extensions.
 # If this is set to None, setup.py will divine the right lib to use.
 # It should probably be either "boost_python" or "boost_python-mt".
-BOOST_LIB = None
+BOOST_LIB = 'boost_python'
+BOOST_LIB_PATH = '%%LOCALBASE%%/lib'
 
 
 ###############################################################################
@@ -285,6 +286,9 @@
             options_dict['library_dirs'].append(rest)
         elif prefix == '-l':
             options_dict['libraries'].append(rest)
+        elif prefix == '-W':
+            # throw away, it breaks cc1
+            continue
         else:
             options_dict['extra_compile_args'].append(comp)
 
@@ -315,7 +319,7 @@
     print "Using %s" % BOOST_LIB
 
 def compile_xine_extractor():
-    rv = os.system("gcc %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine`" %
+    rv = os.system("%%CC%% %s -o %s `pkg-config --libs --cflags gdk-pixbuf-2.0 glib-2.0 libxine` %%PTHREAD_LIBS%%" %
                    (os.path.join(platform_dir, "xine/xine_extractor.c"), os.path.join(platform_dir, "xine/xine_extractor")))
     if rv != 0:
         raise RuntimeError("xine_extractor compilation failed.  Possibly missing libxine, gdk-pixbuf-2.0, or glib-2.0.")
@@ -353,7 +357,7 @@
         exit;
     fi
 
-    %(runtimelib)s$GDB -ex 'set breakpoint pending on' -ex 'run' --args $PYTHON ./miro.real --sync "$@"
+    %(runtimelib)s$GDB -ex 'set breakpoint pending on' -ex 'run' --args $PYTHON %%PREFIX%%/bin/miro.real --sync "$@"
 else
     %(runtimelib)smiro.real "$@"
 fi
@@ -366,6 +370,7 @@
     Extension("miro.fasttypes",
         sources = [os.path.join(portable_dir, 'fasttypes.cpp')],
         libraries = [BOOST_LIB],
+        library_dirs = [BOOST_LIB_PATH],
     )
 
 
@@ -402,12 +407,12 @@
                           "-DHAVE___INCLUDE_LIBTORRENT_ASIO_SSL_STREAM_HPP=1",
                           "-DHAVE___INCLUDE_LIBTORRENT_ASIO_IP_TCP_HPP=1",
                           "-DHAVE_PTHREAD=1", "-DTORRENT_USE_OPENSSL=1", "-DHAVE_SSL=1",
-                          "-DNDEBUG=1", "-O2"]
+                          "-DNDEBUG=1"]
 
     if is_x64():
         extra_compile_args.append("-DAMD64")
 
-    libraries = ['z', 'pthread', 'ssl']
+    libraries = ['z', 'ssl']
 
     # get mt or non-mt versions of the boost libraries
     libraries += [mt_or_not("boost_python"),
@@ -432,6 +437,7 @@
     return Extension("miro.libtorrent",
                      include_dirs=include_dirs,
                      libraries=libraries,
+                     library_dirs=[BOOST_LIB_PATH],
                      extra_compile_args=extra_compile_args,
                      sources=sources)
 
@@ -558,7 +564,7 @@
 xlib_ext = \
     Extension("miro.plat.xlibhelper",
         [ os.path.join(platform_package_dir,'xlibhelper.pyx') ],
-        library_dirs = ['/usr/X11R6/lib'],
+        library_dirs = ['%%LOCALBASE%%/lib'],
         libraries = ['X11'],
     )
 
@@ -644,36 +650,36 @@
 # filter out app.config.template (which is handled specially)
 files = [f for f in listfiles(resource_dir) \
         if os.path.basename(f) != 'app.config.template']
-data_files.append(('/usr/share/miro/resources/', files))
+data_files.append(('%%PREFIX%%/share/miro/resources/', files))
 # handle the sub directories.
 for dir in ('searchengines', 'images', 'testdata',
         os.path.join('testdata', 'stripperdata'),
         os.path.join('testdata', 'locale', 'fr', 'LC_MESSAGES')):
     source_dir = os.path.join(resource_dir, dir)
-    dest_dir = os.path.join('/usr/share/miro/resources/', dir)
+    dest_dir = os.path.join('%%PREFIX%%/share/miro/resources/', dir)
     data_files.append((dest_dir, listfiles(source_dir)))
 
 for mem in ["24", "48", "72", "128"]:
     d = os.path.join("icons", "hicolor", "%sx%s" % (mem, mem), "apps")
     source = os.path.join(platform_dir, d, "miro.png")
-    dest = os.path.join("/usr/share/", d)
+    dest = os.path.join("%%PREFIX%%/share/", d)
     data_files.append((dest, [source]))
 
 # add ADOPTERS file, the desktop file, mime data, and man page
 data_files += [
-    ('/usr/share/miro/resources',
+    ('%%PREFIX%%/share/miro/resources',
      [os.path.join(root_dir, 'ADOPTERS')]),
-    ('/usr/share/pixmaps',
+    ('%%PREFIX%%/share/pixmaps',
      glob(os.path.join(platform_dir, 'miro.xpm'))),
-    ('/usr/share/applications',
+    ('%%PREFIX%%/share/applications',
      [os.path.join(platform_dir, 'miro.desktop')]),
-    ('/usr/share/mime/packages',
+    ('%%PREFIX%%/share/mime/packages',
      [os.path.join(platform_dir, 'miro.xml')]),
-    ('/usr/share/man/man1',
+    ('%%MANPREFIX%%/man/man1',
      [os.path.join(platform_dir, 'miro.1.gz')]),
-    ('/usr/share/man/man1',
+    ('%%MANPREFIX%%/man/man1',
      [os.path.join(platform_dir, 'miro.real.1.gz')]),
-    ('/usr/lib/miro/',
+    ('%%PREFIX%%/libexec/miro',
      [os.path.join(platform_dir, 'xine/xine_extractor')]),
 ]
 
@@ -697,7 +703,7 @@
 
     def install_app_config(self):
         source = os.path.join(resource_dir, 'app.config.template')
-        dest = '/usr/share/miro/resources/app.config'
+        dest = '%%PREFIX%%/share/miro/resources/app.config'
 
         config_file = util.read_simple_config_file(source)
         print "Trying to figure out the svn revision...."
@@ -737,7 +743,7 @@
 
         for source in glob (os.path.join (locale_dir, "*.mo")):
             lang = os.path.basename(source)[:-3]
-            dest = '/usr/share/locale/%s/LC_MESSAGES/miro.mo' % lang
+            dest = '%%PREFIX%%/share/locale/%s/LC_MESSAGES/miro.mo' % lang
             if self.root:
                 dest = change_root(self.root, dest)
             self.mkpath(os.path.dirname(dest))
@@ -766,7 +772,7 @@
 
 #### install_theme installs a specified theme .zip
 class install_theme(Command):
-    description = 'Install a provided theme to /usr/share/miro/themes'
+    description = 'Install a provided theme to %%PREFIX%%/share/miro/themes'
     user_options = [("theme=", None, 'ZIP file containing the theme')]
 
     def initialize_options(self):
@@ -794,7 +800,7 @@
             raise DistutilsOptionError, "invalid theme file"
         self.zipfile = zf
         self.theme_name = themeName
-        self.theme_dir = '/usr/share/miro/themes/%s' % themeName
+        self.theme_dir = '%%PREFIX%%/share/miro/themes/%s' % themeName
 
     def run(self):
         if os.path.exists(self.theme_dir):
