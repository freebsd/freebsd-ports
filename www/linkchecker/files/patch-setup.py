--- setup.py.orig	Wed Oct 22 11:25:31 2003
+++ setup.py	Thu Nov 20 02:02:19 2003
@@ -192,12 +192,12 @@
          ('share/locale/nl/LC_MESSAGES',
              ['share/locale/nl/LC_MESSAGES/linkcheck.mo']),
          ('share/linkchecker', ['linkcheckerrc']),
-         ('share/linkchecker/examples',
+         ('share/examples/linkchecker',
              ['lconline/leer.html.en', 'lconline/leer.html.de',
               'lconline/index.html', 'lconline/lc_cgi.html.en',
               'lconline/lc_cgi.html.de', 'lconline/check.js',
               'lc.cgi','lc.fcgi','lc.sz_fcgi','linkchecker.bat']),
-         ('share/man/man1', ['linkchecker.1']),
+         ('man/man1', ['linkchecker.1']),
       ],
       classifiers = [
         'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking',
