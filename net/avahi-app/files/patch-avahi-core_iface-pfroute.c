--- avahi-core/iface-pfroute.c.orig	2007-09-03 08:32:41.000000000 -0400
+++ avahi-core/iface-pfroute.c	2008-04-06 15:06:36.000000000 -0400
@@ -125,7 +125,7 @@ static void rtm_addr(struct rt_msghdr *r
   int raddr_valid = 0;
   struct ifa_msghdr *ifam = (struct ifa_msghdr *) rtm;
   char *cp = (char *)(ifam + 1);
-  int addrs = ifam->ifam_addrs;
+  char *cp0;
   int i;
   int prefixlen = 0;
   struct sockaddr *sa  =NULL;
@@ -135,17 +135,30 @@ static void rtm_addr(struct rt_msghdr *r
     ((struct sockaddr *)cp)->sa_family = AF_INET;
 #endif
 
-  if(((struct sockaddr *)cp)->sa_family != AF_INET && ((struct sockaddr *)cp)->sa_family != AF_INET6)
+  for (cp0 = cp, i = 0; i < RTAX_MAX; i++) {
+    if (!(ifam->ifam_addrs & (1<<i)))
+      continue;
+    sa = (struct sockaddr *)cp;
+    if (i == RTAX_IFA)
+      break;
+#ifdef SA_SIZE
+    cp += SA_SIZE(sa);
+#else
+    ADVANCE(cp, sa);
+#endif
+  }
+
+  if(sa->sa_family != AF_INET && sa->sa_family != AF_INET6)
     return;
 
-  if (!(iface = avahi_interface_monitor_get_interface(m, (AvahiIfIndex) ifam->ifam_index, avahi_af_to_proto(((struct sockaddr *)cp)->sa_family))))
+  if (!(iface = avahi_interface_monitor_get_interface(m, (AvahiIfIndex) ifam->ifam_index, avahi_af_to_proto(sa->sa_family))))
     return;
 
-  raddr.proto = avahi_af_to_proto(((struct sockaddr *)cp)->sa_family);
+  raddr.proto = avahi_af_to_proto(sa->sa_family);
   
-  for(i = 0; addrs != 0 && i < RTAX_MAX; addrs &= ~(1<<i), i++)
+  for(cp = cp0, i = 0; i < RTAX_MAX; i++)
     {
-      if (!(addrs & 1<<i))
+      if (!(ifam->ifam_addrs & (1<<i)))
 	continue;
       sa = (struct sockaddr *)cp;
 #ifdef HAVE_SYS_SYSCTL_H
@@ -172,6 +185,13 @@ static void rtm_addr(struct rt_msghdr *r
 	  break;
 	case RTA_IFA:
 	  memcpy(raddr.data.data, &((struct sockaddr_in6 *)sa)->sin6_addr,  sizeof(struct in6_addr));
+#ifdef __KAME__
+	  if (IN6_IS_ADDR_LINKLOCAL((struct in6_addr *)raddr.data.data))
+	    {
+	      ((struct in6_addr *)raddr.data.data)->s6_addr[2] = 0;
+	      ((struct in6_addr *)raddr.data.data)->s6_addr[3] = 0;
+	    }
+#endif
 	  raddr_valid = 1;
 	default:
 	  break;
@@ -196,9 +216,12 @@ static void rtm_addr(struct rt_msghdr *r
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
