--- core/configuration.cpp.orig	2011-08-10 13:45:01.165003888 -0500
+++ core/configuration.cpp	2011-08-10 13:45:35.358002044 -0500
@@ -684,7 +684,7 @@
                 in6.sin6_addr.s6_addr[i] = 0;
                 ++i;
             }
-            in6.sin6_addr.s6_addr[15] = ntohs( 1 );
+            in6.sin6_addr.s6_addr[15] = 1;
             in6.sin6_scope_id = 0;
             if ( ::bind( s, (struct sockaddr *)&in6, sizeof( in6 ) ) < 0 ) {
                 if ( errno == EADDRINUSE )
