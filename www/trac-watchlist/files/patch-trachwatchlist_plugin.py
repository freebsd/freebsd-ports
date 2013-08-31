--- tracwatchlist/plugin.py.orig	2013-08-30 19:07:32.000000000 +0800
+++ tracwatchlist/plugin.py	2013-08-30 19:08:43.000000000 +0800
@@ -527,7 +527,7 @@
                     self.set_notify(req, realm, res)
                 db.commit()
             if redirectback and len(new_res) == 1:
-                req.redirect(req.href(realm,new_res[0]))
+                req.redirect(req.href(realm,list(new_res)[0]))
             action = 'view'
 
         elif action == "unwatch":
