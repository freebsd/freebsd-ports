--- zebra/kernel_socket.c	2007/05/10 02:38:52	1.43
+++ zebra/kernel_socket.c	2007/05/17 15:00:41	1.44
@@ -494,6 +494,8 @@
 		short *ifnlen)
 {
   caddr_t pnt, end;
+  union sockunion dst;
+  union sockunion gateway;
 
   pnt = (caddr_t)(ifm + 1);
   end = ((caddr_t)ifm) + ifm->ifam_msglen;
@@ -502,10 +504,12 @@
   memset (mask, 0, sizeof (union sockunion));
   memset (addr, 0, sizeof (union sockunion));
   memset (brd, 0, sizeof (union sockunion));
+  memset (&dst, 0, sizeof (union sockunion));
+  memset (&gateway, 0, sizeof (union sockunion));
 
   /* We fetch each socket variable into sockunion. */
-  RTA_ADDR_GET (NULL, RTA_DST, ifm->ifam_addrs, pnt);
-  RTA_ADDR_GET (NULL, RTA_GATEWAY, ifm->ifam_addrs, pnt);
+  RTA_ADDR_GET (&dst, RTA_DST, ifm->ifam_addrs, pnt);
+  RTA_ADDR_GET (&gateway, RTA_GATEWAY, ifm->ifam_addrs, pnt);
   RTA_ATTR_GET (mask, RTA_NETMASK, ifm->ifam_addrs, pnt);
   RTA_ADDR_GET (NULL, RTA_GENMASK, ifm->ifam_addrs, pnt);
   RTA_NAME_GET (ifname, RTA_IFP, ifm->ifam_addrs, pnt, *ifnlen);
@@ -519,31 +523,43 @@
         {
 	case AF_INET:
 	  {
-	    char buf[2][INET_ADDRSTRLEN];
+	    char buf[4][INET_ADDRSTRLEN];
 	    zlog_debug ("%s: ifindex %d, ifname %s, ifam_addrs 0x%x, "
-			"addr %s/%d broad %s", 
-			__func__, ifm->ifam_index, 
+			"ifam_flags 0x%x, addr %s/%d broad %s dst %s "
+			"gateway %s",
+			__func__, ifm->ifam_index,
 			(ifnlen ? ifname : "(nil)"), ifm->ifam_addrs,
+			ifm->ifam_flags,
 			inet_ntop(AF_INET,&addr->sin.sin_addr,
 			          buf[0],sizeof(buf[0])),
 			ip_masklen(mask->sin.sin_addr),
 			inet_ntop(AF_INET,&brd->sin.sin_addr,
-			          buf[1],sizeof(buf[1])));
+			          buf[1],sizeof(buf[1])),
+			inet_ntop(AF_INET,&dst.sin.sin_addr,
+			          buf[2],sizeof(buf[2])),
+			inet_ntop(AF_INET,&gateway.sin.sin_addr,
+			          buf[3],sizeof(buf[3])));
 	  }
 	  break;
 #ifdef HAVE_IPV6
 	case AF_INET6:
 	  {
-	    char buf[2][INET6_ADDRSTRLEN];
+	    char buf[4][INET6_ADDRSTRLEN];
 	    zlog_debug ("%s: ifindex %d, ifname %s, ifam_addrs 0x%x, "
-			"addr %s/%d broad %s", 
+			"ifam_flags 0x%x, addr %s/%d broad %s dst %s "
+			"gateway %s",
 			__func__, ifm->ifam_index, 
 			(ifnlen ? ifname : "(nil)"), ifm->ifam_addrs,
+			ifm->ifam_flags,
 			inet_ntop(AF_INET6,&addr->sin6.sin6_addr,
 			          buf[0],sizeof(buf[0])),
 			ip6_masklen(mask->sin6.sin6_addr),
 			inet_ntop(AF_INET6,&brd->sin6.sin6_addr,
-			          buf[1],sizeof(buf[1])));
+			          buf[1],sizeof(buf[1])),
+			inet_ntop(AF_INET6,&dst.sin6.sin6_addr,
+			          buf[2],sizeof(buf[2])),
+			inet_ntop(AF_INET6,&gateway.sin6.sin6_addr,
+			          buf[3],sizeof(buf[3])));
 	  }
 	  break;
 #endif /* HAVE_IPV6 */
@@ -554,7 +570,7 @@
 	  break;
         }
     }
-  
+
   /* Assert read up end point matches to end point */
   if (pnt != end)
     zlog_warn ("ifam_read() does't read all socket data");
@@ -569,6 +585,7 @@
   char ifname[INTERFACE_NAMSIZ];
   short ifnlen = 0;
   char isalias = 0;
+  int flags = 0;
   
   ifname[0] = ifname[INTERFACE_NAMSIZ - 1] = '\0';
   
@@ -585,6 +602,12 @@
   if (ifnlen && strncmp (ifp->name, ifname, INTERFACE_NAMSIZ))
     isalias = 1;
   
+  /* N.B. The info in ifa_msghdr does not tell us whether the RTA_BRD
+     field contains a broadcast address or a peer address, so we are forced to
+     rely upon the interface type. */
+  if (if_is_pointopoint(ifp))
+    SET_FLAG(flags, ZEBRA_IFA_PEER);
+
 #if 0
   /* it might seem cute to grab the interface metric here, however
    * we're processing an address update message, and so some systems
@@ -599,12 +622,12 @@
     {
     case AF_INET:
       if (ifam->ifam_type == RTM_NEWADDR)
-	connected_add_ipv4 (ifp, 0, &addr.sin.sin_addr, 
+	connected_add_ipv4 (ifp, flags, &addr.sin.sin_addr, 
 			    ip_masklen (mask.sin.sin_addr),
 			    &brd.sin.sin_addr,
 			    (isalias ? ifname : NULL));
       else
-	connected_delete_ipv4 (ifp, 0, &addr.sin.sin_addr, 
+	connected_delete_ipv4 (ifp, flags, &addr.sin.sin_addr, 
 			       ip_masklen (mask.sin.sin_addr),
 			       &brd.sin.sin_addr);
       break;
@@ -616,8 +639,7 @@
 	SET_IN6_LINKLOCAL_IFINDEX (addr.sin6.sin6_addr, 0);
 
       if (ifam->ifam_type == RTM_NEWADDR)
-	connected_add_ipv6 (ifp, 0,
-			    &addr.sin6.sin6_addr, 
+	connected_add_ipv6 (ifp, flags, &addr.sin6.sin6_addr, 
 			    ip6_masklen (mask.sin6.sin6_addr),
 			    &brd.sin6.sin6_addr,
 			    (isalias ? ifname : NULL));
