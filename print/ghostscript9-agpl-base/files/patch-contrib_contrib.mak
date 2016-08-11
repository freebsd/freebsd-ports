--- contrib/contrib.mak.orig	2015-03-30 08:21:24 UTC
+++ contrib/contrib.mak
@@ -943,7 +943,7 @@ $(DD)dmprt.dev : $(dmprt_) $(DD)page.dev
 $(DEVOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(DEVCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(DEVOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(DEVOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(DEVCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
@@ -1095,3 +1095,5 @@ extra-upp-install:
 ### ------------ Build/Install special features ------------ ###
 
 install-contrib-extras: extra-dmprt-install extra-upp-install
+
+include ${CONTRIBDIR}/epag.contrib.mak
