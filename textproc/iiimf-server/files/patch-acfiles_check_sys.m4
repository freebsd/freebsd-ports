--- acfiles/check_sys.m4.orig	Thu Aug 12 18:01:23 2004
+++ acfiles/check_sys.m4	Wed Sep  8 16:15:39 2004
@@ -74,6 +74,11 @@
 ## Checks for thread library.
 	AC_CHECK_LIB(pthread, pthread_create, [ HAVE_LIBPTHREAD="yes" ])
 	AC_CHECK_LIB(thread, thr_create, [ HAVE_LIBUITHREAD="yes" ])
+
+	case "${target}" in
+		*freebsd*) HAVE_LIBPTHREAD="yes";;
+	esac
+
 	if test "X${HAVE_LIBPTHREAD}" = "Xyes" ; then
 		HAVE_THREAD="pthread"
 	elif test "X${HAVE_LIBUITHREAD}" = "Xyes" ; then
@@ -210,8 +215,6 @@
 		COMMON_CXX_CFLAGS="${COMMON_CXX_CFLAGS} -DLinux"
 		;;
 	    *freebsd*)
-		THREAD_LDFLAGS="-pthread"
-		PTHREAD_LIBS=""
 		;;
 	esac
 
@@ -249,9 +252,9 @@
 		THREAD_CXX_CFLAGS="-mt"
 		HAVE_THREAD="uithread"
 		;;
-	    *freebsd*@gcc:*)
-		THREAD_LDFLAGS="-pthread"
-		THREAD_LIBS=""
+	    *freebsd*)
+		THREAD_CXX_CFLAGS="${PTHREAD_CFLAGS}"
+		THREAD_LIBS="${PTHREAD_LIBS}"
 		HAVE_THREAD="freebsd-pthread"
 		;;
 	    *linux*)
