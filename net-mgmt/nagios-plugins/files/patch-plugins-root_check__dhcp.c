--- plugins-root/check_dhcp.c.orig	2014-06-26 16:17:12 UTC
+++ plugins-root/check_dhcp.c
@@ -326,7 +326,8 @@ int get_hardware_address(int sock,char *
 #elif defined(__bsd__)
 						/* King 2004	see ACKNOWLEDGEMENTS */
 
-        int                     mib[6], len;
+        int                     mib[6];
+        size_t                  len;
         char                    *buf;
         unsigned char           *ptr;
         struct if_msghdr        *ifm;
