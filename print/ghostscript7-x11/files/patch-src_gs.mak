--- src/gs.mak.orig	2003-01-28 12:02:09 UTC
+++ src/gs.mak
@@ -235,7 +235,7 @@ GENINIT_XE=$(AUXGEN)geninit$(XEAUX)
 gconfig_h=$(GLGENDIR)$(D)gconfxx.h
 gconfigf_h=$(GLGENDIR)$(D)gconfxc.h
 
-all default : $(GS_XE)
+all default : $(GS_XE) $(GS_SHARED_OBJS)
 	$(NO_OP)
 
 # the distclean and maintainer-clean targets (if any)
@@ -248,6 +248,7 @@ realclean : clean
 clean : mostlyclean
 	$(RM_) $(GSGEN)arch.h
 	$(RM_) $(GS_XE)
+	$(RM_) $(GS_SHARED_OBJS)
 
 #****** FOLLOWING IS WRONG, NEEDS TO BE PER-SUBSYSTEM ******
 mostlyclean : config-clean
