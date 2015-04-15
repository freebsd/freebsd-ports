--- libpbe/include/Iconver.hh.orig	2008-10-25 12:17:29 UTC
+++ libpbe/include/Iconver.hh
@@ -36,7 +36,7 @@
 #include "Exception.hh"
 
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__sun__)
+#if defined(__OpenBSD__) || defined(__sun__)
 // Previously __APPLE__ was included in this list; presumably they have
 // changed their headers.  If you have an older system you may need to put
 // it back.
