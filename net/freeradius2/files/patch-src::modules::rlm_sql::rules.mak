--- src/modules/rlm_sql/drivers/rules.mak.orig	Sat Feb 19 15:07:59 2005
+++ src/modules/rlm_sql/drivers/rules.mak	Sat Feb 19 15:08:22 2005
@@ -93,7 +93,7 @@
 $(TARGET).la: $(DYNAMIC_OBJS)
 	$(LIBTOOL) --mode=link $(CC) -release $(RADIUSD_VERSION) \
 	-module $(LINK_MODE) $(CFLAGS) \
-	$(RLM_SQL_CFLAGS) -o $@ -rpath $(libdir) $^ $(RLM_SQL_LIBS)
+	$(RLM_SQL_CFLAGS) -o $@ -rpath $(libdir) $^ $(LDFLAGS) $(RLM_SQL_LIBS)
 
 #######################################################################
 #
