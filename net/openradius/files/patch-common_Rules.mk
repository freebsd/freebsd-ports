--- common/Rules.mk.orig 2024-05-23 14:07:34 UTC
+++ common/Rules.mk
@@ -29,7 +29,7 @@
 $(OBJS_$(d)):	$(d)/platform.h
 
 $(d)/common.a:	$(OBJS_$(d))
-		$(ARCHIVE)
+		$(AR)
 
 $(d)/platform.h: $(d)/Rules.mk
 		$(DEFHDR) $@ $(S_CF_U_INT32_T) $(S_CF_VSNPRINTF) \
