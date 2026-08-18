--- ipaserver/install/dsinstance.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/dsinstance.py
@@ -787,6 +787,9 @@ class DsInstance(service.Service):
             self.serverid
         )
         destdir = os.path.dirname(destfile)
+        if not os.path.isdir("/etc/systemd/system"):
+            logger.debug("Skipping systemd dirsrv IPA environment configuration: /etc/systemd/system not found")
+            return
 
         if not os.path.isdir(destdir):
             # create dirsrv-$SERVERID.service.d
@@ -1149,7 +1152,7 @@ class DsInstance(service.Service):
         # (re)start them.
         for ds_instance in get_ds_instances():
             try:
-                services.knownservices.dirsrv.restart(ds_instance, wait=False)
+                services.knownservices.dirsrv.try_restart(ds_instance, wait=False)
             except Exception as e:
                 logger.error(
                     'Unable to restart DS instance %s: %s', ds_instance, e)
@@ -1189,6 +1192,13 @@ class DsInstance(service.Service):
         if serverid is None:
             serverid = self.get_state("serverid")
         if serverid is not None:
+            dirname = config_dirname(serverid)[:-1]
+            if not os.path.isfile(os.path.join(dirname, "dse.ldif")):
+                logger.debug(
+                    "Directory Server instance %s is already absent",
+                    serverid,
+                )
+                return
             nickname = self.get_server_cert_nickname(serverid)
             # drop the trailing / off the config_dirname so the directory
             # will match what is in certmonger
