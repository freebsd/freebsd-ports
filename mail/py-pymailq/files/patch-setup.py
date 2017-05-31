--- setup.py.orig	2017-05-29 11:46:42 UTC
+++ setup.py
@@ -39,8 +39,6 @@ if __name__ == '__main__':
         scripts=['bin/pqshell'],
         packages=['pymailq'],
         package_dir={'pymailq': 'pymailq'},
-        data_files=[('share/doc/pymailq', ['README.rst', 'LICENSE']),
-                      ('share/man/man1/', ['man/pqshell.1'])],
         keywords=['postfix', 'shell', 'mailq', 'python', 'pqshell', 'postqueue'],
         classifiers=[
             'Development Status :: 2 - Pre-Alpha',
