--- print-snmp.c.orig	1993-04-22 20:40:27 UTC
+++ print-snmp.c
@@ -1045,7 +1045,7 @@ static void init_mib()
   if (!Mib)
     Mib = read_mib("mib.txt");
   if (!Mib)
-    Mib = read_mib("/usr/local/mib/mib.txt");
+    Mib = read_mib("/usr/local/lib/tcpview/mib/mib.txt");
   if (!Mib){
     err_print("Couldn't find mib file\n");
     exit(2);
