--- ./turpial/ui/lang.py.orig	2013-12-19 01:59:58.000000000 +0000
+++ ./turpial/ui/lang.py	2014-02-22 15:28:02.000000000 +0000
@@ -8,8 +8,8 @@
 # Initialize gettext
 gettext_domain = 'turpial'
 # localedir definition in development mode
-if os.path.isdir(os.path.join(os.path.dirname(__file__), '..', 'i18n')):
-    localedir = os.path.realpath(os.path.join(os.path.dirname(__file__), '..', 'i18n'))
+if os.path.isdir(os.path.join('%%PREFIX%%', 'share', 'locale')):
+    localedir = os.path.realpath(os.path.join('%%PREFIX%%', 'share', 'locale'))
     trans = gettext.install(gettext_domain, localedir, unicode=1)
 else:
     trans = gettext.install(gettext_domain, unicode=1)
