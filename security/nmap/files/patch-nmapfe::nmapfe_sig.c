--- nmapfe/nmapfe_sig.c	Mon Jun 30 18:23:48 2003
+++ nmapfe/nmapfe_sig.c.new	Mon Jun 30 18:26:03 2003
@@ -372,7 +372,7 @@
   if (size > command_size)
     command = realloc(command, size);
 
-  strcpy(command, "nmap ");
+  strcpy(command, NMAP_PATH "nmap ");
  
   /* select the scan type */
   if (opt.scanValue == CONNECT_SCAN) {