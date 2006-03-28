--- src/modules/rules.mak.orig	Mon Mar 27 15:43:04 2006
+++ src/modules/rules.mak	Mon Mar 27 15:44:11 2006
@@ -112,7 +112,7 @@
 
 $(TARGET).la: $(LT_OBJS)
 	$(LIBTOOL) --mode=link $(CC) -release $(RADIUSD_VERSION) \
-	-module $(LINK_MODE) $(LDFLAGS) $(RLM_LDFLAGS) -o $@     \
+	-module $(LINK_MODE) $(CFLAGS) $(RLM_CFLAGS) $(LDFLAGS) $(RLM_LDFLAGS) -o $@ \
 	-rpath $(libdir) $^ $(top_builddir)/src/lib/libradius.la \
 	$(RLM_LIBS) $(LIBS)
 
