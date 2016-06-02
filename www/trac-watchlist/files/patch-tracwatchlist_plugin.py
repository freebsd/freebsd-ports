--- tracwatchlist/plugin.py.orig	2012-04-05 10:15:12 UTC
+++ tracwatchlist/plugin.py
@@ -527,7 +527,7 @@ class WatchlistPlugin(Component):
                     self.set_notify(req, realm, res)
                 db.commit()
             if redirectback and len(new_res) == 1:
-                req.redirect(req.href(realm,new_res[0]))
+                req.redirect(req.href(realm,list(new_res)[0]))
             action = 'view'
 
         elif action == "unwatch":
