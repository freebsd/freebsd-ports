--- mp.h.orig	2008-02-24 18:56:07.000000000 +0100
+++ mp.h	2013-01-15 00:54:45.484476000 +0100
@@ -46,7 +46,9 @@
 
     if (pthread_attr_init(&attr)==0 &&
 	pthread_attr_setstacksize(&attr,stack_sz)==0 &&
+#if !defined(__DragonFly__)
 	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM)==0 &&
+#endif
 	pthread_create(&h,&attr,(void *(*)(void *))func,arg)==0 )
 	return (void *)h;
 
