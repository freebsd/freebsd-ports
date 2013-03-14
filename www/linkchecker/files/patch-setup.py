--- setup.py.orig
+++ setup.py
@@ -326,15 +326,6 @@
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
@@ -385,7 +376,6 @@
 
     def run (self):
         """Adjust permissions on POSIX systems."""
-        self.add_message_files()
         super(MyInstallData, self).run()
         self.fix_permissions()
 
@@ -583,7 +573,6 @@
     def run (self):
         """Check MANIFEST and build message files before building."""
         check_manifest()
-        self.build_message_files()
         build.run(self)
 
 
@@ -627,8 +616,6 @@
 if os.name == 'nt':
     # windows does not have unistd.h
     define_macros.append(('YY_NO_UNISTD_H', None))
-else:
-    extra_compile_args.append("-pedantic")
 
 myname = "Bastian Kleineidam"
 myemail = "bastian.kleineidam@web.de"
@@ -898,9 +885,6 @@
         'py2app': MyPy2app,
         'register': MyRegister,
     },
-    package_dir = {
-        'linkcheck_dns.dns': 'third_party/dnspython/dns',
-    },
     packages = [
         'linkcheck',
         'linkcheck.bookmarks',
@@ -913,10 +897,6 @@
         'linkcheck.HtmlParser',
         'linkcheck.logger',
         'linkcheck.network',
-        'linkcheck_dns.dns',
-        'linkcheck_dns.dns.rdtypes',
-        'linkcheck_dns.dns.rdtypes.ANY',
-        'linkcheck_dns.dns.rdtypes.IN',
     ],
     ext_modules = [
         Extension('linkcheck.HtmlParser.htmlsax',
@@ -941,7 +921,6 @@
         ),
     ],
     scripts = scripts,
-    data_files = data_files,
     classifiers = [
         'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking',
         'Development Status :: 5 - Production/Stable',
