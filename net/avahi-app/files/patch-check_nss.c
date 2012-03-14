--- avahi-client/check-nss.c.orig       2010-06-29 12:30:33.000000000 +0900
+++ avahi-client/check-nss.c    2012-03-13 14:32:57.000000000 +0900
@@ -33,9 +33,9 @@
 
 #ifdef HAVE_DLOPEN
     static const char * const libs[] = {
-        "libnss_mdns.so.2",
-        "libnss_mdns4.so.2",
-        "libnss_mdns6.so.2",
+        "nss_mdns.so",
+        "nss_mdns4.so",
+        "nss_mdns6.so",
         NULL };
 
     const char * const *l;
