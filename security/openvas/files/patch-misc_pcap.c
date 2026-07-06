--- misc/pcap.c.orig	2026-06-22 06:53:05.000000000 -0700
+++ misc/pcap.c	2026-06-23 00:15:36.671060000 -0700
@@ -25,6 +25,13 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 #include <sys/types.h>
+#if defined __FreeBSD__
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#include <errno.h>
+#endif
 #include <unistd.h>
 
 #define MAXROUTES 1024
@@ -414,6 +421,56 @@
 {
   static struct interface_info mydevs[1024];
   int numinterfaces = 0;
+#if defined(__FreeBSD__)
+  struct ifaddrs *ifaddr, *ifa;
+  struct sockaddr_in *saddr;
+  char *p;
+
+  if (getifaddrs (&ifaddr) == -1)
+    {
+      g_message ("getinterfaces: getifaddrs failed");
+      return NULL;
+    }
+
+  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
+    {
+      if (ifa->ifa_addr == NULL)
+        continue;
+      if (ifa->ifa_addr->sa_family != AF_INET)
+        continue;
+
+       saddr = (struct sockaddr_in *) ifa->ifa_addr;
+
+      if (numinterfaces >= 1023)
+        {
+          g_message ("You seem to have more than 1023 network interfaces."
+                     " Things may not work right.");
+          break;
+        }
+
+      mydevs[numinterfaces].addr = saddr->sin_addr;
+
+      memset (mydevs[numinterfaces].name, 0, MAX_IFACE_NAME_LEN);
+      if ((p = strchr (ifa->ifa_name, ':')))
+        {
+          size_t len = (size_t) (p - ifa->ifa_name);
+          if (len >= MAX_IFACE_NAME_LEN)
+            len = MAX_IFACE_NAME_LEN - 1;
+          memcpy (mydevs[numinterfaces].name, ifa->ifa_name, len);
+        }
+      else
+        {
+          strncpy (mydevs[numinterfaces].name, ifa->ifa_name,
+                   MAX_IFACE_NAME_LEN - 1);
+        }
+
+      numinterfaces++;
+      if (numinterfaces < 1024)
+        mydevs[numinterfaces].name[0] = '\0';
+     }
+      
+  freeifaddrs (ifaddr);
+#else
   int sd;
   int len;
   char *p;
@@ -442,12 +499,6 @@
     g_message (
       "getinterfaces: SIOCGIFCONF claims you have no network interfaces!");
 
-#ifndef __FreeBSD__
-  len = sizeof (struct ifmap);
-#else
-  len = sizeof (struct sockaddr);
-#endif
-
   for (bufp = buf; bufp && *bufp && (bufp < (buf + ifc.ifc_len));
        bufp += sizeof (ifr->ifr_name) + len)
     {
@@ -476,6 +527,7 @@
       mydevs[numinterfaces].name[0] = '\0';
     }
 
+#endif
   // If output parameter given, set value
   if (howmany)
     *howmany = numinterfaces;
@@ -1193,8 +1245,84 @@
         }
       else
         {
+#if defined(__FreeBSD__)
+          void * addr_ptr;
+          struct sockaddr * sockaddr_ptr;
+          struct ifaddrs * ifaddrs_ptr;
+          int status;
+          char address[INET6_ADDRSTRLEN];
+          unsigned long tmp;
+
+          status = getifaddrs (& ifaddrs_ptr);
+          if(status == -1) {
+            g_debug("Error in 'getifaddrs': %d (%s)\n",
+                 errno, strerror (errno));
+            exit (1);
+          }
+
+          while (ifaddrs_ptr) 
+	  {
+            if (ifaddrs_ptr->ifa_addr->sa_family == AF_INET) 
+	    {
+              strncpy (iface, ifaddrs_ptr->ifa_name, sizeof (iface));
+              iface[MAX_IFACE_NAME_LEN - 1] = '\0';
+
+              sockaddr_ptr = ifaddrs_ptr->ifa_dstaddr;
+              addr_ptr = &((struct sockaddr_in *)  sockaddr_ptr)->sin_addr;
+
+              inet_ntop (ifaddrs_ptr->ifa_addr->sa_family,
+                          addr_ptr,
+                          address, sizeof (address));
+
+	      endptr = NULL;
+              tmp = strtoul (address, &endptr, 16);
+	      myroutes[numroutes].dest = tmp;
+
+              endptr = NULL;
+              tmp = strtol ("0", &endptr, 10);
+              myroutes[numroutes].metric = tmp;
+
+              sockaddr_ptr = ifaddrs_ptr->ifa_netmask;
+              addr_ptr = &((struct sockaddr_in *)  sockaddr_ptr)->sin_addr;
+
+              inet_ntop (ifaddrs_ptr->ifa_addr->sa_family,
+                          addr_ptr,
+                          address, sizeof (address));
+
+	      endptr = NULL;
+              tmp = strtoul (address, &endptr, 16);
+              myroutes[numroutes].mask = tmp;
+
+              g_debug("#%d: for dev %s, The dest is %lX and the mask is %lX",
+                     numroutes, iface, myroutes[numroutes].dest,
+                     myroutes[numroutes].mask);
+
+              for (i = 0; i < numinterfaces; i++)
+                if (!strcmp (iface, mydevs[i].name))
+                {
+                  myroutes[numroutes].dev = &mydevs[i];
+                  break;
+                }
+
+              if (i == numinterfaces)
+                g_message (
+                    "Failed to find interface %s",
+                    iface);
+              
+	      numroutes++;
+              
+	      if (numroutes >= MAXROUTES)
+              {
+                g_message ("You seem to have WAY to many routes!");
+                break;
+              }		
+	    }
+	    ifaddrs_ptr = ifaddrs_ptr->ifa_next;
+    	  }
+#else        
           g_message ("Could not read from /proc/net/route");
           return NULL;
+#endif          
         }
     }
   else
