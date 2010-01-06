--- ./scapy/modules/queso.py.orig	2010-01-05 11:38:01.000000000 +0100
+++ ./scapy/modules/queso.py	2010-01-05 11:38:14.000000000 +0100
@@ -8,7 +8,7 @@
 from scapy.layers.inet import IP,TCP
 #from 
 
-conf.queso_base ="/etc/queso.conf"
+conf.queso_base ="%%LOCALBASE%%/etc/queso.conf"
 
 
 #################
