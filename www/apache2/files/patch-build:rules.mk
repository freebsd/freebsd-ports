--- build/rules.mk.orig	Sun Apr  8 01:06:22 2001
+++ build/rules.mk	Sun Apr  8 01:05:46 2001
@@ -172,9 +172,9 @@
 all-p: $(targets)
 install-p: $(targets) $(install_targets)
 	@if test -n '$(PROGRAMS)'; then \
-		test -d $(bindir) || $(MKINSTALLDIRS) $(bindir); \
+		test -d $(sbindir) || $(MKINSTALLDIRS) $(sbindir); \
 		for i in "$(PROGRAMS)"; do \
-			$(INSTALL_PROGRAM) $$i $(bindir); \
+			$(INSTALL_PROGRAM) $$i $(sbindir); \
 		done; \
 	fi
 
