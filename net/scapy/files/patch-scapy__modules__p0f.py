--- ./scapy/modules/p0f.py.orig	2010-01-05 11:36:56.000000000 +0100
+++ ./scapy/modules/p0f.py	2010-01-05 11:37:50.000000000 +0100
@@ -8,10 +8,10 @@
 from scapy.layers.inet import IP, TCP, TCPOptions
 from scapy.packet import NoPayload
 
-conf.p0f_base ="/etc/p0f/p0f.fp"
-conf.p0fa_base ="/etc/p0f/p0fa.fp"
-conf.p0fr_base ="/etc/p0f/p0fr.fp"
-conf.p0fo_base ="/etc/p0f/p0fo.fp"
+conf.p0f_base ="%%LOCALBASE%%/etc/p0f/p0f.fp"
+conf.p0fa_base ="%%LOCALBASE%%/etc/p0f/p0fa.fp"
+conf.p0fr_base ="%%LOCALBASE%%/etc/p0f/p0fr.fp"
+conf.p0fo_base ="%%LOCALBASE%%/etc/p0f/p0fo.fp"
 
 
 ###############
