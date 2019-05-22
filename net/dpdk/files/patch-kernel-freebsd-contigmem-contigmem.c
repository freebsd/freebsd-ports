--- kernel/freebsd/contigmem/contigmem.c.orig	2018-09-05 14:29:02 UTC
+++ kernel/freebsd/contigmem/contigmem.c
@@ -9,9 +9,12 @@
 #include <sys/bio.h>
 #include <sys/bus.h>
 #include <sys/conf.h>
+#include <sys/eventhandler.h>
 #include <sys/kernel.h>
+#include <sys/lock.h>
 #include <sys/malloc.h>
 #include <sys/module.h>
+#include <sys/mutex.h>
 #include <sys/proc.h>
 #include <sys/rwlock.h>
 #include <sys/systm.h>
