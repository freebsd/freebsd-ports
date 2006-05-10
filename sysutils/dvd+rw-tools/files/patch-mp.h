--- mp.h.orig	Wed May 10 16:01:28 2006
+++ mp.h	Wed May 10 16:06:04 2006
@@ -40,7 +40,9 @@
 
     if (pthread_attr_init(&attr)==0 &&
 	pthread_attr_setstacksize(&attr,64*1024)==0 &&
+#if !defined(__FreeBSD__) || __FreeBSD_version >= 500000
 	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM)==0 &&
+#endif /* FreeBSD 4 does not support PTHREAD_SCOPE_SYSTEM */
 	pthread_create(&h,&attr,(void *(*)(void *))func,arg)==0 )
 	return (void *)h;
 
