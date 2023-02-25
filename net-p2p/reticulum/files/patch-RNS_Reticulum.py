--- RNS/Reticulum.py.orig	2022-11-03 16:31:20 UTC
+++ RNS/Reticulum.py
@@ -141,6 +141,7 @@ class Reticulum:
     # named ".reticulum" inside the current users home directory
     userdir          = os.path.expanduser("~")
     configdir        = None
+    dbdir            = ""
     configpath       = ""
     storagepath      = ""
     cachepath        = ""
@@ -181,7 +182,9 @@ class Reticulum:
         if configdir != None:
             Reticulum.configdir = configdir
         else:
-            if os.path.isdir("/etc/reticulum") and os.path.isfile("/etc/reticulum/config"):
+            if os.path.isdir("/usr/local/etc/reticulum") and os.path.isfile("/usr/local/etc/reticulum/config"):
+                Reticulum.configdir = "/usr/local/etc/reticulum"
+            elif os.path.isdir("/etc/reticulum") and os.path.isfile("/etc/reticulum/config"):
                 Reticulum.configdir = "/etc/reticulum"
             elif os.path.isdir(Reticulum.userdir+"/.config/reticulum") and os.path.isfile(Reticulum.userdir+"/.config/reticulum/config"):
                 Reticulum.configdir = Reticulum.userdir+"/.config/reticulum"
@@ -193,10 +196,7 @@ class Reticulum:
             RNS.logfile = Reticulum.configdir+"/logfile"
         
         Reticulum.configpath    = Reticulum.configdir+"/config"
-        Reticulum.storagepath   = Reticulum.configdir+"/storage"
-        Reticulum.cachepath     = Reticulum.configdir+"/storage/cache"
-        Reticulum.resourcepath  = Reticulum.configdir+"/storage/resources"
-        Reticulum.identitypath  = Reticulum.configdir+"/storage/identities"
+        Reticulum.dbdir         = Reticulum.configdir
 
         Reticulum.__transport_enabled = False
         Reticulum.__use_implicit_proof = True
@@ -226,18 +226,6 @@ class Reticulum:
         self.last_data_persist = time.time()
         self.last_cache_clean = 0
 
-        if not os.path.isdir(Reticulum.storagepath):
-            os.makedirs(Reticulum.storagepath)
-
-        if not os.path.isdir(Reticulum.cachepath):
-            os.makedirs(Reticulum.cachepath)
-
-        if not os.path.isdir(Reticulum.resourcepath):
-            os.makedirs(Reticulum.resourcepath)
-
-        if not os.path.isdir(Reticulum.identitypath):
-            os.makedirs(Reticulum.identitypath)
-
         if os.path.isfile(self.configpath):
             try:
                 self.config = ConfigObj(self.configpath)
@@ -253,7 +241,7 @@ class Reticulum:
 
         self.__apply_config()
         RNS.log("Configuration loaded from "+self.configpath, RNS.LOG_VERBOSE)
-        
+
         RNS.Identity.load_known_destinations()
 
         RNS.Transport.start(self)
@@ -345,6 +333,9 @@ class Reticulum:
         if "reticulum" in self.config:
             for option in self.config["reticulum"]:
                 value = self.config["reticulum"][option]
+                if option == "dbdir":
+                    value = self.config["reticulum"][option]
+                    Reticulum.dbdir = value
                 if option == "share_instance":
                     value = self.config["reticulum"].as_bool(option)
                     self.share_instance = value
@@ -369,6 +360,23 @@ class Reticulum:
                     if v == False:
                         Reticulum.__use_implicit_proof = False
 
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
+        if not os.path.isdir(Reticulum.resourcepath):
+            os.makedirs(Reticulum.resourcepath)
+
+        if not os.path.isdir(Reticulum.identitypath):
+            os.makedirs(Reticulum.identitypath)
+
         self.__start_local_interface()
 
         if self.is_shared_instance or self.is_standalone_instance:
@@ -1275,6 +1283,9 @@ __default_rns_config__ = '''# This is the default Reti
 
 
 [reticulum]
+
+# Define the DB directory
+dbdir = "/var/db/reticulum"
 
 # If you enable Transport, your system will route traffic
 # for other peers, pass announces and serve path requests.
