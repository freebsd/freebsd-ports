--- src/daemon.c.orig	Tue Jul 10 11:52:32 2001
+++ src/daemon.c	Tue Jul 10 11:53:33 2001
@@ -661,7 +661,7 @@
   union sockaddr_46 sin;
 
   #if HAVE_IPV6
-  struct in6_addr anyaddr6 = IN6ADDR_ANY_INIT;
+  struct in6_addr anyaddr6 = in6addr_any;
   #endif
 
   /* Find the standard SMTP port if no port number given; otherwise
@@ -690,7 +690,11 @@
     }
 
   /* Otherwise set up one address item with a null address, implying listening
-  on all interfaces. */
+  on all interfaces. In an IPv6 world, we set up a second address for listening
+  on all IPv6 interfaces. Some IPv6 stacks will pick up incoming IPv4 calls on
+  an IPv6 wildcard socket, but some won't (there are security issues). Using
+  two sockets should work in all cases. We identify an IPv6 wildcard address by
+  the string ":". */
 
   else
     {
@@ -698,6 +702,13 @@
     addresses->next = NULL;
     addresses->address[0] = 0;
     listen_socket_count = 1;
+    #if HAVE_IPV6
+    addresses->next = store_get(sizeof(ip_address_item));
+    addresses->next->next = NULL;
+    addresses->next->address[0] = ':';
+    addresses->next->address[1] = 0;
+    listen_socket_count++;
+    #endif  /* HAVE_IPV6 */
     }
 
   /* Get a vector to remember all the sockets in */
@@ -714,41 +725,20 @@
   #endif
 
   /* For each IP address, create a socket and bind it to the appropriate
-  port. Note that if local_interfaces is not set, we bind a single socket to
-  all interfaces. */
+  port. Some IPv6 stacks can handle IPv4 addresses on IPv6 sockets using
+  the mapping facilities. However, some don't do this because of security
+  concerns. Therefore, we use IPv4 sockets for IPv4 addresses even in an
+  IPv6 world. */
 
   for (ipa = addresses, sk = 0; sk < listen_socket_count; ipa = ipa->next, sk++)
     {
     int i;
+    int af = (strchr(ipa->address, ':') != NULL)? AF_INET6 : AF_INET;
 
-    #if HAVE_IPV6
-    BOOL ipv6_socket = TRUE;
-    BOOL ipv6_address = strchr(ipa->address, ':') != NULL;
-
-    /* A system which has all the IPv6 libraries etc. may nevertheless not
-    support IPv6 in the kernel, so if the socket creation fails, fall back
-    on creating an IPv4 socket, except when we have an explicit IPv6 address,
-    for which we really do need an IPv6 socket. */
-
-    listen_sockets[sk] = socket(AF_INET6, SOCK_STREAM, 0);
-    if (listen_sockets[sk] < 0)
-      {
-      if (!ipv6_address)
-        {
-        listen_sockets[sk] = socket(AF_INET, SOCK_STREAM, 0);
-        ipv6_socket = FALSE;
-        }
-      }
-
-    /* The IPv4 case */
-
-    #else    /* HAVE_IPV6 */
-    listen_sockets[sk] = socket(AF_INET, SOCK_STREAM, 0);
-    #endif   /* HAVE_IPV6 */
-
+    listen_sockets[sk] = socket(af, SOCK_STREAM, 0);
     if (listen_sockets[sk] < 0)
-      log_write(0, LOG_PANIC_DIE, "socket creation failed: %s",
-        strerror(errno));
+      log_write(0, LOG_PANIC_DIE, "IPv%c socket creation failed: %s",
+        (af == AF_INET6)? '6' : '4', strerror(errno));
 
     /* Set SO_REUSEADDR so that the daemon can be restarted while a connection
     is being handled.  Without this, a connection will prevent reuse of the
@@ -765,44 +755,29 @@
 
     memset(&sin, 0, sizeof(sin));
 
-    /* This code has to be entirely different for IPv6 and IPv4 because
-    of the different struct layouts. Sigh. Under IPv6, however, we may have
-    ended up with an IPv4 socket because the kernel may not support IPv6 even
-    if the libraries etc. are available. In this case, revert to IPv4 style
-    code (this will happen only when the the address is not an IPv6 one).
-    Although the code is identical, I've chosen to replicate it for ease of
-    reading the two cases. */
+    /* Setup code when using an IPv6 socket. The wildcard address is ":", to
+    ensure an IPv6 socket is used. */
 
     #if HAVE_IPV6
-    if (ipv6_socket)
+    if (af == AF_INET6)
       {
       sin.v6.sin6_family = AF_INET6;
       sin.v6.sin6_port = net_port;
-
-      if (ipa->address[0] == 0)
+      if (ipa->address[0] == ':' && ipa->address[1] == 0)
         {
         sin.v6.sin6_addr = anyaddr6;
         DEBUG(9) debug_printf("listening on all interfaces (IPv6)\n");
         }
       else
         {
-        int rc;
-        if (ipv6_address)
-          rc = inet_pton(AF_INET6, ipa->address, &sin.v6.sin6_addr);
-        else
-        /* We have an IPv6 socket, and an IPv4 address. We have to turn the
-        address into an IPv6 mapped form. */
-          {
-          memmove(ipa->address+7, ipa->address, (int)strlen(ipa->address) + 1);
-          memcpy(ipa->address, "::ffff:", 7);
-          rc = inet_pton(AF_INET6, ipa->address, &sin.v6.sin6_addr);
-          }
-        if (rc != 1)
+        if (inet_pton(AF_INET6, ipa->address, &sin.v6.sin6_addr) != 1)
           log_write(0, LOG_PANIC_DIE, "unable to parse \"%s\"", ipa->address);
         DEBUG(9) debug_printf("listening on %s\n", ipa->address);
         }
       }
-    else   /* Revert to IPv4 code */
+    else
+    #endif  /* HAVE_IPV6 */
+    /* Setup code when using IPv4 socket. The wildcard address is "". */
       {
       sin.v4.sin_family = AF_INET;
       sin.v4.sin_port = net_port;
@@ -817,34 +792,25 @@
         DEBUG(9) debug_printf("listening on %s\n", ipa->address);
         }
       }
