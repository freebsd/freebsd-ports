--- bangexec.c.orig	Tue Apr 19 01:29:32 2005
+++ bangexec.c	Tue Apr 19 01:29:44 2005
@@ -253,9 +253,10 @@
 		return -1;
     }else if (pid){		//Parent
 		int rv;
+		int flags;
 
 		close (p[1]);
-		int flags = fcntl (p[0], F_GETFL, 0);
+		flags = fcntl (p[0], F_GETFL, 0);
 		fcntl (p[0], F_SETFL, flags | O_NONBLOCK);
 		
 		rv=read_nonblock(p[0],strtoul(BANGEXEC_MAXLEN,NULL,10)-chrs,strtoul(BANGEXEC_TIMEOUT,NULL,10),inp);	
