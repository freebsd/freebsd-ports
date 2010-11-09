--- src/ushare.c.orig	2007-12-09 15:03:36.000000000 +0200
+++ src/ushare.c	2010-11-09 14:56:44.261445831 +0200
@@ -171,6 +171,19 @@
   pthread_mutex_unlock (&ut->termination_mutex);
 }
 
+
+#ifdef __FreeBSD__
+static void
+*get_ip_addr(struct sockaddr *sa)
+{
+  if (sa->sa_family == AF_INET)
+    return &(((struct sockaddr_in*)sa)->sin_addr);
+  else
+    return &(((struct sockaddr_in6*)sa)->sin6_addr);
+}
+#endif /* __FreeBSD__ */
+
+
 static void
 handle_action_request (struct Upnp_Action_Request *request)
 {
@@ -188,7 +201,11 @@
   if (strcmp (request->DevUDN + 5, ut->udn))
     return;
 
+#ifndef __FreeBSD__
   ip = request->CtrlPtIPAddr.s_addr;
+#else
+  ip = get_ip_addr((struct sockaddr *)&request->CtrlPtIPAddr) ;
+#endif /* __FreeBSD__ */
   ip = ntohl (ip);
   sprintf (val, "%d.%d.%d.%d",
            (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
@@ -348,6 +365,7 @@
 
   UpnpEnableWebserver (TRUE);
 
+#ifndef __FreeBSD__
   res = UpnpSetVirtualDirCallbacks (&virtual_dir_callbacks);
   if (res != UPNP_E_SUCCESS)
   {
@@ -355,6 +373,43 @@
     free (description);
     return -1;
   }
+#else
+  if ((res = UpnpVirtualDir_set_GetInfoCallback(virtual_dir_callbacks.get_info)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - get_info\n"));
+     free (description);
+     return -1;
+  }
+
+  if ((res = UpnpVirtualDir_set_OpenCallback(virtual_dir_callbacks.open)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - open\n"));
+     free (description);
+     return -1;
+  }
+
+  if ((res = UpnpVirtualDir_set_ReadCallback(virtual_dir_callbacks.read)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - read\n"));
+     free (description);
+     return -1;
+  }
+
+  if ((res = UpnpVirtualDir_set_WriteCallback(virtual_dir_callbacks.write)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - write\n"));
+     free (description);
+     return -1;
+  }
+
+  if ((res = UpnpVirtualDir_set_SeekCallback(virtual_dir_callbacks.seek)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - seek\n"));
+     free (description);
+     return -1;
+  }
+
+  if ((res = UpnpVirtualDir_set_CloseCallback(virtual_dir_callbacks.close)) != UPNP_E_SUCCESS ) {
+     log_error (_("Cannot set virtual directory callback - close\n"));
+     free (description);
+     return -1;
+  }
+#endif /* __FreeBSD__ */
 
   res = UpnpAddVirtualDir (VIRTUAL_DIR);
   if (res != UPNP_E_SUCCESS)
@@ -421,6 +476,7 @@
   itf = itflist;
   while (itf)
   {
+#ifndef __FreeBSD__
     if ((itf->ifa_flags & IFF_UP)
         && !strncmp (itf->ifa_name, interface, IFNAMSIZ))
     {
@@ -430,6 +486,23 @@
       return true;
     }
     itf = itf->ifa_next;
+#else
+    if (strncmp (itf->ifa_name, interface, IFNAMSIZ)) {
+       itf = itf->ifa_next;
+       continue ;
+    }
+
+    if (itf->ifa_flags & IFF_UP) {
+       log_info (_("Interface %s is up.\n"), interface);
+       freeifaddrs (itflist);
+       return true ;
+    } else {
+         log_error (_("Interface %s is down.\n"), interface);
+         log_error (_("Recheck uShare's configuration and try again !\n"));
+         freeifaddrs (itflist);
+         return false ;
+      }
+#endif /*  __FreeBSD__ */
   }
 
   freeifaddrs (itf);
