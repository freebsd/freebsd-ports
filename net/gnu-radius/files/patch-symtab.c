--- radlib/symtab.c.orig	Tue Nov 27 12:13:36 2001
+++ radlib/symtab.c	Wed Apr 24 09:54:42 2002
@@ -307,6 +307,9 @@
 {
 	int i;
 	Symbol *sym, *next;
+
+	if (symtab->hash_num == -1)
+		return;
 	
 	for (i = 0; i < hash_size[symtab->hash_num]; i++) {
 		sym = symtab->sym[i];
