--- RNS/Utilities/rnsd.py.orig	2025-05-15 20:24:33 UTC
+++ RNS/Utilities/rnsd.py
@@ -93,6 +93,9 @@ __example_rns_config__ = '''# This is an example Retic
 
 [reticulum]
 
+# Define database directory
+dbdir = "/var/db/reticulum"
+
 # If you enable Transport, your system will route traffic
 # for other peers, pass announces and serve path requests.
 # This should be done for systems that are suited to act
