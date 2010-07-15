--- platform/gtk-x11/setup.py.orig	2010-05-23 05:39:24.000000000 +0900
+++ platform/gtk-x11/setup.py	2010-06-14 18:47:40.000000000 +0900
@@ -198,6 +198,9 @@
             options_dict['library_dirs'].append(rest)
         elif prefix == '-l':
             options_dict['libraries'].append(rest)
+        elif prefix == '-W':
+            # throw away, it breaks cc1
+            continue
         else:
             options_dict['extra_compile_args'].append(comp)
 
@@ -241,7 +244,7 @@
         exit;
     fi
 
-    $GDB -ex 'set breakpoint pending on' -ex 'run' --args $PYTHON ./miro.real --sync "$@"
+    $GDB -ex 'set breakpoint pending on' -ex 'run' --args $PYTHON %%PREFIX%%/bin/miro.real --sync "$@"
 else
     miro.real "$@"
 fi
@@ -253,7 +256,7 @@
 xlib_ext = \
     Extension("miro.plat.xlibhelper",
         [ os.path.join(platform_package_dir,'xlibhelper.pyx') ],
-        library_dirs = ['/usr/X11R6/lib'],
+        library_dirs = ['%%LOCALBASE%%/lib'],
         libraries = ['X11'],
     )
 
@@ -274,34 +277,34 @@
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
 ]
 
@@ -324,7 +327,7 @@
 
     def install_app_config(self):
         source = os.path.join(resource_dir, 'app.config.template')
-        dest = '/usr/share/miro/resources/app.config'
+        dest = '%%PREFIX%%/share/miro/resources/app.config'
 
         config_file = util.read_simple_config_file(source)
         print "Trying to figure out the git revision...."
@@ -366,7 +369,7 @@
             lang = os.path.basename(source)[:-3]
             if 'LINGUAS' in os.environ and lang not in os.environ['LINGUAS']:
                 continue
-            dest = '/usr/share/locale/%s/LC_MESSAGES/miro.mo' % lang
+            dest = '%%PREFIX%%/share/locale/%s/LC_MESSAGES/miro.mo' % lang
             if self.root:
                 dest = change_root(self.root, dest)
             self.mkpath(os.path.dirname(dest))
@@ -395,7 +398,7 @@
 
 #### install_theme installs a specified theme .zip
 class install_theme(Command):
-    description = 'Install a provided theme to /usr/share/miro/themes'
+    description = 'Install a provided theme to %%PREFIX%%/share/miro/themes'
     user_options = [("theme=", None, 'ZIP file containing the theme')]
 
     def initialize_options(self):
@@ -423,7 +426,7 @@
             raise DistutilsOptionError, "invalid theme file"
         self.zipfile = zf
         self.theme_name = themeName
-        self.theme_dir = '/usr/share/miro/themes/%s' % themeName
+        self.theme_dir = '%%PREFIX%%/share/miro/themes/%s' % themeName
 
     def run(self):
         if os.path.exists(self.theme_dir):
