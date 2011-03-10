--- ./Mailman/Cgi/confirm.py.orig	2010-09-20 14:18:27.000000000 -0400
+++ ./Mailman/Cgi/confirm.py	2011-03-10 09:33:04.506813466 -0500
@@ -471,7 +471,7 @@
     if fullname is None:
         fullname = _('<em>Not available</em>')
     else:
-        fullname = Utils.uncanonstr(fullname, lang)
+        fullname = Utils.websafe(Utils.uncanonstr(fullname, lang))
     table.AddRow([_("""Your confirmation is required in order to complete the
     unsubscription request from the mailing list <em>%(listname)s</em>.  You
     are currently subscribed with
@@ -573,7 +573,7 @@
     if fullname is None:
         fullname = _('<em>Not available</em>')
     else:
-        fullname = Utils.uncanonstr(fullname, lang)
+        fullname = Utils.websafe(Utils.uncanonstr(fullname, lang))
     if globally:
         globallys = _('globally')
     else:
@@ -814,7 +814,7 @@
     if username is None:
         username = _('<em>not available</em>')
     else:
-        username = Utils.uncanonstr(username, lang)
+        username = Utils.websafe(Utils.uncanonstr(username, lang))
 
     table.AddRow([_("""Your membership in the %(realname)s mailing list is
     currently disabled due to excessive bounces.  Your confirmation is
