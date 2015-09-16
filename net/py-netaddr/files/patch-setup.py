--- setup.py.orig	2015-05-27 06:43:40 UTC
+++ setup.py
@@ -41,6 +41,8 @@ def main():
         version          = release.version,
         install_requires = release.install_requires,
         setup_requires   = release.setup_requires,
+        tests_require    = release.tests_require,
+        test_suite       = release.test_suite,
         options = {
             'build_scripts': {
                 'executable': '/usr/bin/env python',
