--- fake-rfc2553.h.orig	Sat Jan  8 17:32:31 2005
+++ fake-rfc2553.h	Sat Jan  8 17:32:59 2005
@@ -114,7 +114,7 @@
 # define NI_MAXHOST 1025
 #endif /* !NI_MAXHOST */
 
-#ifndef EAI_NODATA
+#if 0
 # define EAI_NODATA	1
 # define EAI_MEMORY	2
 # define EAI_NONAME	3
