--- lib/EIMIL/EIMILJournal.c	Mon Aug  2 23:39:10 2004
+++ lib/EIMIL/EIMILJournal.c	Thu Feb 17 01:55:38 2005
@@ -61,7 +61,6 @@
     pjh = NULL;
     pj = ped->pjst;
     for (i = 0; i < EIMIL_JOURNAL_MAX_SLOT_SIZE; i++) {
-        fprintf(stderr, "hoge\n");
         if (!pj) break;
 	if (pj->pv) EIMIL_RMREF(*pj->pv);
 	if ((pj->next - pj) < 0) pjh = pj->next;
