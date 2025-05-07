--- src/tss2-tcti/tcti-device.c.orig	2025-02-22 22:43:21 UTC
+++ src/tss2-tcti/tcti-device.c
@@ -58,7 +58,7 @@ static char *default_conf[] = {
 #include "util/log.h"
 
 static char *default_conf[] = {
-#ifdef __VXWORKS__
+#if defined(__VXWORKS__) || defined(__FreeBSD__)
     "/dev/tpm0"
 #else
     "/dev/tpmrm0",
