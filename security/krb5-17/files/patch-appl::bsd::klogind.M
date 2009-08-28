--- appl/bsd/klogind.M.orig	2008-12-15 12:29:01.000000000 -0800
+++ appl/bsd/klogind.M	2009-08-28 13:13:28.000000000 -0700
@@ -13,7 +13,7 @@
 .B \-rcpPef
 ]
 [[ \fB\-w\fP[\fBip\fP|\fImaxhostlen\fP[\fB,\fP[\fBno\fP]\fBstriplocal\fP ]] ]
-[ \fB\-D\fP \fIport\fP ]
+[ \fB\-D\fP \fIport\fP ] [\fB\-L\fP \fIloginpath\fP]
 .SH DESCRIPTION
 .I Klogind
 is the server for the 
@@ -136,11 +136,9 @@
 .IP \fB\-M\ realm\fP
 Set the Kerberos realm to use.
 
-.IP \fB\-L\ login\fP
-Set the login program to use.  This option only has an effect if
-DO_NOT_USE_K_LOGIN was not defined when
-.I klogind
-was compiled.
+.IP \fB\-L\ loginpath\fP
+Specify pathname to an alternative login program.  Default: /usr/bin/login.
+KRB5_HOME/sbin/login.krb5 may be specified.
 
 .IP \fB\-D\ port\fP
 Run in standalone mode, listening on \fBport\fP.  The daemon will exit
