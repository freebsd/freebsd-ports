--- x11/Subdir.mk.orig	2020-05-15 23:32:25 UTC
+++ x11/Subdir.mk
@@ -117,8 +117,8 @@ x11/v4lctl       : LDFLAGS := $(DLFLAGS)
 x11/pia          : LDFLAGS := $(DLFLAGS)
 
 # compile flags
-x11/complete-xaw.o   : CFLAGS += -DATHENA=1
-x11/complete-motif.o : CFLAGS += -DMOTIF=1
+#x11/complete-xaw.o   : CFLAGS += -DATHENA=1
+#x11/complete-motif.o : CFLAGS += -DMOTIF=1
 
 
 # i18n
@@ -129,12 +129,12 @@ MOTV-app  := $(patsubst %,x11/MoTV.%.ad,$(LANGUAGES))
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
 
 
