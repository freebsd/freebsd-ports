--- sn_interface.c.orig	Thu Jul 16 09:17:10 1998
+++ sn_interface.c	Sat Jul 15 11:44:48 2000
@@ -522,3 +522,3 @@
 if(shmctl(memory_id,IPC_RMID,0)<0)
-  	{perror("Sniffer Hartattack (you are fucked!) ");exit(0);};
+  	{perror("Shared segment dissappeared ");exit(0);};
 }
