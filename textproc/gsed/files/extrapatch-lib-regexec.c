#
# Required for gcc 2.95 since it is pre-C99
# and doesn't handle the 'bool' datatype properly.
#
--- lib/regexec.c.orig	Sat Apr 15 20:53:36 2006
+++ lib/regexec.c	Sat Apr 15 21:17:03 2006
@@ -3296,8 +3296,7 @@
   reg_errcode_t err;
   int i, j, ch, need_word_trtable = 0;
   bitset_word_t elem, mask;
-  bool dests_node_malloced = false;
-  bool dest_states_malloced = false;
+  int dests_node_malloced = 0, dest_states_malloced = 0;
   int ndests; /* Number of the destination states from `state'.  */
   re_dfastate_t **trtable;
   re_dfastate_t **dest_states = NULL, **dest_states_word, **dest_states_nl;
@@ -3322,7 +3321,7 @@
       dests_alloc = re_malloc (struct dests_alloc, 1);
       if (BE (dests_alloc == NULL, 0))
 	return 0;
-      dests_node_malloced = true;
+      dests_node_malloced = 1;
     }
   dests_node = dests_alloc->dests_node;
   dests_ch = dests_alloc->dests_ch;
@@ -3371,7 +3370,7 @@
 	    free (dests_alloc);
 	  return 0;
 	}
-      dest_states_malloced = true;
+      dest_states_malloced = 1;
     }
   dest_states_word = dest_states + ndests;
   dest_states_nl = dest_states_word + ndests;
@@ -3576,7 +3575,7 @@
 	{
 	  if (constraint & NEXT_NEWLINE_CONSTRAINT)
 	    {
-	      bool accepts_newline = bitset_contain (accepts, NEWLINE_CHAR);
+	      int accepts_newline = bitset_contain (accepts, NEWLINE_CHAR);
 	      bitset_empty (accepts);
 	      if (accepts_newline)
 		bitset_set (accepts, NEWLINE_CHAR);
