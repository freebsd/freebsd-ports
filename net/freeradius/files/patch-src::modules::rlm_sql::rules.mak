--- src/modules/rlm_sql/drivers/rules.mak.orig	Mon Mar 27 15:39:02 2006
+++ src/modules/rlm_sql/drivers/rules.mak	Mon Mar 27 15:39:29 2006
@@ -100,8 +100,8 @@
 
 $(TARGET).la: $(LT_OBJS)
 	$(LIBTOOL) --mode=link $(CC) -release $(RADIUSD_VERSION) \
-	-module $(LINK_MODE) $(LDFLAGS) $(RLM_SQL_LDFLAGS) -o $@ \
-	-rpath $(libdir) $^ $(RLM_SQL_LIBS)
+	-module $(LINK_MODE) $(CFLAGS) $(RLM_SQL_LDFLAGS) -o $@ \
+	-rpath $(libdir) $^ $(RLM_SQL_LIBS) $(LDFLAGS)
 
 #######################################################################
 #
