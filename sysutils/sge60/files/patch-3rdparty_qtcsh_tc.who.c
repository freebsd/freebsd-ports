
$FreeBSD: /tmp/pcvs/ports/sysutils/sge60/files/patch-3rdparty_qtcsh_tc.who.c,v 1.1 2011-10-14 16:55:50 brooks Exp $

--- 3rdparty/qtcsh/tc.who.c.orig
+++ 3rdparty/qtcsh/tc.who.c
@@ -56,7 +56,7 @@
 #  define _PATH_UTMP UTMPX_FILE
 # endif /* _PATH_UTMP */
 # define utmp utmpx
-#  ifndef INTERIX
+#  if !defined(INTERIX) && !defined(FREEBSD)
 #   define ut_time ut_xtime
 #  else
 #   define ut_time ut_tv.tv_sec
