--- avahi-core/iface-pfroute.c.orig	2008-04-05 15:54:11.000000000 -0400
+++ avahi-core/iface-pfroute.c	2008-04-05 16:04:04.000000000 -0400
@@ -172,6 +177,13 @@ static void rtm_addr(struct rt_msghdr *r
 	  break;
 	case RTA_IFA:
 	  memcpy(raddr.data.data, &((struct sockaddr_in6 *)sa)->sin6_addr,  sizeof(struct in6_addr));
+#ifdef __KAME__
+	  if (IN6_IS_ADDR_LINKLOCAL((struct in6_addr *)raddr.data.data))
+            {
+              ((struct in6_addr *)raddr.data.data)->s6_addr[2] = 0;
+	      ((struct in6_addr *)raddr.data.data)->s6_addr[3] = 0;
+	    }
+#endif
 	  raddr_valid = 1;
 	default:
 	  break;
@@ -196,9 +207,12 @@ static void rtm_addr(struct rt_msghdr *r
       if (!(addriface = avahi_interface_monitor_get_address(m, iface, &raddr)))
 	if (!(addriface = avahi_interface_address_new(m, iface, &raddr, prefixlen)))
 	  return; /* OOM */
-      /*       FIXME */
-      /*       addriface->global_scope = ifaddrmsg->ifa_scope == RT_SCOPE_UNIVERSE || ifaddrmsg->ifa_scope == RT_SCOPE_SITE; */
-      addriface->global_scope = 1;
+      if (raddr.proto == AVAHI_PROTO_INET6)
+        {
+	  addriface->global_scope = !(IN6_IS_ADDR_LINKLOCAL((struct in6_addr *)raddr.data.data) || IN6_IS_ADDR_MULTICAST((struct in6_addr *)raddr.data.data));
+	}
+      else
+        addriface->global_scope = 1;
     }
   else
     {
