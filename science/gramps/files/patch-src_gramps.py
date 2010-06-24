--- src/gramps.py	2010-03-15 10:21:34.000000000 +0300
+++ src/gramps.py	2010-04-22 00:49:34.000000000 +0400
@@ -69,7 +69,7 @@
 
 if not constfunc.win():
     try:
-        locale.bindtextdomain(TransUtils.LOCALEDOMAIN, TransUtils.LOCALEDIR)
+        gettext.bindtextdomain(TransUtils.LOCALEDOMAIN, TransUtils.LOCALEDIR)
         #locale.textdomain(TransUtils.LOCALEDOMAIN)
     except locale.Error:
         print 'No translation in some gtk.Builder strings, '
