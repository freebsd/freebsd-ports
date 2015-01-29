--- mbgclock/mbgclock_main.c.orig	2015-01-10 10:47:02.000000000 -0500
+++ mbgclock/mbgclock_main.c	2015-01-10 10:47:17.000000000 -0500
@@ -135,7 +135,7 @@
  * attach routine when we create the /dev entry.
  */
 int
-mbgclock_open( struct cdev *dev, int oflags, int devtype, d_thread_t *td )
+mbgclock_open( struct cdev *dev, int oflags, int devtype, struct thread *td )
 {
   struct mbgclock_softc *psc = dev->si_drv1;
   PCPS_DDEV *pddev = psc->pddev;
@@ -152,7 +152,7 @@
 
 
 int
-mbgclock_close( struct cdev *dev, int fflag, int devtype, d_thread_t *td )
+mbgclock_close( struct cdev *dev, int fflag, int devtype, struct thread *td )
 {
   struct mbgclock_softc *psc = dev->si_drv1;
   PCPS_DDEV *pddev = psc->pddev;
