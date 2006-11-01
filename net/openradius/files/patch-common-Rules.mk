--- common/Rules.mk.orig	Sun Oct 29 15:53:42 2006
+++ common/Rules.mk	Sun Oct 29 15:53:45 2006
@@ -29,7 +29,7 @@
 $(OBJS_$(d)):	$(d)/platform.h
 
 $(d)/common.a:	$(OBJS_$(d))
-		$(ARCHIVE)
+		$(AR)
 
 $(d)/platform.h: $(d)/Rules.mk
 		$(DEFHDR) $@ $(S_CF_U_INT32_T) $(S_CF_VSNPRINTF) \
