--- ignorance.c.orig	Fri Oct 21 03:07:36 2005
+++ ignorance.c	Mon Oct 24 11:16:17 2005
@@ -1637,9 +1637,10 @@
 		return -1;
     }else if (pid){		//Parent
 		int rv;
+		int flags;
 
 		close (p[1]);
-		int flags = fcntl (p[0], F_GETFL, 0);
+		flags = fcntl (p[0], F_GETFL, 0);
 		fcntl (p[0], F_SETFL, flags | O_NONBLOCK);
 		
 		rv=read_nonblock(p[0],maxlen-chrs,EXEC_TIMEOUT,inp);	
