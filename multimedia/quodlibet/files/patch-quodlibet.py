--- quodlibet.py.orig	2005-12-12 15:43:59.000000000 -0700
+++ quodlibet.py	2006-01-07 11:25:44.773179056 -0700
@@ -273,15 +273,15 @@
             basedir = os.getcwd()
     if basedir.endswith("/share/quodlibet"):
         sys.path.append(basedir[:-15] + "lib/quodlibet")
-    i18ndir = "/usr/share/locale"
+    i18ndir = "/usr/X11R6/share/locale"
 
     import locale, gettext, util
     try: locale.setlocale(locale.LC_ALL, '')
     except: pass
 
-    gettext.bindtextdomain("quodlibet")
+    gettext.bindtextdomain("quodlibet", i18ndir)
     gettext.textdomain("quodlibet")
-    util.gettext_install("quodlibet", unicode=True)
+    util.gettext_install("quodlibet", i18ndir, unicode=True)
     util.ctypes_init()
 
     from util import to
