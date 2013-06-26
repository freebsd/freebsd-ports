--- server/security.c.orig	2005-06-01 09:20:55.000000000 +0900
+++ server/security.c	2013-06-26 14:56:12.000000000 +0900
@@ -110,18 +110,17 @@
   char                    *hosts_deny;
   extern char             *hosts_allow_table;
   extern char             *hosts_deny_table;
-#  ifdef HAVE_IPV6
-  struct sockaddr_in      *sin;
   struct sockaddr_storage  ss;
-  struct sockaddr_in6     *sin6;
   struct sockaddr         *sa;
   socklen_t                salen = sizeof ss;
+#ifdef HAVE_IPV6
   char                     addr[INET6_ADDRSTRLEN];
   char                     wrapper_addr[INET6_ADDRSTRLEN + 2];
+#else
+  char                     addr[INET_ADDRSTRLEN];
+  char                     wrapper_addr[INET_ADDRSTRLEN + 2];
+#endif
   char                     client_name[NI_MAXHOST];
-#  else
-  struct request_info      req;
-#  endif /* HAVE_IPV6 */

   hosts_allow = get_security_allow();
   hosts_deny  = get_security_deny();
@@ -133,7 +132,6 @@
   hosts_allow_table = hosts_allow;
   hosts_deny_table  = hosts_deny;

-#  ifdef HAVE_IPV6
   /* Do this the new way, which specifically knows how to format IPv6
      addresses. */

@@ -153,42 +151,15 @@

   /* convert the address to a presentation format that tcp wrapper
      understands */
-  switch ( sa->sa_family ) {
-    case AF_INET: {
-      sin = (struct sockaddr_in *) sa;
-      strncpy( wrapper_addr,
-               inet_ntop( AF_INET, (void *) sin->sin_addr.s_addr, addr,
-                          sizeof addr ),
-               sizeof wrapper_addr ) ;
-    }
-    case AF_INET6: {
-      sin6 = (struct sockaddr_in6 *) sa;
-      inet_ntop( AF_INET6, (void *) sin6->sin6_addr.s6_addr, addr, sizeof
-                 addr );
-      /* If it's an IPv4 mapped address, drop the leading '::ffff:' */
-      if ( IN6_IS_ADDR_V4MAPPED( &(sin6->sin6_addr) ) )
-        strncpy( wrapper_addr, addr + 7, sizeof wrapper_addr );
-      /* otherwise surround the address with braces to hopefully match
-         what tcp wrapper expects */
-      else sprintf( wrapper_addr, "%s", addr );
-    }
-  }
+
+  if (getnameinfo(sa, salen, wrapper_addr, sizeof(wrapper_addr), NULL, 0,
+      NI_NUMERICHOST) != 0)
+    log(L_LOG_WARNING, CONFIG, "getnameinfo failed: %s",
+        strerror(errno));
+
   log( L_LOG_WARNING, CONFIG, "client tcp wrapper address: %s", wrapper_addr );

   return( hosts_ctl( directive, client_name, wrapper_addr, STRING_UNKNOWN ) );
-#  else /* HAVE_IPV6 */
-
-  /* Do this the old way, which still seems to work */
-
-  /* set up the request structure */
-  request_init(&req, RQ_FILE, 0, RQ_DAEMON, directive, 0);
-
-  /* fill in the client info */
-  fromhost(&req);
-
-  /* return the results of the access check */
-  return(hosts_access(&req));
-#  endif /* HAVE_IPV6 */

 #else  /* USE_TCP_WRAPPERS */
   return TRUE;
