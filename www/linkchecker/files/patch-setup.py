--- setup.py.orig
+++ setup.py
@@ -328,15 +328,6 @@
 class MyInstallLib (install_lib, object):
     """Custom library installation."""
 
-    def install (self):
-        """Install the generated config file."""
-        outs = super(MyInstallLib, self).install()
-        infile = self.create_conf_file()
-        outfile = os.path.join(self.install_dir, os.path.basename(infile))
-        self.copy_file(infile, outfile)
-        outs.append(outfile)
-        return outs
-
     def create_conf_file (self):
         """Create configuration file."""
         cmd_obj = self.distribution.get_command_obj("install")
@@ -390,7 +381,6 @@
 
     def run (self):
         """Adjust permissions on POSIX systems."""
-        self.add_message_files()
         super(MyInstallData, self).run()
         self.fix_permissions()
 
@@ -588,7 +578,6 @@
     def run (self):
         """Check MANIFEST and build message files before building."""
         check_manifest()
-        self.build_message_files()
         build.run(self)
 
 
@@ -632,8 +621,6 @@
 if os.name == 'nt':
     # windows does not have unistd.h
     define_macros.append(('YY_NO_UNISTD_H', None))
-else:
-    extra_compile_args.append("-pedantic")
 
 if sys.platform == 'darwin':
     define_macros.extend([('HAVE_STRLCPY', None), ('HAVE_STRLCAT', None)])
@@ -900,9 +887,6 @@
         'py2exe': MyPy2exe,
         'py2app': MyPy2app,
     },
-    package_dir = {
-        'linkcheck_dns.dns': 'third_party/dnspython/dns',
-    },
     packages = [
         'linkcheck',
         'linkcheck.bookmarks',
@@ -917,10 +901,6 @@
         'linkcheck.network',
         'linkcheck.parser',
         'linkcheck.plugins',
-        'linkcheck_dns.dns',
-        'linkcheck_dns.dns.rdtypes',
-        'linkcheck_dns.dns.rdtypes.ANY',
-        'linkcheck_dns.dns.rdtypes.IN',
     ],
     ext_modules = [
         Extension('linkcheck.HtmlParser.htmlsax',
@@ -945,7 +925,6 @@
         ),
     ],
     scripts = scripts,
-    data_files = data_files,
     classifiers = [
         'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking',
         'Development Status :: 5 - Production/Stable',
