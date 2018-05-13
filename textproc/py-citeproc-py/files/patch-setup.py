--- setup.py.orig	2017-06-23 13:08:27 UTC
+++ setup.py
@@ -29,7 +29,7 @@ os.chdir(BASE_PATH)
 # inspired by http://dcreager.net/2010/02/10/setuptools-git-version-numbers/
 try:
     print('Attempting to get version number from git...')
-    git = Popen(['git', 'describe', '--always', '--dirty'],
+    git = Popen(['/usr/bin/false', 'describe', '--always', '--dirty'],
                 stdout=PIPE, stderr=sys.stderr)
     if git.wait() != 0:
         raise OSError
@@ -85,7 +85,6 @@ setup(
     name='citeproc-py',
     version=__version__,
     cmdclass = dict(build_py=custom_build_py, develop=custom_develop),
-    packages=find_packages(),
     package_data={PACKAGE: ['data/locales/*.xml',
                             'data/schema/*.rng',
                             'data/styles/*.csl']},
