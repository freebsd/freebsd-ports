--- base/hosts.c	2021-10-11 09:38:23.000000000 -0500
+++ base/hosts.c	2021-10-27 21:07:36.955872000 -0500
@@ -34,11 +34,11 @@
 #include <arpa/inet.h> /* for inet_pton, inet_ntop */
 #include <assert.h>    /* for assert */
 #include <ctype.h>     /* for isdigit */
-#include <malloc.h>
 #include <netdb.h>      /* for getnameinfo, NI_NAMEREQD */
 #include <stdint.h>     /* for uint8_t, uint32_t */
 #include <stdio.h>      /* for sscanf, perror */
 #include <stdlib.h>     /* for strtol, atoi */
+#include <malloc_np.h>
 #include <string.h>     /* for strchr, memcpy, memcmp, bzero, strcasecmp */
 #include <sys/socket.h> /* for AF_INET, AF_INET6, sockaddr */
 
@@ -1092,7 +1092,7 @@
   hosts->count -= duplicates;
   hosts->duplicated += duplicates;
   hosts->current = 0;
-  malloc_trim (0);
+ // malloc_trim (0);
 }
 
 /**
@@ -1287,7 +1287,7 @@
     gvm_hosts_deduplicate (hosts);
 
   g_strfreev (split);
-  malloc_trim (0);
+  //malloc_trim (0);
   return hosts;
 }
 
@@ -1467,8 +1467,8 @@
           gvm_vhost_t *vhost;
 
           new = gvm_host_new ();
-          if (ip6->s6_addr32[0] != 0 || ip6->s6_addr32[1] != 0
-              || ip6->s6_addr32[2] != htonl (0xffff))
+          if (ip6->s6_addr[0] != 0 || ip6->s6_addr[1] != 0
+              || ip6->s6_addr[2] != 0xff)
             {
               new->type = HOST_TYPE_IPV6;
               memcpy (&new->addr6, ip6, sizeof (new->addr6));
@@ -1476,7 +1476,7 @@
           else
             {
               new->type = HOST_TYPE_IPV4;
-              memcpy (&new->addr6, &ip6->s6_addr32[3], sizeof (new->addr));
+              memcpy (&new->addr6, &ip6->s6_addr[12], sizeof (new->addr));
             }
           vhost =
             gvm_vhost_new (g_strdup (host->name), g_strdup ("Forward-DNS"));
@@ -2034,7 +2034,11 @@
       ret->addr.s_addr = host->addr.s_addr;
       break;
     case HOST_TYPE_IPV6:
+#if defined (__FreeBSD__)
+      ret->addr6.__u6_addr = host->addr6.__u6_addr;
+#else
       ret->addr6.__in6_u = host->addr6.__in6_u;
+#endif
       break;
     default:
       g_free (ret);
