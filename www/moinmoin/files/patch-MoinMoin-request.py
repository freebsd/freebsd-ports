--- MoinMoin/request.py.orig	Thu Sep 28 17:21:09 2006
+++ MoinMoin/request.py	Thu Sep 28 17:22:42 2006
@@ -1682,10 +1682,8 @@
             self.http_user_agent = sa.headers.getheader('user-agent', '')            
             co = filter(None, sa.headers.getheaders('cookie'))
             self.saved_cookie = ', '.join(co) or ''
-            self.if_modified_since = (sa.headers.getheader('if-modified-since')
-                                      or self.if_modified_since)
-            self.if_none_match = (sa.headers.getheader('if-none-match')
-                                  or self.if_none_match)
+            self.if_modified_since = sa.headers.getheader('if-modified-since')
+            self.if_none_match = sa.headers.getheader('if-none-match')
             
             # Copy rest from standalone request   
             self.server_name = sa.server.server_name
