--- ../nginx-nats-6f7adf1/src/ngx_nats.c.orig	2025-07-25 14:52:57.670444000 -0400
+++ ../nginx-nats-6f7adf1/src/ngx_nats.c	2025-07-25 14:53:04.538387000 -0400
@@ -55,7 +55,7 @@
  * we can use for uniqueness and to reach the router in testing.
  */
 
-#if (NGX_LINUX) || (NGX_DARWIN)
+#if (NGX_LINUX) || (NGX_DARWIN) || (NGX_FREEBSD)
     #include <net/if.h>
     #include <ifaddrs.h>
 #elif (NGX_WIN32)
@@ -585,7 +585,7 @@
 {
     /* TODO: port to Windows when need it, extend to other platforms. */
 
-#if (NGX_LINUX) || (NGX_DARWIN)
+#if (NGX_LINUX) || (NGX_DARWIN) || (NGX_FREEBSD)
 
     struct ifaddrs     *ifaddrs, *ifa;
     int                 rc, family;
