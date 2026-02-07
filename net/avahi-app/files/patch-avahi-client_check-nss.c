--- avahi-client/check-nss.c.orig	2010-08-26 00:51:38 UTC
+++ avahi-client/check-nss.c
@@ -33,6 +33,7 @@ int avahi_nss_support(void) {
 
 #ifdef HAVE_DLOPEN
     static const char * const libs[] = {
+        "nss_mdns.so.1",
         "libnss_mdns.so.2",
         "libnss_mdns4.so.2",
         "libnss_mdns6.so.2",
