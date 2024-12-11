- workaround for https://github.com/equinor/segyio/issues/586

--- setup.py.orig	2024-12-11 05:38:29 UTC
+++ setup.py
@@ -95,7 +95,7 @@ skbuild.setup(
         # supported OS X release 10.9
         '-DCMAKE_OSX_DEPLOYMENT_TARGET=10.9',
     ],
-    cmdclass = { 'test': setuptools.command.test.test },
+    #cmdclass = { 'test': setuptools.command.test.test },
     classifiers = [
         'Development Status :: 5 - Production/Stable',
         'Environment :: Other Environment',
