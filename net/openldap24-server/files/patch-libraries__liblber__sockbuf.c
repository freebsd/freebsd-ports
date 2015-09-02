--- libraries/liblber/sockbuf.c.orig	2015-09-01 16:43:54.707637190 -0600
+++ libraries/liblber/sockbuf.c	2015-09-01 17:16:22.310503263 -0600
@@ -937,8 +937,7 @@
 	buf = (char *) buf + sizeof( struct sockaddr_storage );
 	len -= sizeof( struct sockaddr_storage );
    
-	rc = sendto( sbiod->sbiod_sb->sb_fd, buf, len, 0, dst,
-		sizeof( struct sockaddr_storage ) );
+	rc = sendto( sbiod->sbiod_sb->sb_fd, buf, len, 0, dst, dst->sa_len );
 
 	if ( rc < 0 ) return -1;
    
