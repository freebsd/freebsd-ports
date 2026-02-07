--- service/realm-samba-enroll.c.orig	2022-09-29 11:05:56 UTC
+++ service/realm-samba-enroll.c
@@ -29,6 +29,7 @@
 #include <glib/gstdio.h>
 
 #include <ldap.h>
+#include <unistd.h>
 
 #include <errno.h>
 #include <fcntl.h>
@@ -43,6 +44,11 @@
 #else
 #define SMBCLI_KERBEROS "-k"
 #define SMBCLI_CONF "-s"
+#endif
+
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
 #endif
 
 typedef struct {
