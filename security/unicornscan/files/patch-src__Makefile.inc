--- src/Makefile.inc.orig	2004-09-30 10:29:05 UTC
+++ src/Makefile.inc
@@ -1,14 +1,13 @@
 # gcc only
-CC=gcc
+CC?=gcc
 
-PREFIX=/usr/local
-LOCALSTATEDIR=/var
+LOCALSTATEDIR=${PREFIX}/var
 TARGETNAME=unicornscan
 SENDERNAME=unisend
 LISTENERNAME=unilisten
 
 # its fine to do almost anything here, just dont remove the includes
-MYCFLAGS=-O1 -ggdb -Wall -Wshadow -Wcast-align -Wcast-qual -Wchar-subscripts -Wno-deprecated-declarations -Wformat-security -Wimplicit -Wsign-compare -Wuninitialized -Wunused -Wwrite-strings -I. -rdynamic -I../libs/fake/include -I/usr/local/include -L/usr/local/lib -DPREFIX=\"$(PREFIX)\" -DLOCALSTATEDIR=\"$(LOCALSTATEDIR)\" -DTARGETNAME=\"$(TARGETNAME)\" -DSENDERNAME=\"$(SENDERNAME)\" -DLISTENERNAME=\"$(LISTENERNAME)\"
+MYCFLAGS:=$(CFLAGS) -Wall -Wshadow -Wcast-align -Wcast-qual -Wchar-subscripts -Wno-deprecated-declarations -Wformat-security -Wimplicit -Wsign-compare -Wuninitialized -Wunused -Wwrite-strings -I. -rdynamic -I../libs/fake/include -I/usr/local/include -L/usr/local/lib -DPREFIX=\"$(PREFIX)\" -DLOCALSTATEDIR=\"$(LOCALSTATEDIR)\" -DTARGETNAME=\"$(TARGETNAME)\" -DSENDERNAME=\"$(SENDERNAME)\" -DLISTENERNAME=\"$(LISTENERNAME)\"
 
 # sometimes you dont have a link to gmake, if your make _is_ gmake, you can use make then, but we need GNU make (for now)
 MAKE=gmake
@@ -26,7 +25,7 @@ MAKE=gmake
 #LDADD=
 
 # linux example
-LDADD=-ldl
+#LDADD=-ldl
 
 # selinux example
 #LDADD=-ldl -lselinux
