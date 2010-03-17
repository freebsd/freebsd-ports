--- ifaddr.c.orig	2010-01-14 23:49:24.515378502 +0300
+++ ifaddr.c	2010-01-14 23:50:07.723908032 +0300
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <ifaddrs.h>
 
 #include <assert.h>
 #include <limits.h>
@@ -21,114 +22,29 @@
  */
 int
 if2addr( const char* ifname,
-             struct sockaddr *addr, size_t addrlen )
+             struct sockaddr_in *addr, size_t addrlen )
 {
-    int rc, sockfd;
-    char *buf, *rec;
-    size_t buflen, sa_len;
-    int last_len;
-    struct ifconf  ifc;
-    struct ifreq   ifr;
-
-    static size_t IFC_TABLE_SIZE;
-
-    static const size_t IFC_ENTRIES = 32;
-    static const size_t MAX_IFCBUF_SIZE = (1024 * 256);
-
-    IFC_TABLE_SIZE = sizeof(struct ifreq) * IFC_ENTRIES;
+    int rc = -1;
+    struct ifaddrs *ifr, *ifc;
+    struct sockaddr_in *sin;
 
     assert( ifname && addr && addrlen );
-    rc = 0;
-
-    /* acquire the list of network interfaces */
-
-    sockfd = socket( AF_INET, SOCK_DGRAM, 0 );
-    if( -1 == sockfd ) return -1;
-
-    buf = NULL; buflen = IFC_TABLE_SIZE; last_len = 0;
-    for( ; buflen < MAX_IFCBUF_SIZE; buflen += IFC_TABLE_SIZE ) {
-        if( NULL == (buf = malloc( buflen )) ) {
-            rc = -1;
-            break;
-        }
-
-        ifc.ifc_len = buflen;
-        ifc.ifc_buf = buf;
-        if( ioctl( sockfd, SIOCGIFCONF, &ifc ) < 0 ) {
-            if( (EINVAL != errno) || (last_len != 0) ) {
-                rc = errno;
-                break;
-            }
-        }
-        else {
-            if( ifc.ifc_len == last_len )
-                break;
-            else
-                last_len = ifc.ifc_len;
-        }
-
-        free( buf );
-        buf = NULL;
-    } /* for */
-
-    (void) close( sockfd );
-    if( buflen > MAX_IFCBUF_SIZE ) rc = -1;
-
-    if( 0 != rc ) {
-        if( NULL != buf ) free( buf );
-        return rc;
-    }
 
-    assert( ifc.ifc_buf );
+    getifaddrs(&ifr);
 
-    /* look for ifname in the list */
-
-    for( rec = ifc.ifc_buf; rec < (ifc.ifc_buf + ifc.ifc_len); ) {
-        (void) memcpy( &ifr, rec, sizeof(struct ifreq) );
-
-        #ifdef NO_SOCKADDR_SA_LEN
-        switch( ifr.ifr_addr.sa_family )
-        {
-            case AF_INET:
-                sa_len = sizeof(struct sockaddr); break;
-#ifndef NO_INET6_SUPPORT
-            case AF_INET6:
-                sa_len = sizeof(struct sockaddr_in6); break;
-#endif
-            default:
-                rc = -1; break;
-        }
-        #else
-        sa_len = ifr.ifr_addr.sa_len;
-        #endif
-        if( 0 != rc ) break;
-
-        if( ifr.ifr_addr.sa_family != AF_INET )
+    for (ifc = ifr; ifc != NULL; ifc = ifc->ifa_next) {
+	if (strcmp(ifc->ifa_name, ifname) != 0)
             continue;
-
-        if( 0 == strncmp(ifname, ifr.ifr_name, sizeof(struct ifreq)) ) {
-            if( addrlen < sa_len ) {
-                rc = -1;
-                break;
-            }
-
-            (void) memcpy( addr, &(ifr.ifr_addr), sa_len );
-            break;
-        }
-        else {
-            /* rec += (sa_len + sizeof( ifr.ifr_name )); */
-            /**** the above is per R. Stevens' book and not working
-             **** on 64-bit Linux */
-
-            rec += sizeof(ifr);
-        }
-    } /* for */
-
-    if( rec >= (buf + ifc.ifc_len) ) {
-        rc = -1;
+        if (ifc->ifa_addr == NULL)
+            continue;
+        sin = (struct sockaddr_in *)ifc->ifa_addr;
+        if (sin->sin_family != AF_INET)
+            continue;
+        memcpy(addr, sin, addrlen);
+        rc = 0;
     }
 
-    free( buf );
+    freeifaddrs(ifr);
     return rc;
 }
 
@@ -147,7 +63,7 @@
         (void) strncpy( buf, s, len );
     }
     else {
-        rc = if2addr( s, (struct sockaddr*)&saddr, sizeof(saddr) );
+        rc = if2addr( s, (struct sockaddr_in *)&saddr, sizeof(saddr) );
         if( 0 != rc ) return rc;
 
         (void) strncpy( buf, inet_ntoa(saddr.sin_addr), len );
