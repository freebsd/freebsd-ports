--- setup.py.orig	2019-07-25 14:48:21 UTC
+++ setup.py
@@ -23,7 +23,6 @@
 import sys
 import os
 from setuptools import setup, Extension
-from setuptools.command.test import test
 from setuptools.command.install import install
 from setuptools.command.sdist import sdist
 from distutils.command.build_scripts import build_scripts
@@ -50,12 +49,6 @@ if os.name == u'posix':
 data_files = [(u'share/man/man1',
                [u'bin/duplicity.1',
                 u'bin/rdiffdir.1']),
-              (u'share/doc/duplicity-%s' % version_string,
-               [u'COPYING',
-                u'README',
-                u'README-REPO',
-                u'README-LOG',
-                u'CHANGELOG']),
               ]
 
 top_dir = os.path.dirname(os.path.abspath(__file__))
@@ -79,47 +72,9 @@ else:
     ext_modules = []
 
 
-class TestCommand(test):
-
-    def run(self):
-        # Make sure all modules are ready
-        build_cmd = self.get_finalized_command(u"build_py")
-        build_cmd.run()
-        # And make sure our scripts are ready
-        build_scripts_cmd = self.get_finalized_command(u"build_scripts")
-        build_scripts_cmd.run()
-
-        # make symlinks for test data
-        if build_cmd.build_lib != top_dir:
-            for path in [u'testfiles.tar.gz', u'gnupg']:
-                src = os.path.join(top_dir, u'testing', path)
-                target = os.path.join(build_cmd.build_lib, u'testing', path)
-                try:
-                    os.symlink(src, target)
-                except Exception:
-                    pass
-
-        os.environ[u'PATH'] = u"%s:%s" % (
-            os.path.abspath(build_scripts_cmd.build_dir),
-            os.environ.get(u'PATH'))
-
-        test.run(self)
-
-
 class InstallCommand(install):
 
     def run(self):
-        # Normally, install will call build().  But we want to delete the
-        # testing dir between building and installing.  So we manually build
-        # and mark ourselves to skip building when we run() for real.
-        self.run_command(u'build')
-        self.skip_build = True
-
-        # This should always be true, but just to make sure!
-        if self.build_lib != top_dir:
-            testing_dir = os.path.join(self.build_lib, u'testing')
-            os.system(u"rm -rf %s" % testing_dir)
-
         install.run(self)
 
 
@@ -186,21 +141,14 @@ setup(name=u"duplicity",
     url=u"http://duplicity.nongnu.org/index.html",
     packages=[u'duplicity',
               u'duplicity.backends',
-              u'duplicity.backends.pyrax_identity',
-              u'testing',
-              u'testing.functional',
-              u'testing.overrides',
-              u'testing.unit'],
+              u'duplicity.backends.pyrax_identity'],
     package_dir={u"duplicity": u"duplicity",
                  u"duplicity.backends": u"duplicity/backends", },
     ext_modules=ext_modules,
     scripts=[u'bin/rdiffdir', u'bin/duplicity'],
     data_files=data_files,
     install_requires=[u'fasteners', u'future'],
-    tests_require=[u'pytest', u'pytest-runner', u'fasteners', u'future', u'mock', u'pexpect'],
-    test_suite=u'testing',
-    cmdclass={u'test': TestCommand,
-              u'install': InstallCommand,
+    cmdclass={u'install': InstallCommand,
               u'sdist': SDistCommand,
               u'build_scripts': BSCommand},
     classifiers=[u"Programming Language :: Python :: 2",
