--- libtests/build.mk.orig	2015-11-10 17:48:52 UTC
+++ libtests/build.mk
@@ -40,4 +40,4 @@ $(foreach B,$(BINS_libtests),$(eval \
 
 $(foreach B,$(BINS_libtests),$(eval \
   libtests/$(OUTPUT_DIR)/$(call binname,$(B)): $(OBJS_$(B)) ; \
-	$(call makebin,$(OBJS_$(B)),$$@,$(LDFLAGS) $(LDFLAGS_libqpdf),$(LIBS) $(LIBS_libqpdf))))
+	$(call makebin,$(OBJS_$(B)),$$@,$(LDFLAGS) $(LDFLAGS_libqpdf),$(LIBS_libqpdf) $(LIBS))))
