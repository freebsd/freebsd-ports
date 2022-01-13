--- setup.py.orig	2022-01-12 10:11:02 UTC
+++ setup.py
@@ -113,7 +113,7 @@ if compiler is not None:
         from sysconfig import get_config_vars
 
     # If CC is set then the following hack will not work
-    assert not os.environ.get('CC'), 'Please unset CC'
+    #assert not os.environ.get('CC'), 'Please unset CC'
 
     vars = get_config_vars()
     for key in ['CC', 'LDSHARED']:
