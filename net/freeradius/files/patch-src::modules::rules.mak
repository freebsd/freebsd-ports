--- src/modules/rules.mak.orig	Sun Jul 31 22:48:01 2005
+++ src/modules/rules.mak	Wed Oct  5 10:57:50 2005
@@ -96,7 +96,7 @@
 
 $(TARGET).la: $(DYNAMIC_OBJS)
 	$(LIBTOOL) --mode=link $(CC) -release $(RADIUSD_VERSION) \
-	-module $(LINK_MODE) $(LDFLAGS) $(RLM_LDFLAGS) \
+	-module $(LINK_MODE) $(CFLAGS) $(RLM_CFLAGS) $(LDFLAGS) $(RLM_LDFLAGS) \
 	-o $@ -rpath $(libdir) $^ $(RLM_LIBS) $(LIBS)
 
 #######################################################################
