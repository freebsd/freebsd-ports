--- setup.py.orig	Mon Sep 20 11:05:17 2004
+++ setup.py	Wed Oct 13 09:54:32 2004
@@ -234,13 +234,13 @@
              ['share/locale/nl/LC_MESSAGES/linkchecker.mo']),
          ('share/linkchecker', ['config/linkcheckerrc',
                                 'config/logging.conf', ]),
-         ('share/linkchecker/examples',
+         ('share/examples/linkchecker',
              ['cgi/lconline/leer.html.en', 'cgi/lconline/leer.html.de',
               'cgi/lconline/index.html', 'cgi/lconline/lc_cgi.html.en',
               'cgi/lconline/lc_cgi.html.de', 'cgi/lconline/check.js',
               'cgi/lc.cgi', 'cgi/lc.fcgi',
               'config/linkchecker-completion', 'config/linkcheck-cron.sh']),
-         ('share/man/man1', ['linkchecker.1']),
+         ('man/man1', ['linkchecker.1']),
       ],
       classifiers = [
         'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking',