-    #else   /* HAVE_IPV6 */
 
-
-    /* The IPv4 case is simple. */
-
-    sin.v4.sin_family = AF_INET;
-    sin.v4.sin_port = net_port;
-    if (ipa->address[0] == 0)
-      {
-      sin.v4.sin_addr.s_addr = (S_ADDR_TYPE)INADDR_ANY;
-      DEBUG(9) debug_printf("listening on all interfaces\n");
-      }
-    else
-      {
-      sin.v4.sin_addr.s_addr = (S_ADDR_TYPE)inet_addr(ipa->address);
-      DEBUG(9) debug_printf("listening on %s\n", ipa->address);
-      }
-    #endif  /* HAVE_IPV6 */
-
-
-    /* Retry loop */
+    /* Retry loop. Need to get the length of sin right for IPv4/IPv6
+    for some operating systems that check it. Although AF_INET6 is always
+    available (even on old IPv4 systems), the sin.v6 field isn't. */
 
     for (i = 9; i >= 0; i--)
       {
-      if (bind(listen_sockets[sk], (struct sockaddr *)&sin, sizeof(sin)) < 0)
+      if (bind(listen_sockets[sk], (struct sockaddr *)&sin,
+               #if HAVE_IPV6
+               (af == AF_INET6)? sizeof(sin.v6) : sizeof(sin.v4)
+               #else
+               sizeof(sin)
+               #endif /* HAVE_IPV6 */
+           ) < 0)
         {
         char *msg = strerror(errno);
-        char *addr = (ipa->address[0] == 0)? "(any)" : ipa->address;
+        char *addr = (ipa->address[0] == 0)? "(any IPv4)" :
+          (ipa->address[0] == ':' && ipa->address[1] == 0)? "(any IPv6)" :
+          ipa->address;
         if (i == 0)
           log_write(0, LOG_MAIN|LOG_PANIC_DIE,
             "socket bind() to port %d for address %s failed: %s: "
