--- src/uscheduled.c.orig	Tue Mar  4 08:26:56 2003
+++ src/uscheduled.c	Sun Nov  2 21:02:00 2003
@@ -161,9 +161,14 @@
 static iopause_fd iop[1];
 static void fifo_open(void) 
 {
+	static int fd2=-1;
+	if (-1!=fd2) close(fd2);
 	iop[0].fd=open_read("fifo");
 	if (-1==iop[0].fd)
-		xbailout(111,errno,"failed to open fifo",0,0,0);
+		xbailout(111,errno,"failed to open_read fifo",0,0,0);
+	fd2=open_write("fifo");
+	if (-1==fd2)
+		xbailout(111,errno,"failed to open_write fifo",0,0,0);
 	ndelay_on(iop[0].fd);
 	iop[0].events=IOPAUSE_READ;
 }
