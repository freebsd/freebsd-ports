--- acfiles/check_sys.m4.orig	Tue Sep 14 13:31:27 2004
+++ acfiles/check_sys.m4	Wed Mar  2 08:39:25 2005
@@ -203,6 +203,11 @@
 		    CXX=${CC}
 		fi
 		;;
+	    cc*:*)
+		COMMON_CFLAGS="${COMMON_CFLAGS} -Wall"
+		SHLIBCFLAGS='-fpic'
+		SHLIBLDFLAGS='-shared'
+		;;
 	    *)
 		DEBUG_CXX_CFLAGS="${DEBUG_CXX_CFLAGS} -g"
 		;;
@@ -249,8 +254,8 @@
 		COMMON_CXX_CFLAGS="${COMMON_CXX_CFLAGS} -DLinux"
 		;;
 	    *freebsd*)
-		THREAD_LDFLAGS="-pthread"
-		PTHREAD_LIBS=""
+		THREAD_LDFLAGS=""
+		PTHREAD_LIBS="${PTHREAD_LIBS}"
 		;;
 	esac
 
@@ -288,9 +293,9 @@
 		THREAD_CXX_CFLAGS="-mt"
 		HAVE_THREAD="uithread"
 		;;
-	    *freebsd*@gcc:*)
-		THREAD_LDFLAGS="-pthread"
-		THREAD_LIBS=""
+	    *freebsd*@cc:*|*freebsd*@gcc:*)
+		THREAD_LDFLAGS=""
+		THREAD_LIBS="${PTHREAD_LIBS}"
 		HAVE_THREAD="freebsd-pthread"
 		;;
 	    *linux*)
