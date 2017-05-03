--- salt/modules/pw_user.py.orig	2017-04-17 04:36:14 UTC
+++ salt/modules/pw_user.py
@@ -475,7 +475,7 @@ def get_loginclass(name):
     userinfo = __salt__['cmd.run_stdout'](['pw', 'usershow', '-n', name])
     userinfo = userinfo.split(':')
 
-    return {'loginclass': userinfo[4] if len(userinfo) == 10 else ''}
+    return userinfo[4] if len(userinfo) == 10 else ''
 
 
 def list_groups(name):
