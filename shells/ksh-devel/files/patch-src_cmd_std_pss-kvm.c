--- src/cmd/std/pss-kvm.c.orig	2017-11-30 22:35:04 UTC
+++ src/cmd/std/pss-kvm.c
@@ -43,6 +43,9 @@ NoN(pss_kvm)
 #if _sys_proc
 #include <sys/proc.h>
 #endif
+#if _sys_user
+#include <sys/user.h>
+#endif
 #include <sys/sysctl.h>
 #include <sys/tty.h>
 
