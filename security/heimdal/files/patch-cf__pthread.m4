--- cf/pthreads.m4.orig	2010-10-27 11:11:58.000000000 +0200
+++ cf/pthreads.m4	2010-10-27 11:12:20.000000000 +0200
@@ -30,12 +30,9 @@
 	dnl heim_threads.h knows this
 	PTHREAD_LIBADD="-lpthread"
 	;;
-*-*-freebsd[[56]]*)
+*-*-freebsd[[56789]]*)
 	native_pthread_support=yes
-	;;
-*-*-freebsd[[789]]*)
-	native_pthread_support=yes
-	PTHREADS_LIBADD="-lpthread"
+	PTHREADS_LIBADD="-pthread"
 	;;
 *-*-openbsd*)
 	native_pthread_support=yes
