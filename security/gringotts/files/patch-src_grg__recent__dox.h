--- src/grg_recent_dox.h.orig	2008-01-04 13:08:43 UTC
+++ src/grg_recent_dox.h
@@ -24,7 +24,7 @@
 
 #define GRG_RECENT_LIMIT 	6
 
-GSList *grg_recent_dox;
+extern GSList *grg_recent_dox;
 
 void grg_recent_dox_init (void);
 void grg_recent_dox_deinit (void);
