--- setup.py.orig	Thu Jan 29 19:14:40 2004
+++ setup.py	Tue Feb  3 09:42:34 2004
@@ -194,13 +194,13 @@
          ('share/locale/nl/LC_MESSAGES',
              ['share/locale/nl/LC_MESSAGES/linkcheck.mo']),
          ('share/linkchecker', ['linkcheckerrc']),
-         ('share/linkchecker/examples',
+         ('share/examples/linkchecker',
              ['lconline/leer.html.en', 'lconline/leer.html.de',
               'lconline/index.html', 'lconline/lc_cgi.html.en',
               'lconline/lc_cgi.html.de', 'lconline/check.js',
               'lc.cgi', 'lc.fcgi', 'lc.sz_fcgi', 'linkchecker.bat',
               'linkchecker-completion', 'linkcheck-cron.sh']),
-         ('share/man/man1', ['linkchecker.1']),
+         ('man/man1', ['linkchecker.1']),
       ],
       classifiers = [
         'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking',
