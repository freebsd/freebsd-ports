--- lib/sockopt.c	2010-04-20 21:44:26.000000000 -0400
+++ lib/sockopt.c	2010-11-03 10:55:06.000000000 -0400
@@ -221,13 +221,13 @@ setsockopt_multicast_ipv4(int sock, 
 #ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
   /* This is better because it uses ifindex directly */
   struct ip_mreqn mreqn;
+  struct group_req gr;
+  struct sockaddr_in *si;
   int ret;
   
   switch (optname)
     {
     case IP_MULTICAST_IF:
-    case IP_ADD_MEMBERSHIP:
-    case IP_DROP_MEMBERSHIP:
       memset (&mreqn, 0, sizeof(mreqn));
 
       if (mcast_addr)
@@ -240,6 +240,37 @@ setsockopt_multicast_ipv4(int sock, 
       
       ret = setsockopt(sock, IPPROTO_IP, optname,
 		       (void *)&mreqn, sizeof(mreqn));
+      return ret;
+      break;
+
+    case IP_ADD_MEMBERSHIP:
+    case IP_DROP_MEMBERSHIP:
+      if (ifindex)
+        {
+          memset (&gr, 0, sizeof(gr));
+	  si = (struct sockaddr_in *)&gr.gr_group;
+	  gr.gr_interface = ifindex;
+          if (mcast_addr)
+            si->sin_family = AF_INET;
+#ifdef HAVE_STRUCT_SOCKADDR_IN_SIN_LEN
+            si->sin_len = sizeof(struct sockaddr_in);
+#endif /* HAVE_STRUCT_SOCKADDR_IN_SIN_LEN */
+	    si->sin_addr.s_addr = mcast_addr;
+          if (optname == IP_ADD_MEMBERSHIP)
+            ret = setsockopt(sock, IPPROTO_IP, MCAST_JOIN_GROUP, (void *)&gr, sizeof(gr));
+          else
+            ret = setsockopt(sock, IPPROTO_IP, MCAST_LEAVE_GROUP, (void *)&gr, sizeof(gr));
+        }
+      else
+        {
+          memset (&mreqn, 0, sizeof(mreqn));
+          if (mcast_addr)
+	    mreqn.imr_multiaddr.s_addr = mcast_addr;
+	  mreqn.imr_address = if_addr;
+      
+          ret = setsockopt(sock, IPPROTO_IP, optname,
+		       (void *)&mreqn, sizeof(mreqn));
+        }
       if ((ret < 0) && (optname == IP_ADD_MEMBERSHIP) && (errno == EADDRINUSE))
         {
 	  /* see above: handle possible problem when interface comes back up */
@@ -248,12 +279,18 @@ setsockopt_multicast_ipv4(int sock, 
 		    "re-add (fd %d, ifaddr %s, mcast %s, ifindex %u)",
 		    sock,
 		    inet_ntop(AF_INET, &if_addr, buf[0], sizeof(buf[0])),
-		    inet_ntop(AF_INET, &mreqn.imr_multiaddr,
-			      buf[1], sizeof(buf[1])), ifindex);
-	  setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP,
-		     (void *)&mreqn, sizeof(mreqn));
-	  ret = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP,
-			   (void *)&mreqn, sizeof(mreqn));
+		    inet_ntop(AF_INET, &mcast_addr, buf[1], sizeof(buf[1])),
+                    ifindex);
+          if (ifindex)
+            {
+	      setsockopt(sock, IPPROTO_IP, MCAST_LEAVE_GROUP, (void *)&gr, sizeof(gr));
+	      ret = setsockopt(sock, IPPROTO_IP, MCAST_JOIN_GROUP, (void *)&gr, sizeof(gr));
+            }
+          else
+            {
+	      setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&mreqn, sizeof(mreqn));
+	      ret = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&mreqn, sizeof(mreqn));
+            }
         }
       return ret;
       break;
