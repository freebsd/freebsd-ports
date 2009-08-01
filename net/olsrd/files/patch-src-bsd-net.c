--- src/bsd/net.c.orig	2009-03-23 19:49:15.000000000 +0000
+++ src/bsd/net.c	2009-06-09 11:51:33.000000000 +0000
@@ -127,7 +127,7 @@
 set_sysctl_int(const char *name, int new)
 {
   int old;
-#if __MacOSX__ || __OpenBSD__
+#if __FreeBSD__ || __MacOSX__ || __OpenBSD__
   size_t len = sizeof(old);
 #else
   unsigned int len = sizeof(old);
@@ -537,7 +537,7 @@
         break;
       }
       ifr6.ifr_addr = *sin6;
-      if (ioctl(s6, SIOCGIFAFLAG_IN6, (int)&ifr6) < 0) {
+      if (ioctl(s6, SIOCGIFAFLAG_IN6, &ifr6) < 0) {
         OLSR_PRINTF(3, "ioctl(SIOCGIFAFLAG_IN6)");
         close(s6);
         break;
