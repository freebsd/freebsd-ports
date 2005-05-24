--- acfiles/check_sys.m4.orig	Mon May  9 15:28:20 2005
+++ acfiles/check_sys.m4	Mon May  9 15:32:07 2005
@@ -203,6 +203,13 @@
 		    CXX=${CC}
 		fi
 		;;
+	    cc*:*)
+		DEBUG_CFLAGS="${DEBUG_CFLAGS} -ggdb"
+		DEBUG_CXXFLAGS="${DEBUG_CXXFLAGS} -g"
+		COMMON_CFLAGS="${COMMON_CFLAGS} -Wall"
+		SHLIBCFLAGS='-fpic'
+		SHLIBLDFLAGS='-shared'
+		;;
 	    *)
 		DEBUG_CXX_CFLAGS="${DEBUG_CXX_CFLAGS} -g"
 		;;
@@ -249,8 +256,8 @@
 		COMMON_CXX_CFLAGS="${COMMON_CXX_CFLAGS} -DLinux"
 		;;
 	    *freebsd*)
-		THREAD_LDFLAGS="-pthread"
-		PTHREAD_LIBS=""
+		THREAD_LDFLAGS=""
+		PTHREAD_LIBS="${PTHREAD_LIBS}"
 		;;
 	esac
 
@@ -288,9 +295,9 @@
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
