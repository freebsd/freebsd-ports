--- src/Makefile.inc.orig	Thu Sep 30 05:29:05 2004
+++ src/Makefile.inc	Tue Oct  5 11:07:49 2004
@@ -1,8 +1,7 @@
 # gcc only
 CC=gcc
 
-PREFIX=/usr/local
-LOCALSTATEDIR=/var
+LOCALSTATEDIR=${PREFIX}/var
 TARGETNAME=unicornscan
 SENDERNAME=unisend
 LISTENERNAME=unilisten
@@ -23,10 +22,10 @@
 #LDADD=-lsocket -lnsl -ldl -lposix4 -lresolv
 
 # freebsd, netbsd example
-#LDADD=
+LDADD=
 
 # linux example
-LDADD=-ldl
+#LDADD=-ldl
 
 # selinux example
 #LDADD=-ldl -lselinux
