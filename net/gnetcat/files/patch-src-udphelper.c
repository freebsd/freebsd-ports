--- src/udphelper.c.orig	Mon Jan 12 19:18:26 2004
+++ src/udphelper.c	Mon Jan 12 19:19:22 2004
@@ -45,10 +45,10 @@
 #endif
 
 #if !defined(SIOCGLIFADDR) || !defined(SIOCGLIFFLAGS)
-/* FIXME The following warning occurs on FreeBSD:
-    udphelper.c:48: warning: `SIOCGLIFADDR' redefined
-    /usr/include/sys/sockio.h:78: warning: this is the location of the previous definition
- */
+/* Temp fix - suggested by author */
+#if defined(SIOCGLIFADDR)
+#undef SIOCGLIFADDR
+#endif
 # define SIOCGLIFADDR SIOCGIFADDR
 # define SIOCGLIFFLAGS SIOCGIFFLAGS
 # define SIOCGLIFDSTADDR SIOCGIFDSTADDR
