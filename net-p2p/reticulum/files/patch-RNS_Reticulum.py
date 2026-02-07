--- RNS/Reticulum.py.orig	2025-05-15 20:24:33 UTC
+++ RNS/Reticulum.py
@@ -165,6 +165,7 @@ class Reticulum:
     # named ".reticulum" inside the current users home directory
     userdir          = os.path.expanduser("~")
     configdir        = None
+    dbdir            = ""
     configpath       = ""
     storagepath      = ""
     cachepath        = ""
@@ -231,8 +232,11 @@ class Reticulum:
         if configdir != None:
             Reticulum.configdir = configdir
         else:
-            if os.path.isdir("/etc/reticulum") and os.path.isfile("/etc/reticulum/config"):
+            if os.path.isdir("/usr/local/etc/reticulum") and os.path.isfile("/usr/local/etc/reticulum/config"):
                 Reticulum.configdir = "/etc/reticulum"
+                Reticulum.interfacepath = Reticulum.configdir+"interfaces"
+            elif os.path.isdir("/etc/reticulum") and os.path.isfile("/etc/reticulum/config"):
+                Reticulum.configdir = "/etc/reticulum"
             elif os.path.isdir(Reticulum.userdir+"/.config/reticulum") and os.path.isfile(Reticulum.userdir+"/.config/reticulum/config"):
                 Reticulum.configdir = Reticulum.userdir+"/.config/reticulum"
             else:
@@ -246,11 +250,8 @@ class Reticulum:
             RNS.logcall = logdest
         
         Reticulum.configpath    = Reticulum.configdir+"/config"
-        Reticulum.storagepath   = Reticulum.configdir+"/storage"
-        Reticulum.cachepath     = Reticulum.configdir+"/storage/cache"
-        Reticulum.resourcepath  = Reticulum.configdir+"/storage/resources"
-        Reticulum.identitypath  = Reticulum.configdir+"/storage/identities"
         Reticulum.interfacepath = Reticulum.configdir+"/interfaces"
+        Reticulum.dbdir         = Reticulum.configdir
 
         Reticulum.__transport_enabled = False
         Reticulum.__link_mtu_discovery = Reticulum.LINK_MTU_DISCOVERY
@@ -291,21 +292,6 @@ class Reticulum:
         self.last_data_persist = time.time()
         self.last_cache_clean = 0
 
-        if not os.path.isdir(Reticulum.storagepath):
-            os.makedirs(Reticulum.storagepath)
-
-        if not os.path.isdir(Reticulum.cachepath):
-            os.makedirs(Reticulum.cachepath)
-
-        if not os.path.isdir(os.path.join(Reticulum.cachepath, "announces")):
-            os.makedirs(os.path.join(Reticulum.cachepath, "announces"))
-
-        if not os.path.isdir(Reticulum.resourcepath):
-            os.makedirs(Reticulum.resourcepath)
-
-        if not os.path.isdir(Reticulum.identitypath):
-            os.makedirs(Reticulum.identitypath)
-
         if not os.path.isdir(Reticulum.interfacepath):
             os.makedirs(Reticulum.interfacepath)
 
@@ -450,6 +436,9 @@ class Reticulum:
         if "reticulum" in self.config:
             for option in self.config["reticulum"]:
                 value = self.config["reticulum"][option]
+                if option == "dbdir":
+                    value = self.config["reticulum"][option]
+                    Reticulum.dbdir = value
                 if option == "share_instance":
                     value = self.config["reticulum"].as_bool(option)
                     self.share_instance = value
@@ -531,6 +520,27 @@ class Reticulum:
         if self.local_socket_path == None and self.use_af_unix:
             self.local_socket_path = "default"
 
+
+        Reticulum.storagepath   = Reticulum.dbdir+"/storage"
+        Reticulum.cachepath     = Reticulum.dbdir+"/storage/cache"
+        Reticulum.resourcepath  = Reticulum.dbdir+"/storage/resources"
+        Reticulum.identitypath  = Reticulum.dbdir+"/storage/identities"
+
+        if not os.path.isdir(Reticulum.storagepath):
+            os.makedirs(Reticulum.storagepath)
+
+        if not os.path.isdir(Reticulum.cachepath):
+            os.makedirs(Reticulum.cachepath)
+
+        if not os.path.isdir(os.path.join(Reticulum.cachepath, "announces")):
+            os.makedirs(os.path.join(Reticulum.cachepath, "announces"))
+
+        if not os.path.isdir(Reticulum.resourcepath):
+            os.makedirs(Reticulum.resourcepath)
+
+        if not os.path.isdir(Reticulum.identitypath):
+            os.makedirs(Reticulum.identitypath)
+
         self.__start_local_interface()
 
         if self.is_shared_instance or self.is_standalone_instance:
@@ -1360,6 +1370,9 @@ __default_rns_config__ = '''# This is the default Reti
 
 
 [reticulum]
+
+# Define database directory
+dbdir = "/var/db/reticulum"
 
 # If you enable Transport, your system will route traffic
 # for other peers, pass announces and serve path requests.
