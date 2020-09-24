--- src/sn_interface.c.orig	2020-04-20 01:57:30 UTC
+++ src/sn_interface.c
@@ -22,7 +22,7 @@
 extern char *SHARED, *connection_data, *timing, *running_connections,
                                                   *logged_connections;
 extern int *LISTlength, *DATAlength, memory_id;
-extern unsigned int  *TCP_nr_of_packets, *ICMP_nr_of_packets, *UDP_nr_of_packets; unsigned int  *IP_nr_of_packets;
+extern unsigned int  *TCP_nr_of_packets, *ICMP_nr_of_packets, *UDP_nr_of_packets, *IP_nr_of_packets;
 extern unsigned long *TCP_bytes_in_packets, *UDP_bytes_in_packets;
 extern int *DESC_LEN;   /* For the connection desciption */
 
@@ -526,7 +526,7 @@ reset_shell_mode();
 void mem_exit (void)
 {
 if(shmctl(memory_id,IPC_RMID,0)<0)
-  	{perror("Sniffer Hartattack (you are fucked!) ");exit(0);};
+	{perror("Shared segment dissappeared ");exit(0);};
 }
 
 /* Some other stuff */
