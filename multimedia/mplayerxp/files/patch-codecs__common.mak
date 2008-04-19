--- codecs/common.mak.orig	Fri Dec  1 16:20:40 2006
+++ codecs/common.mak	Mon Dec 25 00:55:17 2006
@@ -22,7 +22,7 @@
 endif
 
 ifneq ($(TARGET_OS),WIN32)
-LDFLAGS+=-Xlinker -rpath=$(BINDIR)
+LDFLAGS+=-L${LOCALBASE}/lib -Xlinker -rpath=$(BINDIR)
 endif
 
 ifeq ($(TARGET_ARCH_SPARC64),yes)
@@ -42,9 +42,9 @@
 	$(RANLIB) $@
 
 $(SLIBNAME): $(SHARED_OBJS)
-ifneq ($(TARGET_OS),WIN32)
-	install -d  $(BINDIR)
-endif
+#ifneq ($(TARGET_OS),WIN32)
+#	install -d  $(BINDIR)
+#endif
 	$(CC) $(SHFLAGS) $(LDFLAGS) -o $@ $^ $(EXTRALIBS) $(EXTRAOBJS)
 #ifeq ($(TARGET_OS),WIN32)
 #	-lib /machine:i386 /def:$(@:.dll=.def)
