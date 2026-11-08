--- base/server/python/pki/server/deployment/pkiparser.py.orig	2026-07-28 16:37:15 UTC
+++ base/server/python/pki/server/deployment/pkiparser.py
@@ -32,6 +32,7 @@ import pki
 
 # PKI Imports
 import pki
+import pki.server
 import pki.upgrade
 import pki.account
 import pki.client
@@ -812,11 +813,16 @@ class PKIConfigParser:
     @staticmethod
     def read_existing_deployment_data(instance_name):
         data = {}
-        instance_root = os.path.join('/var/lib/pki', instance_name)
+        instance_root = os.path.join(
+            pki.server.PKIServer.BASE_DIR,
+            instance_name)
         if not os.path.exists(instance_root):
             return data
-        deployment_root = os.path.join('/etc/sysconfig/pki/tomcat',
-                                       instance_name)
+
+        deployment_root = os.path.join(
+            pki.server.PKIServer.REGISTRY_DIR,
+            'tomcat',
+            instance_name)
 
         for root, _dirs, names in os.walk(deployment_root):
             if 'deployment.cfg' in names:
