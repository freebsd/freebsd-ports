--- src/netstatus-iface.c.orig	Fri Oct 31 08:49:51 2003
+++ src/netstatus-iface.c	Fri Jan  2 23:29:27 2004
@@ -32,9 +32,12 @@
 
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <net/if_arp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <unistd.h>
@@ -577,6 +580,7 @@
 					       iface);
 
       netstatus_iface_monitor_timeout (iface);
+
     }
 }
 
@@ -646,7 +650,11 @@
   strncpy (if_req.ifr_name, iface->priv->name, IF_NAMESIZE - 1);
   if_req.ifr_name [IF_NAMESIZE - 1] = '\0';
   if (mask && ioctl (fd, SIOCGIFNETMASK, &if_req) == 0)
+#if !defined(__FreeBSD__)
     *mask = g_strdup (inet_ntoa (((struct sockaddr_in *) &if_req.ifr_netmask)->sin_addr));
+#else
+    *mask = g_strdup (inet_ntoa (((struct sockaddr_in *) &if_req.ifr_addr)->sin_addr));
+#endif
 
   close (fd);
 
@@ -925,6 +933,7 @@
 				char           **hw_addr)
 				
 {
+#ifdef SIOCGIFHWADDR
   static struct HwType *hw_type = NULL;
   struct ifreq          if_req;
   int                   fd;
@@ -973,6 +982,9 @@
     *hw_addr = hw_type->print_hw_addr (if_req.ifr_hwaddr.sa_data);
 
   return hw_type;
+#else
+  return NULL;
+#endif
 }
 
 gboolean
@@ -1083,8 +1095,11 @@
   struct ifconf *if_conf;
   GList         *interfaces;
   GList         *loopbacks;
+  gchar         *ptr;
   int            fd;
-  int            i;
+  struct ifreq  *if_req;
+  int            len;
+  gboolean       loopback;
   
   if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) < 0)
     {
@@ -1105,12 +1120,25 @@
   interfaces = NULL;
   loopbacks  = NULL;
 
-  for (i = 0; i < if_conf->ifc_len / sizeof (struct ifreq); i++)
+  for (ptr = if_conf->ifc_buf; ptr < if_conf->ifc_buf + if_conf->ifc_len;)
     {
-      struct ifreq if_req = if_conf->ifc_req [i];
-      gboolean     loopback = FALSE;
+      if_req = (struct ifreq *) ptr;
+      loopback = FALSE;
+      len      = sizeof(struct sockaddr);
+#if defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
+      if (if_req->ifr_addr.sa_len > len)
+	len = if_req->ifr_addr.sa_len;
+#endif
+
+      ptr += sizeof(if_req->ifr_name) + len;
+ 
+      if (g_list_find_custom (interfaces, if_req->ifr_name, 
+		  (GCompareFunc) g_ascii_strcasecmp) != NULL
+	      || g_list_find_custom (loopbacks, if_req->ifr_name,
+		  (GCompareFunc) g_ascii_strcasecmp) != NULL)
+	continue;
 
-      if (ioctl (fd, SIOCGIFFLAGS, &if_req) < 0)
+      if (ioctl (fd, SIOCGIFFLAGS, if_req) < 0)
 	{
 	  if (error)
 	    *error = g_error_new (NETSTATUS_ERROR,
@@ -1120,13 +1148,14 @@
 	}
       else
 	{
-	  loopback = (if_req.ifr_flags & IFF_LOOPBACK);
+	  loopback = (if_req->ifr_flags & IFF_LOOPBACK);
 	}
 
       if (!loopback)
-	interfaces = g_list_prepend (interfaces, g_strdup (if_req.ifr_name));
+	interfaces = g_list_prepend (interfaces, g_strdup (if_req->ifr_name));
       else
-	loopbacks  = g_list_prepend (loopbacks,  g_strdup (if_req.ifr_name));
+	loopbacks  = g_list_prepend (loopbacks,  g_strdup (if_req->ifr_name));
+
     }
 
   interfaces = g_list_concat (interfaces, loopbacks);
