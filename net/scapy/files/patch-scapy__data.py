--- ./scapy/data.py.orig	2010-01-05 11:34:28.000000000 +0100
+++ ./scapy/data.py	2010-01-05 11:35:09.000000000 +0100
@@ -178,7 +178,7 @@
     IP_PROTOS=load_protocols("/etc/protocols")
     ETHER_TYPES=load_ethertypes("/etc/ethertypes")
     TCP_SERVICES,UDP_SERVICES=load_services("/etc/services")
-    MANUFDB = load_manuf("/usr/share/wireshark/wireshark/manuf")
+    MANUFDB = load_manuf("%%LOCALBASE%%/share/wireshark/wireshark/manuf")
 
 
 
