--- setup.py.orig	2018-03-06 17:14:54 UTC
+++ setup.py
@@ -39,11 +39,11 @@ if __name__ == '__main__':
         scripts=['bin/pqshell'],
         packages=['pymailq'],
         package_dir={'pymailq': 'pymailq'},
-        data_files=[('share/doc/pymailq', ['README.rst', 'LICENSE', 'CHANGES']),
-                    ('share/doc/pymailq/examples', [
+        data_files=[('%%DOCSDIR%%', ['README.rst', 'LICENSE', 'CHANGES']),
+                    ('%%EXAMPLESDIR%%', [
                         'share/doc/examples/pymailq.ini'
                     ]),
-                    ('share/man/man1', ['man/pqshell.1'])],
+                    ('%%MANPREFIX%%/man/man1', ['man/pqshell.1'])],
         keywords=['postfix', 'shell', 'mailq', 'python', 'pqshell', 'postqueue'],
         classifiers=[
             'Development Status :: 5 - Production/Stable',
