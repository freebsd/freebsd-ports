--- build/rules.mak.orig	2020-02-14 09:48:27 UTC
+++ build/rules.mak
@@ -129,7 +129,7 @@ endif
 $(OBJDIR)/$(app).o: $(OBJDIRS) $(OBJS)
 	$(CROSS_COMPILE)ld -r -o $@ $(OBJS)
 
-$(OBJDIR)/$(app).ko: $(OBJDIR)/$(app).o
+$(OBJDIR)/$(app).ko: $(OBJDIR)/$(app).o | $(OBJDIRS)
 	@echo Creating kbuild Makefile...
 	@echo "# Our module name:" > $(OBJDIR)/Makefile
 	@echo 'obj-m += $(app).o' >> $(OBJDIR)/Makefile
@@ -154,27 +154,27 @@ $(OBJDIR)/$(app).ko: $(OBJDIR)/$(app).o
 ../lib/$(app).ko: $(LIB) $(OBJDIR)/$(app).ko
 	cp $(OBJDIR)/$(app).ko ../lib
 
-$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.m
+$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.m | $(OBJDIRS)
 	$(CC) $($(APP)_CFLAGS) \
 		$(CC_OUT)$(subst /,$(HOST_PSEP),$@) \
 		$(subst /,$(HOST_PSEP),$<) 
 
-$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.c
+$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.c | $(OBJDIRS)
 	$(CC) $($(APP)_CFLAGS) \
 		$(CC_OUT)$(subst /,$(HOST_PSEP),$@) \
 		$(subst /,$(HOST_PSEP),$<) 
 
-$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.S
+$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.S | $(OBJDIRS)
 	$(CC) $($(APP)_CFLAGS) \
 		$(CC_OUT)$(subst /,$(HOST_PSEP),$@) \
 		$(subst /,$(HOST_PSEP),$<) 
 
-$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.cpp
+$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.cpp | $(OBJDIRS)
 	$(CXX) $($(APP)_CXXFLAGS) \
 		$(CC_OUT)$(subst /,$(HOST_PSEP),$@) \
 		$(subst /,$(HOST_PSEP),$<)
 
-$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.cc
+$(OBJDIR)/%$(OBJEXT): $(SRCDIR)/%.cc | $(OBJDIRS)
 	$(CXX) $($(APP)_CXXFLAGS) \
 		$(CC_OUT)$(subst /,$(HOST_PSEP),$@) \
 		$(subst /,$(HOST_PSEP),$<)
