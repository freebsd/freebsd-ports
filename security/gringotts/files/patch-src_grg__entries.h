--- src/grg_entries.h.orig	2008-01-04 13:08:43 UTC
+++ src/grg_entries.h
@@ -24,7 +24,7 @@
 
 /* current element. */
 /* MUST BE USED ONLY BY grg_attachs.h !!!! */
-GList *current;
+extern GList *current;
 
 /* Appends a new entry to the list */
 void grg_entries_append (void);
