--- appl/bsd/klogind.M.orig	Wed Feb 28 14:06:43 2001
+++ appl/bsd/klogind.M	Mon Dec 31 21:22:27 2001
@@ -14,7 +14,7 @@
 .B \-kr54cpPef
 ]
 [[ \fB\-w\fP[\fBip\fP|\fImaxhostlen\fP[\fB,\fP[\fBno\fP]\fBstriplocal\fP ]] ]
-[ \fB\-D\fP \fIport\fP ]
+[ \fB\-D\fP \fIport\fP ] [\fB\-L\fP \fIloginpath\fP]
 .SH DESCRIPTION
 .I Klogind
 is the server for the 
@@ -107,6 +108,10 @@
 Beta5 (May 1995)--present bogus checksums that prevent Kerberos
 authentication from succeeding in the default mode.
 
+.IP \fB\-L\ loginpath\fP
+Specify pathname to an alternative login program.  Default: /usr/bin/login.
+KRB5_HOME/sbin/login.krb5 may be specified.
+
 
 .PP
 If the
@@ -157,12 +162,6 @@
 
 .IP \fB\-M\ realm\fP
 Set the Kerberos realm to use.
-
-.IP \fB\-L\ login\fP
-Set the login program to use.  This option only has an effect if
-DO_NOT_USE_K_LOGIN was not defined when
-.I klogind
-was compiled.
 
 .IP \fB\-D\ port\fP
 Run in standalone mode, listening on \fBport\fP.  The daemon will exit
