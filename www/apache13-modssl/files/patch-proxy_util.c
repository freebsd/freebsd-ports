--- src/modules/proxy/proxy_util.c.orig	Tue Feb 17 22:52:22 2004
+++ src/modules/proxy/proxy_util.c	Fri Jun 11 10:24:12 2004
@@ -545,8 +545,8 @@
                 n = ap_bread(f, buf, buf_size);
             }
             else {
-                n = ap_bread(f, buf, MIN((int)buf_size,
-                                         (int)(len - total_bytes_rcvd)));
+                n = ap_bread(f, buf, MIN((size_t)buf_size,
+                                         (size_t)(len - total_bytes_rcvd)));
             }
         }
 
