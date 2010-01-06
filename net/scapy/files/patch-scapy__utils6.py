--- ./scapy/utils6.py.orig	2010-01-05 11:38:37.000000000 +0100
+++ ./scapy/utils6.py	2010-01-05 11:39:13.000000000 +0100
@@ -267,7 +267,7 @@
     Extract the MAC address from a modified EUI-64 constructed IPv6
     address provided and use the IANA oui.txt file to get the vendor.
     The database used for the conversion is the one loaded by Scapy,
-    based on Wireshark (/usr/share/wireshark/wireshark/manuf)  None
+    based on Wireshark (%%LOCALBASE%%/share/wireshark/wireshark/manuf)  None
     is returned on error, "UNKNOWN" if the vendor is unknown.
     """
     mac = in6_addrtomac(addr)
