--- common/Subdir.mk.orig	Tue Jan  7 16:16:34 2003
+++ common/Subdir.mk	Sat Jan 18 00:44:45 2003
@@ -16,10 +16,10 @@
 	common/midictrl.o
 
 # RegEdit.c is good old K&R ...
-common/RegEdit.o: CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
-common/channel-no-x11.o: CFLAGS += -DNO_X11=1 
+#common/RegEdit.o: CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
+#common/channel-no-x11.o: CFLAGS += -DNO_X11=1 
 
 common/channel-no-x11.o: common/channel.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DNO_X11=1
 	@$(fixup_deps)
