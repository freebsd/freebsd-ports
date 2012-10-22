--- base/gs.mak.orig	2012-08-08 17:01:36.000000000 +0900
+++ base/gs.mak	2012-10-14 02:29:03.000000000 +0900
@@ -437,7 +437,7 @@
 ld_tr=$(GLGENDIR)$(D)ld.tr
 $(ld_tr) : \
   $(GS_MAK) $(TOP_MAKEFILES) $(GLSRCDIR)$(D)version.mak $(GENCONF_XE) $(ECHOGS_XE) $(devs_tr) $(DEVS_ALL) $(GLGENDIR)$(D)libcore.dev
-	$(EXP)$(GENCONF_XE) $(devs_tr) -h $(gconfxx_h) $(CONFILES) $(CONFLDTR) $(ld_tr)
+	$(EXP)$(GENCONF_XE) $(devs_tr) -h /dev/stdout $(CONFILES) $(CONFLDTR) $(ld_tr) | awk 'BEGIN{j=0; p=1;} /jpeg_device/ {if(j++ > 0) p=0;} // { if(p==1) { print; } else { p=1 } }' > $(gconfxx_h)
 	$(EXP)$(ECHOGS_XE) -a $(gconfxx_h) $(GCONFIG_EXTRAS)
 
 $(gconfxx_h) : $(ld_tr)
