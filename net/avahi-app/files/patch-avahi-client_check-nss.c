--- avahi-client/check-nss.c.orig	2014-09-08 12:26:55.000000000 -0400
+++ avahi-client/check-nss.c	2014-09-08 12:27:24.000000000 -0400
@@ -33,6 +33,7 @@ int avahi_nss_support(void) {
 
 #ifdef HAVE_DLOPEN
     static const char * const libs[] = {
+        "nss_mdns.so.1",
         "libnss_mdns.so.2",
         "libnss_mdns4.so.2",
         "libnss_mdns6.so.2",
