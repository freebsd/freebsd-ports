--- kenosis_setup.py.orig	Fri Jan  7 04:16:32 2005
+++ kenosis_setup.py	Thu Jan 13 00:22:56 2005
@@ -15,7 +15,6 @@
     url = "http://kenosis.sf.net/",
     license = "MIT",
     
-    packages = ["bt", "bt.BitTorrent", "ds", "kenosis", "kenosis.dns"],
+    packages = ["kenosis", "kenosis.ds", "kenosis.dns"],
     )
 
-print("Upload to upload.sf.net/incoming by running: ncftpput upload.sf.net incoming dist/kenosis-%s.tar.gz" % kenosis.version)
