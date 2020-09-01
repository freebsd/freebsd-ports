--- src/modules/ldap/ldap.c.orig	2001-10-03 01:45:29 UTC
+++ src/modules/ldap/ldap.c
@@ -60,7 +60,10 @@
 #include "cache.h"
 
 #define CONFIG_FILE CONFDIR "/ldap.conf"
+/*
 #define MAPS "auto.home auto_home amd.home passwd.byname passwd.byuid group.byname group.bygid"
+*/
+#define MAPS "auto.home auto_home amd.home master.passwd.byname master.passwd.byuid passwd.byname passwd.byuid group.byname group.bygid"
 
 struct ldaprefs ldaprefs;
 
