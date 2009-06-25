--- scapy/config.py.orig	2009-02-09 17:41:39.000000000 +0500
+++ scapy/config.py	2009-06-24 16:11:35.000000000 +0600
@@ -309,7 +309,7 @@
     services_tcp = TCP_SERVICES
     services_udp = UDP_SERVICES
     extensions_paths = "."
-    manufdb = load_manuf("/usr/share/wireshark/manuf")
+    manufdb = load_manuf("%%LOCALBASE%%/share/wireshark/manuf")
     stats_classic_protocols = []
     stats_dot11_protocols = []
     temp_files = []
