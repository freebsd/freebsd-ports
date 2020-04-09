--- setup.py.orig	2020-04-06 16:34:05 UTC
+++ setup.py
@@ -30,7 +30,7 @@ os.chdir(BASE_PATH)
 # inspired by http://dcreager.net/2010/02/10/setuptools-git-version-numbers/
 try:
     print('Attempting to get version number from git...')
-    git = Popen(['git', 'describe', '--always', '--dirty'],
+    git = Popen(['/usr/bin/false', 'describe', '--always', '--dirty'],
                 stdout=PIPE, stderr=sys.stderr)
     if git.wait() != 0:
         raise OSError
@@ -85,13 +85,12 @@ setup(
     name='citeproc-py',
     version=__version__,
     cmdclass = dict(build_py=custom_build_py, develop=custom_develop),
-    packages=find_packages(),
     package_data={PACKAGE: ['data/locales/*.xml',
                             'data/locales/locales.json',
                             'data/schema/*.rng',
                             'data/styles/*.csl']},
     scripts=['bin/csl_unsorted'],
-    setup_requires=['rnc2rng>=2.6.1,!=2.6.2'],
+    setup_requires=['rnc2rng'],
     install_requires=['lxml'],
     provides=[PACKAGE],
     #test_suite='nose.collector',
