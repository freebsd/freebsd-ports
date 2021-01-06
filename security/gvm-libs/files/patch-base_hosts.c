--- base/hosts.c	2020-12-30 14:04:30.773110000 -0500
+++ base/hosts.c	2020-12-30 23:46:15.994709000 -0500
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
 
@@ -1068,7 +1068,7 @@
   hosts->count -= duplicates;
   hosts->removed += duplicates;
   hosts->current = 0;
-  malloc_trim (0);
+ // malloc_trim (0);
 }
 
 /**
@@ -1263,7 +1263,7 @@
     gvm_hosts_deduplicate (hosts);
 
   g_strfreev (split);
-  malloc_trim (0);
+  //malloc_trim (0);
   return hosts;
 }
 
@@ -1410,8 +1410,8 @@
           gvm_vhost_t *vhost;
 
           new = gvm_host_new ();
-          if (ip6->s6_addr32[0] != 0 || ip6->s6_addr32[1] != 0
-              || ip6->s6_addr32[2] != htonl (0xffff))
+          if (ip6->s6_addr[0] != 0 || ip6->s6_addr[1] != 0
+              || ip6->s6_addr[2] != 0xff)
             {
               new->type = HOST_TYPE_IPV6;
               memcpy (&new->addr6, ip6, sizeof (new->addr6));
@@ -1419,7 +1419,7 @@
           else
             {
               new->type = HOST_TYPE_IPV4;
-              memcpy (&new->addr6, &ip6->s6_addr32[3], sizeof (new->addr));
+              memcpy (&new->addr6, &ip6->s6_addr[12], sizeof (new->addr));
             }
           vhost =
             gvm_vhost_new (g_strdup (host->name), g_strdup ("Forward-DNS"));
