--- my_hdrs.h.orig	Thu Mar 23 11:32:02 2000
+++ my_hdrs.h	Sun Dec 15 05:10:26 2002
@@ -35,7 +35,6 @@
 
 /* other networking function */
 int inet_pton(int, const char *, void *);
-const char * inet_ntop(int, const void *, char *, size_t);
 void Inet_pton(int, const char *, void *);
 
 /* non-networking stuff */
