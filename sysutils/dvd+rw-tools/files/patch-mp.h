--- mp.h.orig	Mon Jan 16 11:34:56 2006
+++ mp.h	Thu Jan 19 20:22:30 2006
@@ -39,7 +39,9 @@
   pthread_attr_t attr;
 
     if (pthread_attr_init(&attr)==0 &&
+#if	!defined(__FreeBSD__) || __FreeBSD__ >= 5
 	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM)==0 &&
+#endif	/* FreeBSD 4 does not support PTHREAD_SCOPE_SYSTEM */
 	pthread_create(&h,&attr,(void *(*)(void *))func,arg)==0 )
 	return (void *)h;
 
