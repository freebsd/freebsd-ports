--- tw_osl_freebsd.c.orig	2024-04-04 10:43:09 UTC
+++ tw_osl_freebsd.c
@@ -67,8 +67,8 @@ static struct cdevsw twa_cdevsw = {
 	.d_name =	"twa",
 };
 
-static devclass_t	twa_devclass;
 
+
 /*
  * Function name:	twa_open
  * Description:		Called when the controller is opened.
@@ -194,7 +194,7 @@ static driver_t	twa_pci_driver = {
 	sizeof(struct twa_softc)
 };
 
-DRIVER_MODULE(twa, pci, twa_pci_driver, twa_devclass, 0, 0);
+DRIVER_MODULE(twa, pci, twa_pci_driver, 0, 0);
 MODULE_DEPEND(twa, cam, 1, 1, 1);
 MODULE_DEPEND(twa, pci, 1, 1, 1);
 
