--- src/platform-headers.h.orig	2017-10-16 17:35:19 UTC
+++ src/platform-headers.h
@@ -97,10 +97,6 @@ typedef struct statfs procenv_mnt_type;
 #include <selinux/selinux.h>
 #endif
 
-#if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
-#endif
-
 #if defined (__GLIBC__)
 #include <sys/sysmacros.h>
 #endif
@@ -261,10 +257,6 @@ typedef struct statfs procenv_mnt_type;
 #include <sys/statvfs.h>
 #include <net/if.h>
 #include <link.h>
-
-#if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
-#endif
 
 #define PROCENV_CPU_TYPE     int
 #define PROCENV_CPU_SET_TYPE cpu_set_t
