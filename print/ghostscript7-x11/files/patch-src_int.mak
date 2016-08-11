--- src/int.mak.orig	2003-01-17 00:49:04 UTC
+++ src/int.mak
@@ -953,10 +953,10 @@ $(PSOBJ)iccfont.$(OBJ) : $(PSSRC)iccfont
 
 # We select either iccinit0 or iccinit1 depending on COMPILE_INITS.
 
-$(PSOBJ)iccinit0.$(OBJ) : $(PSSRC)iccinit0.c $(stdpre_h)
+$(PSOBJ)iccinit0.$(OBJ) : $(arch_h) $(PSSRC)iccinit0.c $(stdpre_h)
 	$(PSCC) $(PSO_)iccinit0.$(OBJ) $(C_) $(PSSRC)iccinit0.c
 
-$(PSOBJ)iccinit1.$(OBJ) : $(PSOBJ)gs_init.$(OBJ)
+$(PSOBJ)iccinit1.$(OBJ) : $(arch_h) $(PSOBJ)gs_init.$(OBJ)
 	$(CP_) $(PSOBJ)gs_init.$(OBJ) $(PSOBJ)iccinit1.$(OBJ)
 
 # All the gs_*.ps files should be prerequisites of gs_init.c,
@@ -964,7 +964,7 @@ $(PSOBJ)iccinit1.$(OBJ) : $(PSOBJ)gs_ini
 $(PSGEN)gs_init.c : $(PSLIB)$(GS_INIT) $(GENINIT_XE) $(gconfig_h)
 	$(EXP)$(GENINIT_XE) -I $(PSLIB) $(GS_INIT) $(gconfig_h) -c $(PSGEN)gs_init.c
 
-$(PSOBJ)gs_init.$(OBJ) : $(PSGEN)gs_init.c $(stdpre_h)
+$(PSOBJ)gs_init.$(OBJ) : $(arch_h) $(PSGEN)gs_init.c $(stdpre_h)
 	$(PSCC) $(PSO_)gs_init.$(OBJ) $(C_) $(PSGEN)gs_init.c
 
 # ---------------- Stochastic halftone ---------------- #
