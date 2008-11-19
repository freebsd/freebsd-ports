--- scapy/utils6.py.orig	2008-11-12 05:06:52.000000000 +0800
+++ scapy/utils6.py	2008-11-12 05:07:08.000000000 +0800
@@ -194,7 +194,7 @@
     Extract the MAC address from a modified EUI-64 constructed IPv6
     address provided and use the IANA oui.txt file to get the vendor.
     The database used for the conversion is the one loaded by Scapy,
-    based on Wireshark (/usr/share/wireshark/wireshark/manuf)  None
+    based on Wireshark (%%LOCALBASE%%/share/wireshark/manuf)  None
     is returned on error, "UNKNOWN" if the vendor is unknown.
     """
     mac = in6_addrtomac(addr)
