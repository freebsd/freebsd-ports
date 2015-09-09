--- plugins-root/check_dhcp.c.orig	2015-07-30 21:40:06 UTC
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
@@ -1194,7 +1195,7 @@ int call_getopt(int argc, char **argv){
 		        }
 	        }
 
-	return i;
+	return i+1;
         }
 
 
