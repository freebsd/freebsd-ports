--- base/gs.mak.orig	2010-05-23 15:46:23.000000000 +0900
+++ base/gs.mak	2010-05-23 15:57:37.000000000 +0900
@@ -415,7 +415,7 @@
 ld_tr=$(GLGENDIR)$(D)ld.tr
 $(ld_tr) : \
   $(GS_MAK) $(TOP_MAKEFILES) $(GLSRCDIR)$(D)version.mak $(GENCONF_XE) $(ECHOGS_XE) $(devs_tr) $(DEVS_ALL) $(GLGENDIR)$(D)libcore.dev
-	$(EXP)$(GENCONF_XE) $(devs_tr) -h $(gconfig_h) $(CONFILES) $(CONFLDTR) $(ld_tr)
+	$(EXP)$(GENCONF_XE) $(devs_tr) -h /dev/stdout $(CONFILES) $(CONFLDTR) $(ld_tr) | awk 'BEGIN{j=0; p=1;} /jpeg_device/ {if(j++ > 0) p=0;} // {if(p==1) { print; } else { p=1 } }' > $(gconfig_h)
 	$(EXP)$(ECHOGS_XE) -a $(gconfig_h) $(GCONFIG_EXTRAS)
 
 $(gconfig_h) : $(ld_tr)
