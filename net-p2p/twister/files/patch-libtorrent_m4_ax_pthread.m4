--- libtorrent/m4/ax_pthread.m4.orig	2014-06-20 21:38:49.000000000 +0200
+++ libtorrent/m4/ax_pthread.m4	2014-06-21 16:58:22.000000000 +0200
@@ -318,7 +318,7 @@
         #
         if test x"$done" = xno; then
            AC_MSG_CHECKING([whether -lpthread fixes that])
-           LIBS="-lpthread $PTHREAD_LIBS $save_LIBS"
+           LIBS="$PTHREAD_LIBS $save_LIBS"
            AC_TRY_LINK([#include <pthread.h>],
               [pthread_t th; pthread_join(th, 0);
               pthread_attr_init(0); pthread_cleanup_push(0, 0);
@@ -327,7 +327,7 @@
 
            if test "x$done" = xyes; then
               AC_MSG_RESULT([yes])
-              PTHREAD_LIBS="-lpthread $PTHREAD_LIBS"
+              PTHREAD_LIBS="$PTHREAD_LIBS"
            else
               AC_MSG_RESULT([no])
            fi
