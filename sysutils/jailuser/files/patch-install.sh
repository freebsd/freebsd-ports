--- ../install.sh.orig Fri Oct 26 09:37:07 2001
+++ ../install.sh      Sun Jun 13 23:00:48 2004
@@ -23,7 +23,7 @@
 #
 ##############################################################################
 
-TMPFILE=/tmp/jail.tmp
+TMPFILE=jail.tmp
 
 # ----------------------------------------------------------------------------
 
@@ -63,16 +63,16 @@
 
 gen_jail_conf() {
 
-cp etc/jail.conf /tmp/jail.conf.tmp
+cp etc/jail.conf jail.conf.tmp
 
-parse_tag /tmp/jail.conf.tmp __VERSION__    $1
-parse_tag /tmp/jail.conf.tmp __ARCH__       $2
-parse_tag /tmp/jail.conf.tmp __DEBUG__      $3
-parse_tag /tmp/jail.conf.tmp __INSTALLDIR__ $4
-
-mv /tmp/jail.conf.tmp /tmp/jail.conf
-install_file /tmp/jail.conf $4/etc $5 $6 $7
-rm /tmp/jail.conf
+parse_tag jail.conf.tmp __VERSION__    $1
+parse_tag jail.conf.tmp __ARCH__       $2
+parse_tag jail.conf.tmp __DEBUG__      $3
+parse_tag jail.conf.tmp __INSTALLDIR__ $4
+
+mv jail.conf.tmp jail.conf.sample
+install_file jail.conf.sample $4/etc $5 $6 $7
+rm jail.conf.sample
 
 }
 
@@ -80,13 +80,13 @@
 
 gen_libjail() {
 
-cp lib/libjail.pm /tmp/libjail.pm.tmp
+cp lib/libjail.pm libjail.pm.tmp
 
-parse_tag /tmp/libjail.pm.tmp __INSTALLDIR__ $1
+parse_tag libjail.pm.tmp __INSTALLDIR__ $1
 
-mv /tmp/libjail.pm.tmp /tmp/libjail.pm
-install_file /tmp/libjail.pm $1/lib $2 $3 $4
-rm /tmp/libjail.pm
+mv libjail.pm.tmp libjail.pm
+install_file libjail.pm $1/lib $2 $3 $4
+rm libjail.pm
 
 }
 
@@ -94,14 +94,14 @@
 
 gen_mkenv() {
 
-cp bin/mkjailenv /tmp/mkjailenv.tmp
+cp bin/mkjailenv mkjailenv.tmp
 
-parse_tag /tmp/mkjailenv.tmp __INSTALLDIR__ $1
-parse_tag /tmp/mkjailenv.tmp __PERL__ $2
+parse_tag mkjailenv.tmp __INSTALLDIR__ $1
+parse_tag mkjailenv.tmp __PERL__ $2
 
-mv /tmp/mkjailenv.tmp /tmp/mkjailenv
-install_file /tmp/mkjailenv $1/bin $3 $4 $5
-rm /tmp/mkjailenv
+mv mkjailenv.tmp mkjailenv
+install_file mkjailenv $1/bin $3 $4 $5
+rm mkjailenv
 
 }
 
@@ -109,14 +109,14 @@
 
 gen_addjailsw() {
 
-cp bin/addjailsw /tmp/addjailsw.tmp
+cp bin/addjailsw addjailsw.tmp
 
-parse_tag /tmp/addjailsw.tmp __INSTALLDIR__ $1
-parse_tag /tmp/addjailsw.tmp __PERL__ $2
+parse_tag addjailsw.tmp __INSTALLDIR__ $1
+parse_tag addjailsw.tmp __PERL__ $2
 
-mv /tmp/addjailsw.tmp /tmp/addjailsw
-install_file /tmp/addjailsw $1/bin $3 $4 $5
-rm /tmp/addjailsw
+mv addjailsw.tmp addjailsw
+install_file addjailsw $1/bin $3 $4 $5
+rm addjailsw
 
 }
 
@@ -125,14 +125,14 @@
 
 gen_addjailuser() {
 
-cp bin/addjailuser /tmp/addjailuser.tmp
+cp bin/addjailuser addjailuser.tmp
 
-parse_tag /tmp/addjailuser.tmp __INSTALLDIR__ $1
-parse_tag /tmp/addjailuser.tmp __PERL__ $2
+parse_tag addjailuser.tmp __INSTALLDIR__ $1
+parse_tag addjailuser.tmp __PERL__ $2
 
-mv /tmp/addjailuser.tmp /tmp/addjailuser
-install_file /tmp/addjailuser $1/bin $3 $4 $5
-rm /tmp/addjailuser
+mv addjailuser.tmp addjailuser
+install_file addjailuser $1/bin $3 $4 $5
+rm addjailuser
 
 }
 
@@ -165,7 +165,7 @@
 ROOTID=$6
 ROOTGID=$7
 
-install_file ./bin/jail $INSTALLDIR/bin 4755 $ROOTID $ROOTGID
+install_file ./bin/jailuser $INSTALLDIR/bin 4755 $ROOTID $ROOTGID
 gen_jail_conf $VERSION $ARCH $DEBUG $INSTALLDIR 755 $ROOTID $ROOTGID
 gen_libjail $INSTALLDIR 755 $ROOTID $ROOTGID  
 
