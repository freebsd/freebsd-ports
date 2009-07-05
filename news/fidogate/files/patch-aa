--- config.make.orig	2003-04-15 20:45:20.000000000 +0200
+++ config.make	2009-07-05 06:31:34.000000000 +0200
@@ -57,13 +57,13 @@
 
 # variable parameters, can be changed at run-time, DO NOT DELETE ANYTHING!!!
 DEFAULT_V_CONFIGDIR	= /etc/fidogate
-DEFAULT_V_LIBDIR	= /usr/lib/fidogate
-DEFAULT_V_BINDIR	= $(DEFAULT_V_LIBDIR)/bin
-DEFAULT_V_LOGDIR	= /var/log/fidogate
+DEFAULT_V_LIBDIR	= ${PREFIX}/libexec/fidogate
+DEFAULT_V_BINDIR	= ${PREFIX}/libexec/fidogate
+DEFAULT_V_LOGDIR	= /var/spool/fidogate/log
 DEFAULT_V_VARDIR	= /var/lib/fidogate
-DEFAULT_V_LOCKDIR	= /var/lock/fidogate
+DEFAULT_V_LOCKDIR	= /var/spool/fidogate/lock
 DEFAULT_V_SPOOLDIR	= /var/spool/fidogate
-DEFAULT_V_BTBASEDIR	= /var/spool/bt
+DEFAULT_V_BTBASEDIR	= /var/spool/fidogate/bt
 DEFAULT_V_INBOUND	= $(DEFAULT_V_BTBASEDIR)/in
 DEFAULT_V_PINBOUND	= $(DEFAULT_V_BTBASEDIR)/pin
 DEFAULT_V_UUINBOUND	= $(DEFAULT_V_BTBASEDIR)/uuin
@@ -87,7 +87,7 @@
 DEFAULT_F_NEWSVARDIR	= /var/lib/news
 # INN 1.7
 #DEFAULT_F_NEWSLIBDIR	= /usr/lib/news
-#DEFAULT_F_NEWSSPOOLDIR	= /var/spool/news
+#DEFAULT_F_NEWSSPOOLDIR	= /var/spool/news/articles
 # INN 2.2
 #DEFAULT_F_NEWSLIBDIR	= /usr/lib
 #DEFAULT_F_NEWSSPOOLDIR	= /var/spool/news/articles
@@ -149,7 +149,7 @@
 
 
 # The perl interpreter used by subst.pl
-PERL			= /usr/bin/perl
+PERL			= ${LOCALBASE}/bin/perl
 
 # Directory with sendmail m4 configuration files
 # RedHat 6.x
@@ -158,9 +158,9 @@
 SENDMAIL_CF_DIR		= /usr/share/sendmail-cf
 
 # Directories for installing documentation, not used by subst.pl
-INFODIR			= /usr/info
-HTMLDIR			= /html/fidogate
-HTMLLOGDIR		= /html/log
+INFODIR			= ${PREFIX}/share/doc/fidogate/info
+HTMLDIR			= ${PREFIX}/share/doc/fidogate/html
+HTMLLOGDIR		= ${PREFIX}/share/doc/fidogate/html
 
 # RedHat RPM related dirs
 RPMBASEDIR	= /usr/src/redhat
