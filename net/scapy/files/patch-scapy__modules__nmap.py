--- ./scapy/modules/nmap.py.orig	2010-01-05 11:35:33.000000000 +0100
+++ ./scapy/modules/nmap.py	2010-01-05 11:36:28.000000000 +0100
@@ -13,7 +13,7 @@
 if WINDOWS:
     conf.nmap_base=os.environ["ProgramFiles"] + "\\nmap\\nmap-os-fingerprints"
 else:
-    conf.nmap_base ="/usr/share/nmap/nmap-os-fingerprints"
+    conf.nmap_base ="%%LOCALBASE%%/share/nmap/nmap-os-fingerprints"
 
 
 ######################
