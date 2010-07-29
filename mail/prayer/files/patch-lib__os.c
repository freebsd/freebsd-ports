--- ./lib/os.c.orig	2010-07-28 16:25:44.919661109 +0200
+++ ./lib/os.c	2010-07-28 16:26:35.810521675 +0200
@@ -238,8 +238,6 @@
         results[j++] = sockfd;
     }
 
-    freeaddrinfo(ai);
-
     return(results);
 }
 
