--- config.m4.orig	Thu Sep  8 12:40:37 2005
+++ config.m4	Thu Sep  8 12:40:42 2005
@@ -114,17 +114,18 @@
   _SAVE_CPPFLAGS=$CPPFLAGS
   _SAVE_LDFLAGS=$LDFLAGS
   CPPFLAGS="$CPPFLAGS -I$LDAP_INCDIR"
+  LDFLAGS="$LDFLAGS $LDAP_SHARED_LIBADD"
   AC_CACHE_CHECK([for 3 arg ldap_set_rebind_proc], ac_cv_3arg_setrebindproc,
   [AC_TRY_COMPILE([#include <ldap.h>], [ldap_set_rebind_proc(0,0,0)],
   ac_cv_3arg_setrebindproc=yes, ac_cv_3arg_setrebindproc=no)])
   if test "$ac_cv_3arg_setrebindproc" = yes; then
     AC_DEFINE(HAVE_3ARG_SETREBINDPROC,1,[Whether 3 arg set_rebind_proc()])
   fi
-  CPPFLAGS=$_SAVE_CPPFLAGS
 
   dnl Solaris 2.8 claims to be 2004 API, but doesn't have
   dnl ldap_parse_reference() nor ldap_start_tls_s()
   AC_CHECK_FUNCS([ldap_parse_result ldap_parse_reference ldap_start_tls_s])
+  CPPFLAGS=$_SAVE_CPPFLAGS
   LDFLAGS=$_SAVE_LDFLAGS
   
   dnl
