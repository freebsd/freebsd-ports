--- libfreeipmi/driver/ipmi-kcs-driver.c.orig	2012-01-03 03:25:58.000000000 +0800
+++ libfreeipmi/driver/ipmi-kcs-driver.c	2012-01-06 04:38:31.485000601 +0800
@@ -491,7 +491,7 @@
 #ifdef __FreeBSD__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
-  if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
+  if (sysarch (I386_SET_IOPERM, (void *) (ctx->driver_address, 0x02, 0x01)))
     {
       KCS_ERRNO_TO_KCS_ERRNUM (ctx, errno);
       return (-1);
