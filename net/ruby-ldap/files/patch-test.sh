--- test/test.sh.orig	Sun Nov 19 02:46:14 2000
+++ test/test.sh	Sun Nov 19 06:55:30 2000
@@ -4,24 +4,24 @@
 'openldap1')
   # for OpenLDAP1
   TESTDIR=./test/openldap1
-  LDAPD=/usr/local/openldap-1.2.11/libexec/slapd
+  LDAPD=!!PREFIX!!/libexec/slapd
   CONFIG=$TESTDIR/slapd.conf
   DBDIR=$TESTDIR/test-db
   PIDFILE=$DBDIR/slapd.pid
   PORT=6666
-  RUBY=ruby-1.6
+  RUBY=!!RUBY!!
   LOGFILE=test.log
   LDAPDOPT="-d 2 -f $CONFIG -p $PORT"
   ;;
 'openldap2')
   # for OpenLDAP2
   TESTDIR=./test/openldap2
-  LDAPD=/usr/local/openldap/libexec/slapd
+  LDAPD=!!PREFIX!!/libexec/slapd
   CONFIG=$TESTDIR/slapd.conf
   DBDIR=$TESTDIR/test-db
   PIDFILE=$DBDIR/slapd.pid
   PORT=6666
-  RUBY=ruby-1.6
+  RUBY=!!RUBY!!
   LOGFILE=test.log
   LDAPURL=ldap://127.0.0.1:$PORT/
   LDAPDOPT="-d 2 -f $CONFIG -h $LDAPURL"
