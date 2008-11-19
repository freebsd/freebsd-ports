--- scapy/config.py.orig	2008-11-12 05:01:38.000000000 +0800
+++ scapy/config.py	2008-11-12 05:01:59.000000000 +0800
@@ -308,7 +308,7 @@
     services_tcp = TCP_SERVICES
     services_udp = UDP_SERVICES
     extensions_paths = "."
-    manufdb = load_manuf("/usr/share/wireshark/wireshark/manuf")
+    manufdb = load_manuf("%%LOCALBASE%%/share/wireshark/manuf")
     stats_classic_protocols = []
     stats_dot11_protocols = []
     temp_files = []
