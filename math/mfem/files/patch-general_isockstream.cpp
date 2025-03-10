--- general/isockstream.cpp.orig	2024-09-08 17:21:14 UTC
+++ general/isockstream.cpp
@@ -86,7 +86,7 @@ int isockstream::establish()
          return (-1);
       }
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       if (bind(sfd, (const struct sockaddr *)rp->ai_addr, rp->ai_addrlen) < 0)
 #else
       if (bind(sfd, rp->ai_addr, rp->ai_addrlen) < 0)
