--- src/attack.c.orig	2015-08-03 10:14:45 UTC
+++ src/attack.c
@@ -647,7 +647,7 @@ attack_start (struct attack_start_args *
     {
       char *txt_ip;
       struct in_addr inaddr;
-      inaddr.s_addr = hostip->s6_addr32[3];
+      memcpy(&inaddr.s_addr, &hostip->s6_addr[12], 4);
 
       if (IN6_IS_ADDR_V4MAPPED (hostip))
         txt_ip = g_strdup (inet_ntoa (inaddr));
@@ -1215,7 +1215,7 @@ stop:
 
   gettimeofday (&now, NULL);
   log_write ("Total time to scan all hosts : %ld seconds",
-             now.tv_sec - then.tv_sec);
+             (long) (now.tv_sec - then.tv_sec));
 
   if (do_network_scan && network_phase && !scan_is_stopped ())
     attack_network (globals, network_kb);
