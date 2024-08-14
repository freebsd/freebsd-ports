--- language/Rules.mk.orig 2024-05-23 14:07:34 UTC
+++ language/Rules.mk
@@ -31,7 +31,7 @@
 		$(COMP)
 
 $(d)/language.a: $(LIBOBJS_$(d))
-		$(ARCHIVE)
+		$(AR)
 
 $(d)/langtest:	LL_TGT := $(S_LL_CRYPT)
 $(d)/langtest:	$(TSTOBJS_$(d)) common/common.a
