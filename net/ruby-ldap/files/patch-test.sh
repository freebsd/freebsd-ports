--- test/test.sh.orig	Wed Nov 22 01:21:08 2000
+++ test/test.sh	Wed Nov 22 02:12:48 2000
@@ -4,12 +4,12 @@
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
   SERVERLOG=serv.log
   LDAPDOPT="-d 2 -f $CONFIG -p $PORT"
@@ -18,12 +18,12 @@
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
   SERVERLOG=serv.log
   LDAPURL="ldap://127.0.0.1:$PORT/"
@@ -33,13 +33,13 @@
 'openldap2-ssl')
   # -- experimental -- OpenLDAP2 with SSL,SASL
   TESTDIR=./test/openldap2
-  LDAPD=/usr/local/openldap/libexec/slapd
+  LDAPD=!!PREFIX!!/libexec/slapd
   CONFIG=$TESTDIR/slapd-ssl.conf
   DBDIR=$TESTDIR/test-db
   PIDFILE=$DBDIR/slapd.pid
   PORT=6666
   SSLPORT=6667
-  RUBY=ruby-1.6
+  RUBY=!!RUBY!!
   LOGFILE=test.log
   SERVERLOG=serv.log
   LDAPURL="ldaps://127.0.0.1:$SSLPORT/ ldap://127.0.0.1:$PORT/"
@@ -133,4 +133,4 @@
 rm -rf $DBDIR
 if [ "$CERTFILE" != "" ]; then
   rm -f $CERTFILE $KEYFILE
-fi
+fi
