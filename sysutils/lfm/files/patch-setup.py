--- setup.py.orig	2017-06-25 17:04:03 UTC
+++ setup.py
@@ -37,18 +37,12 @@ Topic :: Utilities
 Topic :: Utilities
 """
 
-print(__doc__)
-
 # check python version
 ver = (version_info.major, version_info.minor)
 if ver < (3, 4):
     print('ERROR: Python 3.4 or higher is required to run lfm.')
     exit(-1)
 
-# to avoid bug in pip 7.x. See https://bitbucket.org/pypa/wheel/issues/92
-if 'bdist_wheel' in argv:
-    raise RuntimeError("This setup.py does not support wheels")
-
 import shutil
 try:
     try:
@@ -71,7 +65,7 @@ try:
           license='GPL3+',
           packages=['lfm'],
           scripts=['lfm/lfm'],
-          data_files=[(join(prefix, 'share/man/man1'), MAN_FILES)],
+          data_files=[('share/man/man1', MAN_FILES)],
           package_data={'': CONFIG_FILES + [join('doc', f) for f in DOC_FILES]},
     )
 finally:
