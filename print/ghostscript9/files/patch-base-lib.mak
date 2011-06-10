--- base/lib.mak.orig	2011-06-10 13:41:36.000000000 +0900
+++ base/lib.mak	2011-06-10 13:42:59.000000000 +0900
@@ -25,7 +25,7 @@
 GLI_=$(GLGENDIR) $(II)$(GLSRCDIR)
 GLF_=
 GLCCFLAGS=$(I_)$(GLI_)$(_I) $(GLF_)
-GLCC=$(CC_) $(GLCCFLAGS)
+GLCC=$(GLCCSHARED)
 GLJCC=$(CC_) $(I_)$(GLI_) $(II)$(JI_)$(_I) $(JCF_) $(GLF_)
 GLZCC=$(CC_) $(I_)$(GLI_) $(II)$(ZI_)$(_I) $(ZCF_) $(GLF_)
 GLJBIG2CC=$(CC_) $(I_)$(GLI_) $(II)$(JB2I_)$(_I) $(JB2CF_) $(GLF_)
