--- src/gvmd.c	2020-08-11 10:05:36.000000000 -0500
+++ src/gvmd.c	2021-01-03 16:50:30.707314000 -0500
@@ -1362,6 +1362,7 @@
   struct sockaddr_un address_unix;
   struct sockaddr_storage address_tls;
   int address_size;
+  socklen_t addrlen;
 
   memset (&address_tls, 0, sizeof (struct sockaddr_storage));
   memset (&address_unix, 0, sizeof (struct sockaddr_un));
@@ -1375,9 +1376,8 @@
       /* UNIX file socket. */
 
       address_unix.sun_family = AF_UNIX;
-      strncpy (address_unix.sun_path,
-               address_str_unix,
-               sizeof (address_unix.sun_path) - 1);
+      strcpy (address_unix.sun_path,
+               address_str_unix);
 
       g_debug ("%s: address_unix.sun_path: %s",
                __func__,
@@ -1398,7 +1398,7 @@
         }
 
       address = (struct sockaddr *) &address_unix;
-      address_size = sizeof (address_unix);
+      addrlen = sizeof(struct sockaddr_un);
 
       /* Ensure the path of the socket exists. */
 
@@ -1414,8 +1414,8 @@
     }
   else if (address_str_tls)
     {
-      struct sockaddr_in *addr4;
-      struct sockaddr_in6 *addr6;
+      struct sockaddr_in *addr4 = (struct sockaddr_in *) &address_tls;
+      struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *) &address_tls;
       int port, optval;
 
       /* TLS TCP socket. */
@@ -1440,17 +1440,17 @@
             port = htons (GVMD_PORT);
         }
 
-      addr4 = (struct sockaddr_in *) &address_tls;
-      addr6 = (struct sockaddr_in6 *) &address_tls;
       if (inet_pton (AF_INET6, address_str_tls, &addr6->sin6_addr) > 0)
         {
           address_tls.ss_family = AF_INET6;
           addr6->sin6_port = port;
+	  addrlen = sizeof (*addr6);
         }
       else if (inet_pton (AF_INET, address_str_tls, &addr4->sin_addr) > 0)
         {
           address_tls.ss_family = AF_INET;
           addr4->sin_port = port;
+	  addrlen = sizeof (*addr4);
         }
       else
         {
@@ -1491,7 +1491,7 @@
       return -1;
     }
 
-  if (bind (*soc, address, address_size) == -1)
+  if (bind (*soc, address, addrlen) == -1)
     {
       g_warning ("Failed to bind manager socket: %s", strerror (errno));
       return -1;
