--- eventcomm.c.orig	Mon Aug  8 04:44:04 2005
+++ eventcomm.c	Sat Mar 18 18:54:22 2006
@@ -55,6 +55,7 @@
 static Bool
 event_query_is_touchpad(int fd)
 {
+#if 0
     int ret;
     unsigned long evbits[NBITS(KEY_MAX)];
 
@@ -83,6 +84,9 @@
 	return FALSE;
 
     return TRUE;
+#else
+    return FALSE;
+#endif
 }
 
 static Bool
