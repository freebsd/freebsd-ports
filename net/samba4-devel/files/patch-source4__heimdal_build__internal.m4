--- ./source4/heimdal_build/internal.m4.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/heimdal_build/internal.m4	2010-01-24 21:49:26.000000000 +0000
@@ -77,8 +77,7 @@
 	ttyname.h				\
 	netinet/in.h				\
 	netinet/in6.h				\
-	netinet6/in6.h				\
-	libintl.h
+	netinet6/in6.h
 ])
 
 AC_CHECK_FUNCS([				\
@@ -180,12 +179,6 @@
 
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
