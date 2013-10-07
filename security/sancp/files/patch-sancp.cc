--- sancp.cc.orig	2013-10-04 17:55:19.000000000 +0000
+++ sancp.cc	2013-10-04 17:56:55.000000000 +0000
@@ -271,10 +271,10 @@
 /******************************************************************* 
  * Function for C code to call C++ code (used by pcap_functions.c) * 
  *******************************************************************/
-
+         
 extern "C" void ProcessMyPacket(char *user, struct pcap_pkthdr * pkthdr, u_char * pkt)
 {
-	extern struct gvars gVars;
+	struct gvars gVars;
 	CBuffer *buffer;
 	struct cnx *new_cnx=0;
         gVars.timeptr.tv_sec=pkthdr->ts.tv_sec;
