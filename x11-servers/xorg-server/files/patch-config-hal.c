--- config/hal.c.orig	2007-08-23 15:04:52.000000000 -0400
+++ config/hal.c	2008-03-27 18:36:36.000000000 -0400
@@ -212,6 +212,7 @@
     }
 
     add_option(&options, "path", path);
+    add_option(&options, "device", path);
     add_option(&options, "driver", driver);
     add_option(&options, "name", name);
     config_info = xalloc(strlen(udi) + 5); /* "hal:" and NULL */
