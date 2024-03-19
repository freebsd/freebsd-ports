--- src/auth/basic/NIS/nis_support.h.orig	2024-03-04 05:45:51 UTC
+++ src/auth/basic/NIS/nis_support.h
@@ -8,9 +8,6 @@
 #ifndef SQUID_SRC_AUTH_BASIC_NIS_NIS_SUPPORT_H
 #define SQUID_SRC_AUTH_BASIC_NIS_NIS_SUPPORT_H
 
-#ifndef SQUID_SRC_AUTH_BASIC_NIS_NIS_SUPPORT_H
-#define SQUID_SRC_AUTH_BASIC_NIS_NIS_SUPPORT_H
-
 extern char * get_nis_password(char *user, char *nisdomain, char *nismap);
 
 #endif /* SQUID_SRC_AUTH_BASIC_NIS_NIS_SUPPORT_H */
