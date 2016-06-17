Index: cmulocal/ucdsnmp.m4
diff -u cmulocal/ucdsnmp.m4.orig cmulocal/ucdsnmp.m4
--- cmulocal/ucdsnmp.m4.orig	Tue May 25 10:27:58 2004
+++ cmulocal/ucdsnmp.m4	Sat Dec 10 16:34:09 2005
@@ -31,9 +31,12 @@
 
     if test -n "$SNMP_LIBS" && test -n "$SNMP_PREFIX"; then
       CPPFLAGS="$CPPFLAGS -I${SNMP_PREFIX}/include"
-      LIB_UCDSNMP=$SNMP_LIBS
+      LIB_UCDSNMP="$SNMP_LIBS -lwrap"
+      PERLLIBDIR=`$PERL -e 'use Config; print "$Config{archlibexp}/CORE";'`
+      LDFLAGS_UCDSNMP="-L${PERLLIBDIR} -R${PERLLIBDIR}"
       AC_DEFINE(HAVE_NETSNMP,1,[Do we have Net-SNMP support?])
       AC_SUBST(LIB_UCDSNMP)
+      AC_SUBST(LDFLAGS_UCDSNMP)
       AC_MSG_RESULT(yes)
     else
       AC_MSG_RESULT(no)
@@ -59,7 +62,7 @@
     LIB_UCDSNMP=""
     if test "$with_snmp" != no; then
       AC_DEFINE(HAVE_UCDSNMP,1,[Do we have UCD-SNMP support?])
-      LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp"
+      LIB_UCDSNMP="-lucdagent -lucdmibs -lsnmp -lkvm -ldevstat -lwrap"
       AC_CHECK_LIB(rpm, rpmdbOpen,
 		 LIB_UCDSNMP="${LIB_UCDSNMP} -lrpm -lpopt",,-lpopt)
     fi
