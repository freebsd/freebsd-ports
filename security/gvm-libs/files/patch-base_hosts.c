--- base/hosts.c	2022-07-18 03:40:56.000000000 -0500
+++ base/hosts.c	2022-07-31 17:50:48.439636000 -0500
@@ -34,7 +34,11 @@
 #include <arpa/inet.h> /* for inet_pton, inet_ntop */
 #include <assert.h>    /* for assert */
 #include <ctype.h>     /* for isdigit */
+#if defined(__FreeBSD__)
+#include <malloc_np.h>
+#else
 #include <malloc.h>
+#endif
 #include <netdb.h>      /* for getnameinfo, NI_NAMEREQD */
 #include <stdint.h>     /* for uint8_t, uint32_t */
 #include <stdio.h>      /* for sscanf, perror */
@@ -1472,8 +1476,13 @@
           gvm_vhost_t *vhost;
 
           new = gvm_host_new ();
+#if defined(__FreeBSD__)
+	  if (ip6->s6_addr[0] != 0 || ip6->s6_addr[1] != 0
+              || ip6->s6_addr[2] != 0xff)
+#else
           if (ip6->s6_addr32[0] != 0 || ip6->s6_addr32[1] != 0
               || ip6->s6_addr32[2] != htonl (0xffff))
+#endif
             {
               new->type = HOST_TYPE_IPV6;
               memcpy (&new->addr6, ip6, sizeof (new->addr6));
@@ -1481,7 +1490,11 @@
           else
             {
               new->type = HOST_TYPE_IPV4;
+#if defined(__FreeBSD__)
+              memcpy (&new->addr6, &ip6->s6_addr[12], sizeof (new->addr));
+#else
               memcpy (&new->addr6, &ip6->s6_addr32[3], sizeof (new->addr));
+#endif
             }
           vhost =
             gvm_vhost_new (g_strdup (host->name), g_strdup ("Forward-DNS"));
@@ -2040,7 +2053,11 @@
       ret->addr.s_addr = host->addr.s_addr;
       break;
     case HOST_TYPE_IPV6:
+#if defined(__FreeBSD__)
+      ret->addr6.__u6_addr = host->addr6.__u6_addr;
+#else
       ret->addr6.__in6_u = host->addr6.__in6_u;
+#endif
       break;
     default:
       g_free (ret);
