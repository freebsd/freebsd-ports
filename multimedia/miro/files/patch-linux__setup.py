--- linux/setup.py.orig	2012-04-30 16:25:50.000000000 +0200
+++ linux/setup.py	2012-05-12 08:50:18.990985060 +0200
@@ -243,7 +243,7 @@
 xlib_ext = \
     Extension("miro.plat.xlibhelper",
         [os.path.join(platform_package_dir, 'xlibhelper.pyx')],
-        library_dirs=['/usr/X11R6/lib'],
+        library_dirs=['/usr/local/lib'],
         libraries=['X11'],
     )
 
@@ -291,7 +291,7 @@
 # filter out app.config.template (which is handled specially)
 files = [f for f in listfiles(resource_dir) \
         if os.path.basename(f) != 'app.config.template']
-data_files.append(('/usr/share/miro/resources/', files))
+data_files.append(('/usr/local/share/miro/resources/', files))
 
 # handle the sub directories.
 for dir in ('searchengines',
@@ -310,7 +310,7 @@
         os.path.join('testdata', 'metadata'),
         os.path.join('testdata', 'locale', 'fr', 'LC_MESSAGES')):
     source_dir = os.path.join(resource_dir, dir)
-    dest_dir = os.path.join('/usr/share/miro/resources/', dir)
+    dest_dir = os.path.join('/usr/local/share/miro/resources/', dir)
     data_files.append((dest_dir, listfiles(source_dir)))
 data_files.append((dest_dir, [os.path.join(resource_dir, 'donate.html')]))
 
@@ -320,7 +320,7 @@
     files = [os.path.join(root, f) for f in files
              if (not f.endswith("~") and not "#" in f)]
     data_files.append((
-        os.path.join('/usr/share/miro/resources/extensions/', extroot),
+        os.path.join('/usr/local/share/miro/resources/extensions/', extroot),
         files))
 
 # add core platform extension files
@@ -329,28 +329,28 @@
     files = [os.path.join(root, f) for f in files
              if (not f.endswith("~") and not "#" in f)]
     data_files.append((
-        os.path.join('/usr/share/miro/resources/extensions/', extroot),
+        os.path.join('/usr/local/share/miro/resources/extensions/', extroot),
         files))
 
 for mem in ["24", "48", "72", "128"]:
     d = os.path.join("icons", "hicolor", "%sx%s" % (mem, mem), "apps")
     source = os.path.join(platform_dir, d, "miro.png")
-    dest = os.path.join("/usr/share/", d)
+    dest = os.path.join("/usr/local/share/", d)
     data_files.append((dest, [source]))
 
 # add the desktop file, mime data, and man page
 data_files += [
-    ('/usr/share/miro/resources',
+    ('/usr/local/share/miro/resources',
      [os.path.join(root_dir, 'CREDITS')]),
-    ('/usr/share/pixmaps',
+    ('/usr/local/share/pixmaps',
      glob(os.path.join(platform_dir, 'miro.xpm'))),
-    ('/usr/share/applications',
+    ('/usr/local/share/applications',
      [os.path.join(platform_dir, 'miro.desktop')]),
-    ('/usr/share/mime/packages',
+    ('/usr/local/share/mime/packages',
      [os.path.join(platform_dir, 'miro.xml')]),
-    ('/usr/share/man/man1',
+    ('/usr/local/man/man1',
      [os.path.join(platform_dir, 'miro.1.gz')]),
-    ('/usr/share/man/man1',
+    ('/usr/local/man/man1',
      [os.path.join(platform_dir, 'miro.real.1.gz')]),
 ]
 
@@ -376,7 +376,7 @@
 
     def install_app_config(self):
         source = os.path.join(resource_dir, 'app.config.template')
-        dest = '/usr/share/miro/resources/app.config'
+        dest = '/usr/local/share/miro/resources/app.config'
 
         config_file = buildutils.read_simple_config_file(source)
         print "Trying to figure out the git revision...."
@@ -418,7 +418,7 @@
             lang = os.path.basename(source)[:-3]
             if 'LINGUAS' in os.environ and lang not in os.environ['LINGUAS']:
                 continue
-            dest = '/usr/share/locale/%s/LC_MESSAGES/miro.mo' % lang
+            dest = '/usr/local/share/locale/%s/LC_MESSAGES/miro.mo' % lang
             if self.root:
                 dest = change_root(self.root, dest)
             self.mkpath(os.path.dirname(dest))
@@ -438,7 +438,9 @@
         cc.add_library('avcodec')
         # Fedora places ffmpeg include into this directory rather than
         # root /usr/include.
-        cc.add_include_dir('/usr/include/ffmpeg')
+        cc.add_include_dir('/usr/local/include')
+        cc.add_include_dir('/usr/local/include/ffmpeg')
+        cc.add_library_dir('/usr/local/lib')
         output_dir = os.path.join(self.build_base, 'miro-segmenter')
         segmenter_objs = cc.compile([segmenter_src],
                                     output_dir=output_dir,
@@ -449,7 +451,7 @@
         self.distribution.scripts.append(segmenter_exe)
 
     def build_echoprint_codegen(self):
-        subprocess.check_call('/usr/bin/make', cwd=echoprint_src_dir)
+        subprocess.check_call('/usr/local/bin/gmake', cwd=echoprint_src_dir)
         src_binary = os.path.join(echoprint_dir, 'echoprint-codegen')
         dest_dir = os.path.join(self.build_base, 'echoprint-codegen')
         dest_binary = os.path.join(dest_dir, 'echoprint-codegen')
@@ -488,7 +490,7 @@
 
 #### install_theme installs a specified theme .zip
 class install_theme(Command):
-    description = 'Install a provided theme to /usr/share/miro/themes'
+    description = 'Install a provided theme to /usr/local/share/miro/themes'
     user_options = [("theme=", None, 'ZIP file containing the theme')]
 
     def initialize_options(self):
@@ -516,7 +518,7 @@
             raise DistutilsOptionError("invalid theme file")
         self.zipfile = zf
         self.theme_name = themeName
-        self.theme_dir = '/usr/share/miro/themes/%s' % themeName
+        self.theme_dir = '/usr/local/share/miro/themes/%s' % themeName
 
     def run(self):
         if os.path.exists(self.theme_dir):
