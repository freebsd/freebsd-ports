--- gwee.c.orig	Thu Jul  5 10:41:27 2007
+++ gwee.c	Thu Jul  5 10:41:48 2007
@@ -2767,8 +2767,8 @@
             #endif
             return 1;
         }
-        (uint32_t)binary_ip = ((uint32_t *)he->h_addr_list[0])[0];
-        (uint32_t)xored_ip = ((uint32_t *)he->h_addr_list[0])[0] ^ XOR;
+        binary_ip = ((uint32_t *)he->h_addr_list[0])[0];
+        xored_ip = ((uint32_t *)he->h_addr_list[0])[0] ^ XOR;
 
         /* save ip in ascii dot notation form */
         snprintf(ascii_ip, sizeof(ascii_ip), "%u.%u.%u.%u",

