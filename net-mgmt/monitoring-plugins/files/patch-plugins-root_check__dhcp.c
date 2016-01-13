--- plugins-root/check_dhcp.c.orig	2015-10-16 09:06:18 UTC
+++ plugins-root/check_dhcp.c
@@ -323,7 +323,8 @@ int get_hardware_address(int sock,char *
 #elif defined(__bsd__)
 						/* King 2004	see ACKNOWLEDGEMENTS */
 
-        int                     mib[6], len;
+        int                     mib[6];
+        size_t                  len;
         char                    *buf;
         unsigned char           *ptr;
         struct if_msghdr        *ifm;
