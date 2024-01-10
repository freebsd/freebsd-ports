--- cf/pthreads.m4.orig	2022-11-17 06:42:48.000000000 -0800
+++ cf/pthreads.m4	2022-11-17 15:04:24.219994000 -0800
@@ -34,7 +34,7 @@
     ;;
 *-*-freebsd*)
 	native_pthread_support=yes
-	PTHREAD_LIBADD="-pthread"
+	PTHREAD_LIBADD="-lpthread"
 	;;
 *-*-openbsd*)
 	native_pthread_support=yes
