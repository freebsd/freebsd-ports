--- x11/Subdir.mk.orig	Mon Jan 12 18:56:17 2004
+++ x11/Subdir.mk	Mon Feb  9 18:49:10 2004
@@ -15,7 +15,7 @@
 TARGETS-x11 += \
 	x11/motv
 endif
-ifeq ($(FOUND_MOTIF)$(FOUND_ZVBI),yesyes)
+ifeq ($(FOUND_MOTIF)$(NOT_WORKINGFOUND_ZVBI),yesyes)
 TARGETS-x11 += \
 	x11/mtt
 endif
@@ -116,8 +116,8 @@
 x11/pia          : LDFLAGS := $(DLFLAGS)
 
 # compile flags
-x11/complete-xaw.o   : CFLAGS += -DATHENA=1
-x11/complete-motif.o : CFLAGS += -DMOTIF=1
+#x11/complete-xaw.o   : CFLAGS += -DATHENA=1
+#x11/complete-motif.o : CFLAGS += -DMOTIF=1
 
 
 # i18n
@@ -128,12 +128,12 @@
 # local targets
 x11/complete-xaw.o: x11/complete.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DATHENA=1
 	@$(fixup_deps)
 
 x11/complete-motif.o: x11/complete.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DMOTIF=1
 	@$(fixup_deps)
 
 
