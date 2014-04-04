--- libpromises/expand.c.orig	2014-03-31 18:24:39.000000000 +0000
+++ libpromises/expand.c	2014-03-31 18:25:10.000000000 +0000
@@ -787,6 +787,7 @@
             ScopeNewSpecial(ctx, "this", "promise_linenumber", number, DATA_TYPE_STRING);
         }
 
+        ScopeNewSpecial(ctx, "this", "promiser", pp->promiser, DATA_TYPE_STRING);
         snprintf(v, CF_MAXVARSIZE, "%d", (int) getuid());
         ScopeNewSpecial(ctx, "this", "promiser_uid", v, DATA_TYPE_INT);
         snprintf(v, CF_MAXVARSIZE, "%d", (int) getgid());
