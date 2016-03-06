--- setup.py.orig	2016-03-05 09:59:07.250354000 +0100
+++ setup.py	2016-03-05 10:02:48.940832000 +0100
@@ -23,7 +23,6 @@
 import sys
 import os
 from setuptools import setup, Extension
-from setuptools.command.test import test
 from setuptools.command.install import install
 from setuptools.command.sdist import sdist
 from distutils.command.build_scripts import build_scripts
@@ -35,6 +34,9 @@
     sys.exit(1)
 
 incdir_list = libdir_list = None
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
 
 if os.name == 'posix':
     LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
@@ -47,15 +49,9 @@
         incdir_list = [os.path.join(LIBRSYNC_DIR, 'include')]
         libdir_list = [os.path.join(LIBRSYNC_DIR, 'lib')]
 
-data_files = [('share/man/man1',
+data_files = [('man/man1',
                ['bin/duplicity.1',
                 'bin/rdiffdir.1']),
-              ('share/doc/duplicity-%s' % version_string,
-               ['COPYING',
-                'README',
-                'README-REPO',
-                'README-LOG',
-                'CHANGELOG']),
               ]
 
 top_dir = os.path.dirname(os.path.abspath(__file__))
@@ -69,48 +65,9 @@
                 ('share/locale/%s/LC_MESSAGES' % lang,
                  ["po/%s/duplicity.mo" % lang]))
 
-
-class TestCommand(test):
-
-    def run(self):
-        # Make sure all modules are ready
-        build_cmd = self.get_finalized_command("build_py")
-        build_cmd.run()
-        # And make sure our scripts are ready
-        build_scripts_cmd = self.get_finalized_command("build_scripts")
-        build_scripts_cmd.run()
-
-        # make symlinks for test data
-        if build_cmd.build_lib != top_dir:
-            for path in ['testfiles.tar.gz', 'gnupg']:
-                src = os.path.join(top_dir, 'testing', path)
-                target = os.path.join(build_cmd.build_lib, 'testing', path)
-                try:
-                    os.symlink(src, target)
-                except Exception:
-                    pass
-
-        os.environ['PATH'] = "%s:%s" % (
-            os.path.abspath(build_scripts_cmd.build_dir),
-            os.environ.get('PATH'))
-
-        test.run(self)
-
-
 class InstallCommand(install):
 
     def run(self):
-        # Normally, install will call build().  But we want to delete the
-        # testing dir between building and installing.  So we manually build
-        # and mark ourselves to skip building when we run() for real.
-        self.run_command('build')
-        self.skip_build = True
-
-        # This should always be true, but just to make sure!
-        if self.build_lib != top_dir:
-            testing_dir = os.path.join(self.build_lib, 'testing')
-            os.system("rm -rf %s" % testing_dir)
-
         install.run(self)
 
 
@@ -178,11 +135,7 @@
       url="http://duplicity.nongnu.org/index.html",
       packages=['duplicity',
                 'duplicity.backends',
-                'duplicity.backends.pyrax_identity',
-                'testing',
-                'testing.functional',
-                'testing.overrides',
-                'testing.unit'],
+                'duplicity.backends.pyrax_identity'],
       package_dir={"duplicity": "duplicity",
                    "duplicity.backends": "duplicity/backends", },
       ext_modules=[Extension("duplicity._librsync",
@@ -193,10 +146,7 @@
       scripts=['bin/rdiffdir', 'bin/duplicity'],
       data_files=data_files,
       install_requires=['lockfile'],
-      tests_require=['lockfile', 'mock', 'pexpect'],
-      test_suite='testing',
-      cmdclass={'test': TestCommand,
-                'install': InstallCommand,
+      cmdclass={'install': InstallCommand,
                 'sdist': SDistCommand,
                 'build_scripts': BSCommand},
       )
