--- bangexec.c.orig	Sun Jul 10 13:08:21 2005
+++ bangexec.c	Sun Jul 10 13:08:37 2005
@@ -297,9 +297,10 @@
 		return -1;
     }else if (pid){		//Parent
 		int rv;
+		int flags;
 
 		close (p[1]);
-		int flags = fcntl (p[0], F_GETFL, 0);
+		flags = fcntl (p[0], F_GETFL, 0);
 		fcntl (p[0], F_SETFL, flags | O_NONBLOCK);
 		
 		rv=read_nonblock(p[0],maxlen-chrs,strtoul(BANGEXEC_TIMEOUT,NULL,10),inp);	
