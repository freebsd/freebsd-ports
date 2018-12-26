broadcast.cpp:91:13: error: value of type '__bind<int &, sockaddr *, unsigned long>' is not contextually convertible to 'bool'
        if (bind (fd6, (struct sockaddr *)&addr, sizeof (addr)))
	                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- broadcast.cpp.orig	2010-10-09 16:04:27 UTC
+++ broadcast.cpp
@@ -88,7 +88,7 @@ Broadcast::Broadcast(int i_ttl, const char *psz_iface)
             setsockopt (fd6, IPPROTO_IPV6, IPV6_MULTICAST_HOPS,
                         &i_ttl, sizeof(i_ttl));
 
-        if (bind (fd6, (struct sockaddr *)&addr, sizeof (addr)))
+        if (::bind (fd6, (struct sockaddr *)&addr, sizeof (addr)))
         {
             close (fd6);
             fd6 = -1;
@@ -143,7 +143,7 @@ Broadcast::Broadcast(int i_ttl, const char *psz_iface)
             setsockopt (fd4, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, 1);
         }
 
-        if (bind (fd4, (struct sockaddr *)&addr, sizeof (addr)))
+        if (::bind (fd4, (struct sockaddr *)&addr, sizeof (addr)))
         {
             close (fd4);
             fd4 = -1;
@@ -281,7 +281,7 @@ int Broadcast::GuessDestination (const char *str,
     memset (a6, 0, sizeof (*a6));
     a6->sin6_family = AF_INET6;
 #ifdef HAVE_SA_LEN
-    a6->sin_len = sizeof (*a6);
+    a6->sin6_len = sizeof (*a6);
 #endif
     a6->sin6_scope_id = scope_id;
     a6->sin6_port = htons (HELLO_PORT);
