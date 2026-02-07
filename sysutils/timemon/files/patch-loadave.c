--- loadave.c.orig	2008-05-25 19:48:17.000000000 +0000
+++ loadave.c
@@ -31,7 +31,7 @@ int la_read(unsigned long long *times)
   return LA_NOERR;
 }
 
-#elif defined( __FreeBSD__ ) 
+#elif defined( __FreeBSD__ ) || defined ( __DragonFly__ )
 
 #include <sys/types.h>
 #include <sys/errno.h>
