--- Make.inc.orig	2008-06-10 08:48:03.000000000 -0500
+++ Make.inc	2008-06-10 08:49:11.000000000 -0500
@@ -3,15 +3,15 @@
 #
 #
 
-PREFIX  = /usr/local/squid
-BINDIR	= $(PREFIX)/libexec/
+PREFIX  = /usr/local
+BINDIR	= $(PREFIX)/libexec/squid/
 MANDIR  = $(PREFIX)/man/man8
 MANEXT	= .8
-CONFDIR  = $(PREFIX)/etc
+CONFDIR  = $(PREFIX)/etc/squid/
 
 INCLUDES       = radius.h md5.h
 
-ALL:	squid_radius_auth
+all:	squid_radius_auth
 
 
 attrprint.o: attrprint.c $(INCLUDES)
