--- base/pcap-snoop.c.orig	2008-01-29 21:40:43.000000000 +0600
+++ base/pcap-snoop.c	2008-01-29 21:40:51.000000000 +0600
@@ -206,7 +206,7 @@
 
     signal(SIGINT,sig_handler);
     
-    while((c=getopt(argc,argv,"vr:f:S:Ttai:k:p:nsAxXhHVNdqem:P"))!=EOF){
+    while((c=getopt(argc,argv,"vr:f:S:yTtai:k:p:nsAxXhHVNdqem:P"))!=EOF){
       switch(c){
         case 'v':
           print_version();
