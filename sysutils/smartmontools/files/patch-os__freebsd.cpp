--- os_freebsd.cpp.orig	2016-12-17 18:42:22 UTC
+++ os_freebsd.cpp
@@ -1936,6 +1936,8 @@ smart_device * freebsd_smart_interface::
   int i;
   const char * test_name = name;
 
+  memset(&ccb, 0, sizeof(ccb));
+
   // if dev_name null, or string length zero
   if (!name || !*name)
     return 0;
