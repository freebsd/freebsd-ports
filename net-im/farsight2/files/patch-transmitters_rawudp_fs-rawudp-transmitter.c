--- transmitters/rawudp/fs-rawudp-transmitter.c.orig	2009-08-01 16:45:45.000000000 -0400
+++ transmitters/rawudp/fs-rawudp-transmitter.c	2009-08-01 16:46:50.000000000 -0400
@@ -603,8 +603,10 @@ _bind_port (
     GST_WARNING ( "could not set TOS: %s", g_strerror (errno));
 
   prio = 6;
+#ifdef SO_PRIORITY
   if (setsockopt (sock, SOL_SOCKET, SO_PRIORITY, &prio, sizeof (tos)) < 0)
     GST_WARNING ( "could not set socket priority: %s", g_strerror (errno));
+#endif
 
   return sock;
 }
