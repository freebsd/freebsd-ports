--- src/gvmd.c	2023-09-08 08:33:54.000000000 -0500
+++ src/gvmd.c	2023-09-20 22:04:48.265160000 -0500
@@ -1558,6 +1558,9 @@
   struct sockaddr_un address_unix;
   struct sockaddr_storage address_tls;
   int address_size;
+#if defined(__FreeBSD__)
+  socklen_t addrlen;
+#endif
 
   memset (&address_tls, 0, sizeof (struct sockaddr_storage));
   memset (&address_unix, 0, sizeof (struct sockaddr_un));
@@ -1571,10 +1574,14 @@
       /* UNIX file socket. */
 
       address_unix.sun_family = AF_UNIX;
+#if defined(__FreeBSD__)
+      strcpy (address_unix.sun_path,                                    
+               address_str_unix);
+#else
       strncpy (address_unix.sun_path,
                address_str_unix,
                sizeof (address_unix.sun_path) - 1);
-
+#endif
       g_debug ("%s: address_unix.sun_path: %s",
                __func__,
                address_unix.sun_path);
@@ -1594,7 +1601,11 @@
         }
 
       address = (struct sockaddr *) &address_unix;
+#if defined(__FreeBSD__)
+      addrlen = sizeof(struct sockaddr_un);
+#else
       address_size = sizeof (address_unix);
+#endif
 
       /* Ensure the path of the socket exists. */
 
@@ -1610,8 +1621,9 @@
     }
   else if (address_str_tls)
     {
-      struct sockaddr_in *addr4;
-      struct sockaddr_in6 *addr6;
+      struct sockaddr_in *addr4 = (struct sockaddr_in *) &address_tls;
+      struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *) &address_tls;
+
       int port, optval;
 
       /* TLS TCP socket. */
@@ -1636,17 +1648,21 @@
             port = htons (GVMD_PORT);
         }
 
-      addr4 = (struct sockaddr_in *) &address_tls;
-      addr6 = (struct sockaddr_in6 *) &address_tls;
       if (inet_pton (AF_INET6, address_str_tls, &addr6->sin6_addr) > 0)
         {
           address_tls.ss_family = AF_INET6;
           addr6->sin6_port = port;
+#if defined(__FreeBSD__)
+          addrlen = sizeof (*addr6);
+#endif
         }
       else if (inet_pton (AF_INET, address_str_tls, &addr4->sin_addr) > 0)
         {
           address_tls.ss_family = AF_INET;
           addr4->sin_port = port;
+#if defined(__FreeBSD__)
+          addrlen = sizeof (*addr4);
+#endif
         }
       else
         {
@@ -1687,7 +1703,11 @@
       return -1;
     }
 
+#if defined(__FreeBSD__)
+  if (bind (*soc, address, addrlen) == -1)
+#else
   if (bind (*soc, address, address_size) == -1)
+#endif
     {
       g_warning ("Failed to bind manager socket: %s", strerror (errno));
       return -1;
@@ -2378,7 +2398,9 @@
 
   /* Set process title. */
 
+#if !defined(__FreeBSD__)
   setproctitle_init (argc, argv, env);
+#endif
   setproctitle ("Initializing");
 
   /* Setup initial signal handlers. */
