--- bgpd/bgp_packet.c.orig	Mon Nov 22 15:31:07 2004
+++ bgpd/bgp_packet.c	Mon Nov 22 15:31:40 2004
@@ -566,17 +566,22 @@
   while (1)
     {
       int writenum;
+      int val;
 
       s = bgp_write_packet (peer);
       if (! s)
 	return 0;
 
+      val = fcntl (peer->fd, F_GETFL, 0);
+      fcntl (peer->fd, F_SETFL, val|O_NONBLOCK);
+
       /* Number of bytes to be sent.  */
       writenum = stream_get_endp (s) - stream_get_getp (s);
 
       /* Call write() system call.  */
       num = write (peer->fd, STREAM_PNT (s), writenum);
       write_errno = errno;
+      fcntl (peer->fd, F_SETFL, val);
       if (num <= 0)
 	{
 	  /* Partial write. */
