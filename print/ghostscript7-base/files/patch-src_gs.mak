--- src/gs.mak.orig	2015-08-21 22:03:26.487964000 +0900
+++ src/gs.mak	2015-08-21 22:04:09.624656000 +0900
@@ -235,7 +235,7 @@
 gconfig_h=$(GLGENDIR)$(D)gconfxx.h
 gconfigf_h=$(GLGENDIR)$(D)gconfxc.h
 
-all default : $(GS_XE)
+all default : $(GS_XE) $(GS_SHARED_OBJS)
 	$(NO_OP)
 
 # the distclean and maintainer-clean targets (if any)
@@ -248,6 +248,7 @@
 clean : mostlyclean
 	$(RM_) $(GSGEN)arch.h
 	$(RM_) $(GS_XE)
+	$(RM_) $(GS_SHARED_OBJS)
 
 #****** FOLLOWING IS WRONG, NEEDS TO BE PER-SUBSYSTEM ******
 mostlyclean : config-clean
