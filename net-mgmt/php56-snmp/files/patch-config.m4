--- config.m4.orig	2018-08-31 12:19:23 UTC
+++ config.m4
@@ -18,7 +18,6 @@ if test "$PHP_SNMP" != "no"; then
 
   if test -x "$SNMP_CONFIG"; then
     SNMP_LIBS=`$SNMP_CONFIG --netsnmp-libs`
-    SNMP_LIBS="$SNMP_LIBS `$SNMP_CONFIG --external-libs`"
     SNMP_PREFIX=`$SNMP_CONFIG --prefix`
     snmp_full_version=`$SNMP_CONFIG --version`
     ac_IFS=$IFS
