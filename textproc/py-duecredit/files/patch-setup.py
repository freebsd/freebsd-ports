--- setup.py.orig	2018-05-14 00:01:07 UTC
+++ setup.py
@@ -39,7 +39,7 @@ try:
                                   list(filter(lambda x: x.startswith(' -- '), lines))[0].rstrip())
     else:
         print('Attempting to get version number from git...')
-        git = Popen(['git', 'describe', '--abbrev=4', '--dirty'],
+        git = Popen(['false', 'describe', '--abbrev=4', '--dirty'],
                     stdout=PIPE, stderr=sys.stderr)
         if git.wait() != 0:
             raise OSError
