--- misc/pcap.c.orig	2015-08-03 10:14:29 UTC
+++ misc/pcap.c
@@ -631,13 +631,12 @@ getinterfaces (int *howmany)
   static struct interface_info mydevs[1024];
   int numinterfaces = 0;
   int sd;
-  int len;
+  size_t n;
   char *p;
   char buf[10240];
   struct ifconf ifc;
   struct ifreq *ifr;
   struct sockaddr_in *sin;
-  char *bufp;
 
   /* Dummy socket for ioctl. */
   sd = socket (AF_INET, SOCK_DGRAM, 0);
@@ -655,12 +654,8 @@ getinterfaces (int *howmany)
     log_legacy_write
      ("getinterfaces: SIOCGIFCONF claims you have no network interfaces!");
 
-  len = sizeof (struct ifmap);
-
-  for (bufp = buf; bufp && *bufp && (bufp < (buf + ifc.ifc_len));
-       bufp += sizeof (ifr->ifr_name) + len)
+  for (ifr = (struct ifreq *) buf; (char *) ifr < buf + ifc.ifc_len; )
     {
-      ifr = (struct ifreq *) bufp;
       sin = (struct sockaddr_in *) &ifr->ifr_addr;
       memcpy (&(mydevs[numinterfaces].addr), (char *) &(sin->sin_addr),
               sizeof (struct in_addr));
@@ -670,6 +665,7 @@ getinterfaces (int *howmany)
       strncpy (mydevs[numinterfaces].name, ifr->ifr_name, 63);
       mydevs[numinterfaces].name[63] = '\0';
       numinterfaces++;
+      mydevs[numinterfaces].name[0] = '\0';
       if (numinterfaces == 1023)
         {
           log_legacy_write
@@ -677,7 +673,11 @@ getinterfaces (int *howmany)
             " Things may not work right.");
           break;
         }
-      mydevs[numinterfaces].name[0] = '\0';
+      n = offsetof(struct ifreq, ifr_addr) + ifr->ifr_addr.sa_len;
+      if (n < sizeof(*ifr))
+          ifr++;
+      else
+          ifr = (struct ifreq *)((char *)ifr + n);
     }
 
   // If output parameter given, set value
