--- x11/Subdir.mk.orig	Wed Oct 30 21:15:02 2002
+++ x11/Subdir.mk	Wed Oct 30 21:15:26 2002
@@ -110,8 +110,8 @@
 x11/pia          : LDFLAGS := $(DLFLAGS)
 
 # compile flags
-x11/complete-xaw.o   : CFLAGS += -DATHENA=1
-x11/complete-motif.o : CFLAGS += -DMOTIF=1
+#x11/complete-xaw.o   : CFLAGS += -DATHENA=1
+#x11/complete-motif.o : CFLAGS += -DMOTIF=1
 
 
 # i18n
@@ -122,12 +122,12 @@
 # local targets
 x11/complete-xaw.o:: x11/complete.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DATHENA=1
 	@$(fixup_deps)
 
 x11/complete-motif.o:: x11/complete.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DMOTIF=1
 	@$(fixup_deps)
 
 
