--- ./Interface.xs.orig	2008-06-06 08:51:42.000000000 -0700
+++ ./Interface.xs	2012-05-15 13:16:22.856348098 -0700
@@ -567,6 +567,7 @@
      struct ifreq   ifr;
 #if (defined(USE_GETIFADDRS) && defined(HAVE_SOCKADDR_DL_STRUCT))
      struct ifaddrs* ifap = NULL;
+     struct ifaddrs* saved_ifap = NULL;
      struct sockaddr_dl* sdl;
      sa_family_t  family;
      char *sdlname, *haddr, *s;
@@ -581,6 +582,7 @@
 #endif
 #if (defined(USE_GETIFADDRS) && defined(HAVE_SOCKADDR_DL_STRUCT))
      getifaddrs(&ifap);
+     saved_ifap = ifap;
 
      while(1) {
        if (ifap == NULL) break;
@@ -595,7 +597,7 @@
        }
        ifap = ifap -> ifa_next;
      } 
-     freeifaddrs(ifap);
+     freeifaddrs(saved_ifap);
 
      s = hwaddr; 
      s[0] = '\0';
