--- libfreeipmi/src/driver/ipmi-kcs-driver.c.orig	2010-09-29 05:11:01.000000000 +0800
+++ libfreeipmi/src/driver/ipmi-kcs-driver.c	2010-10-01 17:51:46.000000000 +0800
@@ -485,7 +485,7 @@
 #ifdef __FreeBSD__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
-  if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
+  if (sysarch (I386_SET_IOPERM, (void *) (ctx->driver_address, 0x02, 0x01)))
     {
       KCS_ERRNO_TO_KCS_ERRNUM (ctx, errno);
       return (-1);
