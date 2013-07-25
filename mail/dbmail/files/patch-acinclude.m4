--- acinclude.m4.orig	2013-05-31 14:03:59.000000000 +0100
+++ acinclude.m4	2013-05-31 14:45:49.000000000 +0100
@@ -23,7 +23,7 @@
  SOCKETS:                   $SOCKETLIB
  MATH:                      $MATHLIB
  MHASH:                     $MHASHLIB
- LIBEVENT:                  $EVENTLIB
+ LIBEVENT:                  $ac_event_libs
  OPENSSL:                   $SSLLIB
  ZDB:                       $ZDBLIB
  JEMALLOC:                  $JEMALLOCLIB
@@ -342,13 +342,40 @@
 	fi
 ])
 
-AC_DEFUN([DM_CHECK_EVENT], [
-	AC_CHECK_HEADERS([event.h], [EVENTLIB="-levent_pthreads -levent"],[EVENTLIB="failed"], [#include <event2/event.h>])
-	if test [ "x$EVENTLIB" = "xfailed" ]; then
-		AC_MSG_ERROR([Could not find EVENT library.])
-	else
-		LDFLAGS="$LDFLAGS $EVENTLIB"
+AC_DEFUN([DM_CHECK_EVENT], [dnl
+AC_PATH_PROG(eventconfig,pkg-config)
+if test [ -z "$eventconfig" ]
+then
+	AC_MSG_ERROR([pkg-config executable not found. Make sure pkg-config is in your path])
+else
+	AC_MSG_CHECKING([Event headers])
+	ac_event_cflags=`${eventconfig} --cflags libevent_pthreads`
+	if test -z "$ac_event_cflags"
+	then
+		AC_MSG_RESULT([no])
+		AC_MSG_ERROR([Unable to locate event development files])
+	fi
+ 
+	CFLAGS="$CFLAGS $ac_event_cflags"
+	AC_MSG_RESULT([$ac_event_cflags])
+        AC_MSG_CHECKING([Event libraries])
+	ac_event_libs=`${eventconfig} --libs libevent_pthreads`
+	if test -z "$ac_event_libs"
+	then
+		AC_MSG_RESULT([no])
+		AC_MSG_ERROR([Unable to locate event libaries])
 	fi
+ 	ac_event_minvers="2.0"
+	AC_MSG_CHECKING([Event version >= $ac_event_minvers])
+	ac_event_vers=`${eventconfig}  --atleast-version=$ac_event_minvers libevent_pthreads>/dev/null && echo yes`
+	if test -z "$ac_event_vers"
+	then
+		AC_MSG_ERROR([At least Event version $ac_event_minvers is required.])
+	fi
+
+	LDFLAGS="$LDFLAGS $ac_event_libs"
+        AC_MSG_RESULT([$ac_event_libs])
+fi
 ])
 
 AC_DEFUN([DM_CHECK_SSL], [
