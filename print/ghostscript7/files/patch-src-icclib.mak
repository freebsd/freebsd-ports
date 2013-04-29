--- src/icclib.mak.orig	2013-04-30 02:10:16.000000000 +0900
+++ src/icclib.mak	2013-04-30 02:10:26.000000000 +0900
@@ -73,7 +73,7 @@
 
 icc_h=$(ICCSRC)$(D)icc.h $(ICCSRC)$(D)icc$(ICCPROFVER).h
 
-$(ICCOBJ)icc.$(OBJ) : $(ICCSRC)icc.c $(ICCDEP) $(icc_h)
+$(ICCOBJ)icc.$(OBJ) : ${ECHOGS_XE} $(ICCSRC)icc.c $(ICCDEP) $(icc_h)
 #	echo $(ICC_CCFLAGS)
 	$(EXP)$(ECHOGS_XE) $(ICC_CCFLAGS)
 	$(ICC_CC) $(ICCO_)icc.$(OBJ) $(C_) $(ICCSRC)icc.c
