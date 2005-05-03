--- pbx/pbx_wilcalu.c.orig	Tue Apr 26 10:00:28 2005
+++ pbx/pbx_wilcalu.c	Tue Apr 26 10:03:42 2005
@@ -82,6 +82,11 @@
 		fds[0].events = POLLIN;
 		poll(fds, 1, -1);
 		bytes=read(fd,buf,256);
+		if (bytes <= 0) {
+			/* XXX error on device, sleep a bit before retrying */
+			sleep(1);
+			continue;
+		}
 		buf[(int)bytes]=0;
 
 		if(bytes>0){
