--- tcpreplay.c.orig	Wed May 19 13:00:35 1999
+++ tcpreplay.c	Thu Nov  2 17:58:27 2000
@@ -229,8 +229,8 @@
   }
 
   while (write_status < 0) {
-    write_status = write_link_layer((struct link_int *)user, interface,
-				    data,pcap_hdr->caplen);
+    write_status = libnet_write_link_layer((struct libnet_link_int *)user,
+				    interface,data,pcap_hdr->caplen);
 #ifdef DEBUG
     if (debug > 1) {
       fprintf(stderr, "write_status = %i\n", write_status);
@@ -255,7 +255,7 @@
 int main(int argc, char * argv[])
 {
   pcap_t * in_file;
-  struct link_int * write_if;
+  struct libnet_link_int * write_if;
   float Mrate = 0;
   double starttime_local, startusec;
   char ebuf[256];
@@ -327,7 +327,7 @@
   failed_writes  = 0;
   pkts_sent = 0;
   bytes_sent = 0;
-  write_if = open_link_interface(interface,ebuf);
+  write_if = libnet_open_link_interface(interface,ebuf);
   if (write_if <= 0) {
     fprintf(stderr, "output i/f: %s\n",ebuf);
     exit(1);
