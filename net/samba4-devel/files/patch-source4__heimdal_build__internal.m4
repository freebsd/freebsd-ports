--- ./source4/heimdal_build/internal.m4.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/heimdal_build/internal.m4	2009-07-12 02:39:36.000000000 +0000
@@ -68,8 +68,7 @@
 	ttyname.h				\
 	netinet/in.h				\
 	netinet/in6.h				\
-	netinet6/in6.h				\
-	libintl.h
+	netinet6/in6.h
 ])
 
 AC_CHECK_FUNCS([				\
@@ -171,12 +170,6 @@
 
 SMB_EXT_LIB(OPENPTY,[${OPENPTY_LIBS}],[${OPENPTY_CFLAGS}],[${OPENPTY_CPPFLAGS}],[${OPENPTY_LDFLAGS}])
 
-AC_CHECK_LIB_EXT(intl, INTL_LIBS, gettext)
-
-SMB_ENABLE(INTL,YES)
-
-SMB_EXT_LIB(INTL, $INTL_LIBS)
-
 smb_save_LIBS=$LIBS
 RESOLV_LIBS=""
 LIBS=""
