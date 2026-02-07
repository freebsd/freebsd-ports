--- src/sn_interface.c.orig	2025-09-22 23:50:28 UTC
+++ src/sn_interface.c
@@ -535,7 +535,7 @@ if(shmctl(memory_id,IPC_RMID,0)<0)
 void mem_exit (void)
 {
 if(shmctl(memory_id,IPC_RMID,0)<0)
-  	{perror("Sniffer Hartattack (you are fucked!) ");exit(0);};
+	{perror("Shared segment dissappeared ");exit(0);};
 }
 
 /* Some other stuff */
