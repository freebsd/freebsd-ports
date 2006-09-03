--- jabberd/mio.c.orig	Wed Nov 12 22:19:08 2003
+++ jabberd/mio.c	Sun Sep  3 09:40:22 2006
@@ -530,6 +530,13 @@
         return NULL;
     }
 
+    /* do not accept a higher fd than FD_SET, or FD_CLR can handle */
+    if (fd >= FD_SETSIZE) {
+       log_warn(NULL, "could not accept incomming connection, maximum number of connections reached (%i)", FD_SETSIZE);
+       close(fd);
+       return NULL;
+    }
+
 #ifdef WITH_IPV6
     allow = _mio_allow_check(inet_ntop(AF_INET6, &serv_addr.sin6_addr, addr_str, sizeof(addr_str)));
     deny = _mio_deny_check(addr_str);
