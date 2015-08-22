--- contrib/contrib.mak.orig	2014-03-26 21:53:47.000000000 +0900
+++ contrib/contrib.mak	2014-08-25 00:49:19.000000000 +0900
@@ -943,7 +943,7 @@
 $(DEVOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(DEVCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(DEVOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(DEVOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(DEVCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
@@ -1095,3 +1095,5 @@
 ### ------------ Build/Install special features ------------ ###
 
 install-contrib-extras: extra-dmprt-install extra-upp-install
+
+include ${CONTRIBDIR}/epag.contrib.mak
