--- xipshcut.c.orig	Fri Oct 29 05:23:57 1999
+++ xipshcut.c	Mon Nov 15 10:41:54 1999
@@ -27,7 +27,7 @@
   {"",
    "<b>%Timestamp%</b>: %Pat% %ether.shost% %ether.dhost% %ether.Type% %Len%"},
-  {"arp[6:2] = 1",
+  {"arp[7] = 1 && arp[6] = 0",
    "<b>%Timestamp%</b>: arp who-has %arpethip.Tpa% tell %arpethip.Spa%"},
-  {"arp[6:2] = 2",
+  {"arp[7] = 2 && arp[6] = 0",
    "<b>%Timestamp%</b>: %arpethip.Spa% tells %arpethip.Tpa% he has %arpethip.sha%"},
   {"ip",
