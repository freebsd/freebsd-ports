--- nmapfe/nmapfe_sig.c.orig	Mon Oct  6 12:59:49 2003
+++ nmapfe/nmapfe_sig.c	Mon Oct  6 13:00:06 2003
@@ -425,7 +425,7 @@
   if (size > command_size)
     command = realloc(command, size);
 
-  strcpy(command, "nmap ");
+  strcpy(command, NMAP_PATH "nmap ");
  
   /* select the scan type */
   if (opt.scanValue == CONNECT_SCAN) {
