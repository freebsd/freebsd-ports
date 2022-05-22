--- misc/pcap.c	2022-02-22 05:32:53.000000000 -0500
+++ misc/pcap.c	2022-05-21 23:28:28.467854000 -0500
@@ -38,6 +38,13 @@
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
@@ -1196,8 +1203,84 @@
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
