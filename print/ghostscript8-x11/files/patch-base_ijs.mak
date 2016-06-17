--- base/ijs.mak.orig	2007-06-05 22:23:38 UTC
+++ base/ijs.mak
@@ -41,7 +41,7 @@ IJS_MAK=$(GLSRC)ijs.mak
 ijs.clean : ijs.config-clean ijs.clean-not-config-clean
 
 ### WRONG.  MUST DELETE OBJ AND GEN FILES SELECTIVELY.
-ijs.clean-not-config-clean :
+ijs.clean-not-config-clean : $(ECHOGS_XE)
 #	echo $(IJSSRC) $(IJSGEN) $(IJSOBJ) $(IJSO_)
 	$(EXP)$(ECHOGS_XE) $(IJSSRC) $(IJSGEN) $(IJSOBJ) $(IJSO_)
 	$(RM_) $(IJSOBJ)*.$(OBJ)
@@ -61,7 +61,7 @@ ijs_h=$(IJSSRC)ijs.h
 ijs_client_h=$(IJSSRC)$(D)ijs_client.h
 ijs_server_h=$(IJSSRC)$(D)ijs_server.h
 
-$(IJSOBJ)ijs.$(OBJ) : $(IJSSRC)ijs.c $(IJSDEP) $(ijs_h)
+$(IJSOBJ)ijs.$(OBJ) : $(ECHOGS_XE) $(IJSSRC)ijs.c $(IJSDEP) $(ijs_h)
 #	echo $(IJS_CCFLAGS)
 	$(EXP)$(ECHOGS_XE) $(IJS_CCFLAGS)
 	$(IJS_CC) $(IJSO_)ijs.$(OBJ) $(C_) $(IJSSRC)ijs.c
