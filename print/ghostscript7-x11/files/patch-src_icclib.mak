--- src/icclib.mak.orig	2003-01-17 00:49:04 UTC
+++ src/icclib.mak
@@ -73,7 +73,7 @@ $(ICCGEN)icclib.dev : $(ICCLIB_MAK) $(EC
 
 icc_h=$(ICCSRC)$(D)icc.h $(ICCSRC)$(D)icc$(ICCPROFVER).h
 
-$(ICCOBJ)icc.$(OBJ) : $(ICCSRC)icc.c $(ICCDEP) $(icc_h)
+$(ICCOBJ)icc.$(OBJ) : ${ECHOGS_XE} $(ICCSRC)icc.c $(ICCDEP) $(icc_h)
 #	echo $(ICC_CCFLAGS)
 	$(EXP)$(ECHOGS_XE) $(ICC_CCFLAGS)
 	$(ICC_CC) $(ICCO_)icc.$(OBJ) $(C_) $(ICCSRC)icc.c
