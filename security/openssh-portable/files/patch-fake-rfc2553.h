--- openbsd-compat/fake-rfc2553.h.orig	Fri Feb 11 08:32:13 2005
+++ openbsd-compat/fake-rfc2553.h	Sat Mar 19 21:27:33 2005
@@ -113,7 +113,7 @@
 # define NI_MAXHOST 1025
 #endif /* !NI_MAXHOST */
 
-#ifndef EAI_NODATA
+#ifndef EAI_MEMORY
 # define EAI_NODATA	1
 # define EAI_MEMORY	2
 # define EAI_NONAME	3
