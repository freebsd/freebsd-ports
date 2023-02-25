--- RNS/Utilities/rnsd.py.orig	2023-02-23 17:25:44 UTC
+++ RNS/Utilities/rnsd.py
@@ -80,6 +80,9 @@ __example_rns_config__ = '''# This is an example Retic
 
 [reticulum]
 
+# Define the DB directory
+dbdir = "/var/db/reticulum"
+
 # If you enable Transport, your system will route traffic
 # for other peers, pass announces and serve path requests.
 # This should be done for systems that are suited to act
