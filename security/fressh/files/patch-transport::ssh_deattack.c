--- transport/ssh_deattack.c.orig	Sun May 11 22:27:05 2003
+++ transport/ssh_deattack.c	Sun May 11 22:27:06 2003
@@ -132,8 +132,8 @@
     n = l;
     h = (u_int32_t *) malloc(n * HASH_ENTRYSIZE);
     if (h == NULL) {
-      SSH_ERROR("Unable to allocate memory for CRC compensation
- 		attack detector: %s\n", strerror(errno));
+      SSH_ERROR("Unable to allocate memory for CRC compensation\n"
+ 		"attack detector: %s\n", strerror(errno));
       return -1;
     }
   } else
@@ -144,8 +144,8 @@
       h = (u_int32_t *) realloc(h, n * HASH_ENTRYSIZE);
 
       if (h == NULL) {
-        SSH_ERROR("Unable to allocate memory for CRC compensation
-                   attack detector: %s\n", strerror(errno));
+        SSH_ERROR("Unable to allocate memory for CRC compensation\n"
+                   "attack detector: %s\n", strerror(errno));
         return -1;                                  
       }                     
     }
