--- kernel/freebsd/nic_uio/nic_uio.c.orig	2018-09-05 14:29:02 UTC
+++ kernel/freebsd/nic_uio/nic_uio.c
@@ -9,6 +9,7 @@
 #include <sys/kernel.h> /* types used in module initialization */
 #include <sys/conf.h> /* cdevsw struct */
 #include <sys/bus.h> /* structs, prototypes for pci bus stuff and DEVMETHOD */
+#include <sys/lock.h> /* used by vm_pager.h => MPASS() */
 #include <sys/rman.h>
 #include <sys/systm.h>
 #include <sys/rwlock.h>
