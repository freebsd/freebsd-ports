--- cmds.c.orig	2019-02-22 18:41:46 UTC
+++ cmds.c
@@ -65,7 +65,7 @@
 #endif
 
 void syncref(register struct enode *e);
-extern unsigned int shall_quit;
+extern int shall_quit;
 char insert_edit_submode;
 struct ent * freeents = NULL; // keep deleted ents around before sync_refs
 wchar_t interp_line[BUFFERSIZE];
