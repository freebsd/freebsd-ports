--- src/libnids.c.orig	Tue Oct  9 21:13:12 2001
+++ src/libnids.c	Tue Oct  9 21:13:38 2001
@@ -369,6 +369,9 @@
       return 0;
   }
   switch ((linktype = pcap_datalink(desc))) {
+  case DLT_NULL:
+    linkoffset = 4;
+    break;
   case DLT_EN10MB:
     linkoffset = 14;
     break;
