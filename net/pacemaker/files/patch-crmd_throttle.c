--- crmd/throttle.c.orig	2016-01-14 21:43:08 UTC
+++ crmd/throttle.c
@@ -389,7 +389,7 @@ throttle_mode(void)
     unsigned int blocked = 0;
     enum throttle_state_e mode = throttle_none;
 
-#ifdef ON_SOLARIS
+#if defined(ON_BSD) || defined(ON_SOLARIS)
     return throttle_none;
 #endif
 
