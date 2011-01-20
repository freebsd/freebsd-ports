--- isdcore/sockets-kq.cpp.orig	2011-01-20 14:15:51.000000000 +0100
+++ isdcore/sockets-kq.cpp	2011-01-20 14:16:45.000000000 +0100
@@ -58,7 +58,7 @@
 void process_socket()
 {
    int i;
-   unsigned int udata_index = 0;
+   uintptr_t udata_index = 0;
    
    pack_processed = 0;		/* number of processed by server packets  */
    Packet upacket;		/* udp socket processor temporal packet   */
@@ -86,7 +86,7 @@
 
       for(i = 0; i < nsockets; i++)
       {
-         udata_index = (unsigned int)sock_kev[i].udata;
+         udata_index = (uintptr_t)sock_kev[i].udata;
 	 
          /* socket errors handler */
          if(sock_kev[i].flags & EV_ERROR)
