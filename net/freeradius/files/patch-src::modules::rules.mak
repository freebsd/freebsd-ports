--- src/modules/rules.mak.orig	Sat Feb 19 14:43:30 2005
+++ src/modules/rules.mak	Sat Feb 19 14:45:14 2005
@@ -95,7 +95,7 @@
 
 $(TARGET).la: $(DYNAMIC_OBJS)
 	$(LIBTOOL) --mode=link $(CC) -release $(RADIUSD_VERSION) \
-	-module $(LINK_MODE) $(CFLAGS) $(RLM_CFLAGS) $(RLM_LDFLAGS) \
+	-module $(LINK_MODE) $(CFLAGS) $(RLM_CFLAGS) $(LDFLAGS) $(RLM_LDFLAGS) \
 	-o $@ -rpath $(libdir) $^ $(RLM_LIBS) $(LIBS)
 
 #######################################################################
