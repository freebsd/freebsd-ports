--- src/external/ldap.m4.orig	2020-03-17 13:31:28 UTC
+++ src/external/ldap.m4
@@ -32,8 +32,7 @@ test "$with_ldap" != "yes" && { AC_CHECK_LIB(ldap, lda
 test "$with_ldap" != "yes" && { AC_CHECK_LIB(ldap, ldap_open, [with_ldap=yes with_ldap_lber=yes], , -llber) }
 test "$with_ldap" != "yes" && { AC_CHECK_LIB(ldap, ldap_open, [with_ldap=yes with_ldap_lber=yes with_ldap_krb=yes], , -llber -lkrb) }
 test "$with_ldap" != "yes" && { AC_CHECK_LIB(ldap, ldap_open, [with_ldap=yes with_ldap_lber=yes with_ldap_krb=yes with_ldap_des=yes], , -llber -lkrb -ldes) }
-CFLAGS=$SAVE_CFLAGS
-LIBS=$SAVE_LIBS
+
 dnl Recently, we need -lber even though the main routines are elsewhere,
 dnl because otherwise we get link errors w.r.t. ber_pvt_opt_on. So just
 dnl check for that (it's a variable not a fun but that doesn't seem to
@@ -41,6 +40,9 @@ test "$with_ldap_lber" != "yes" && { AC_CHECK_LIB(lber
 dnl stick it in always shouldn't hurt, I don't think) ... #### Someone who
 dnl #### understands LDAP needs to fix this properly.
 test "$with_ldap_lber" != "yes" && { AC_CHECK_LIB(lber, ber_pvt_opt_on, with_ldap_lber=yes) }
+
+CFLAGS=$SAVE_CFLAGS
+LIBS=$SAVE_LIBS
 
 if test "$with_ldap" = "yes"; then
   if test "$with_ldap_des" = "yes" ; then
