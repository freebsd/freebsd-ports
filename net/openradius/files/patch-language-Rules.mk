--- language/Rules.mk.orig	Sun Oct 29 15:55:04 2006
+++ language/Rules.mk	Sun Oct 29 15:55:08 2006
@@ -31,7 +31,7 @@
 		$(COMP)
 
 $(d)/language.a: $(LIBOBJS_$(d))
-		$(ARCHIVE)
+		$(AR)
 
 $(d)/langtest:	LL_TGT := $(S_LL_CRYPT)
 $(d)/langtest:	$(TSTOBJS_$(d)) common/common.a
