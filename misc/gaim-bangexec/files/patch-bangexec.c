--- bangexec.c.orig	Mon May  9 07:02:52 2005
+++ bangexec.c	Mon May  9 07:03:30 2005
@@ -287,9 +287,10 @@
 		return -1;
     }else if (pid){		//Parent
 		int rv;
+		int flags;
 
 		close (p[1]);
-		int flags = fcntl (p[0], F_GETFL, 0);
+		flags = fcntl (p[0], F_GETFL, 0);
 		fcntl (p[0], F_SETFL, flags | O_NONBLOCK);
 		
 		rv=read_nonblock(p[0],strtoul(BANGEXEC_MAXLEN,NULL,10)-chrs,strtoul(BANGEXEC_TIMEOUT,NULL,10),inp);	
