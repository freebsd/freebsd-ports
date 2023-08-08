--- src/datasource/domain.c.orig	2022-08-27 02:05:09 UTC
+++ src/datasource/domain.c
@@ -36,7 +36,9 @@
 #include   <errno.h>
 #include   <limits.h>
 #include   <stdio.h>
+#define __BSD_VISIBLE 1
 #include   <string.h>
+#undef __BSD_VISIBLE
 #include   <unistd.h>
 
 
@@ -44,7 +46,7 @@
 /*
  * Local defines
  */
-#define   HOST_NAME_BUF_SIZE    HOST_NAME_MAX + 2   // +1 for terminal \0 and +1 because we'll be adding a trailing dot
+#define   HOST_NAME_BUF_SIZE    _POSIX_HOST_NAME_MAX + 2   // +1 for terminal \0 and +1 because we'll be adding a trailing dot
 #define   HOSTS_PATH            "/etc/hosts"
 #define   HOSTS_LINE_SIZE_MAX   1024
 #define   HOSTS_LINE_POS_MAX    1023
@@ -76,12 +78,12 @@ int snoopy_datasource_domain (char * const result, __a
      * START: COPY FROM datasource/hostname
      */
     /* Get my hostname first */
-    retVal = gethostname(hostname, HOST_NAME_MAX);
+    retVal = gethostname(hostname, _POSIX_HOST_NAME_MAX);
     if (0 != retVal) {
         return snprintf(result, SNOOPY_DATASOURCE_MESSAGE_MAX_SIZE, "(error @ gethostname(): %d)", errno);
     }
 
-    // If hostname was something alien (longer than HOST_NAME_MAX), then the
+    // If hostname was something alien (longer than _POSIX_HOST_NAME_MAX), then the
     // last character may not be NULL (the behavior is unspecified).
     // Let's avoid any surprises and null-terminate at the end of this buffer.
     hostname[HOST_NAME_BUF_SIZE-1] = '\0';
