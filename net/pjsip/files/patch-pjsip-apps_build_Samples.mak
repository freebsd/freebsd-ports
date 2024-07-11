--- pjsip-apps/build/Samples.mak.orig	2024-06-06 12:41:28 UTC
+++ pjsip-apps/build/Samples.mak
@@ -63,7 +63,7 @@ endif
 .PHONY: $(EXES)
 .PHONY: $(PJSUA2_EXES)
 
-all: $(EXES) $(PJSUA2_EXES)
+all: $(EXES)
 
 $(EXES):
 	$(MAKE) --no-print-directory -f $(RULES_MAK) SAMPLE_SRCDIR=$(SRCDIR) SAMPLE_OBJS=$@.o SAMPLE_CFLAGS="$(_CFLAGS)" SAMPLE_CXXFLAGS="$(_CXXFLAGS)" SAMPLE_LDFLAGS="$(_LDFLAGS)" SAMPLE_EXE=$@ APP=SAMPLE app=sample $(subst /,$(HOST_PSEP),$(BINDIR)/$@)
