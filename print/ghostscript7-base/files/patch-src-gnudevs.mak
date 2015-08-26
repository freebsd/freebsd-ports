--- src/gnudevs.mak.orig	2003-02-10 03:12:48.000000000 +0900
+++ src/gnudevs.mak	2015-08-22 00:20:45.754922000 +0900
@@ -66,64 +66,6 @@
 $(DD)sxlcrt.dev : $(sxlcrt_) $(DD)page.dev
 	$(SETPDEV) $(DD)sxlcrt $(sxlcrt_)
 
-
-### -------------------- Gimp-Print (stp) driver -------------------###
-
-# To include this driver add '$(DD)stp.dev' to your DEVICE_DEVS
-# line and define 'STPLIB=gimpprint' in your top-level makefile.
-# See http://gimp-print.sourceforge.net/ for more information.
-
-stp_=$(GLOBJ)gdevstp.$(OBJ)
-
-$(DD)stp.dev : $(stp_) $(DD)page.dev
-	$(SETPDEV) $(DD)stp $(stp_)
-	$(ADDMOD) $(DD)stp -lib $(STPLIB)
-
-$(GLOBJ)gdevstp.$(OBJ) : $(GLSRC)gdevstp.c \
- $(gdevprn_h) $(gdevpccm_h) $(gsparam_h)
-	$(GLCC) $(GLO_)gdevstp.$(OBJ) $(C_) $(GLSRC)gdevstp.c
-
-
-### -------------- cdj850 - HP 850c Driver under development ------------- ###
-
-cdeskjet8_=$(GLOBJ)gdevcd8.$(OBJ) $(HPPCL)
-
-# Author: Uli Wortmann (uliw@erdw.ethz.ch), Martin Gerbershagen (ger@ulm.temic.de)
-# Printer: HP 670
-$(DD)cdj670.dev : $(cdeskjet8_) $(DD)page.dev
-	$(SETPDEV2) $(DD)cdj670 $(cdeskjet8_)
-
-# Author: Uli Wortmann (uliw@erdw.ethz.ch)
-# Printer: HP 850
-$(DD)cdj850.dev : $(cdeskjet8_) $(DD)page.dev
-	$(SETPDEV2) $(DD)cdj850 $(cdeskjet8_)
-
-# Author: Uli Wortmann (uliw@erdw.ethz.ch), Martin Gerbershagen (ger@ulm.temic.de)
-# Printer: HP 890
-$(DD)cdj890.dev : $(cdeskjet8_) $(DD)page.dev
-	$(SETPDEV2) $(DD)cdj890 $(cdeskjet8_)
-
-# Author: Uli Wortmann (uliw@erdw.ethz.ch), Martin Gerbershagen (ger@ulm.temic.de)
-# Printer: HP 1600
-$(DD)cdj1600.dev : $(cdeskjet8_) $(DD)page.dev
-	$(SETPDEV2) $(DD)cdj1600 $(cdeskjet8_)
-
-$(GLOBJ)gdevcd8.$(OBJ) : $(GLSRC)gdevcd8.c $(PDEVH) $(math__h)\
- $(gsparam_h) $(gxlum_h) $(gdevpcl_h)
-	$(GLCC) $(GLO_)gdevcd8.$(OBJ) $(C_) $(GLSRC)gdevcd8.c
-
-### -------------- cdj880 - HP 880c Driver under development ------------- ###
-### Since this driver is in the development phase it is not distributed    ###
-### with Ghostscript, but is available from                                ###
-###   http://www.proaxis.com/~mgelhaus/linux/software/hp880c/hp880c.html   ###
-
-### NOTE:  Depends on the presence of the cdj850 section above.            ###
-
-# Author: Matthew Gelhaus (mgelhaus@proaxis.com)
-# Printer: HP 880c
-$(DD)cdj880.dev : $(cdeskjet8_) $(DD)page.dev
-	$(SETPDEV2) $(DD)cdj880 $(cdeskjet8_)
-
 ### ------------- cdj970 - HP 970Cxi Driver under development ------------- ###
 
 cdeskjet9_=$(GLOBJ)gdevdj9.$(OBJ) $(HPPCL)
