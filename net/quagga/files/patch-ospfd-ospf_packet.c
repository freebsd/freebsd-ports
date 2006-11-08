--- ospfd/ospf_packet.c.orig
+++ ospfd/ospf_packet.c
@@ -2712,25 +2712,9 @@ ospf_make_db_desc (struct ospf_interface
   /* Set DD Sequence Number. */
   stream_putl (s, nbr->dd_seqnum);
 
+  /* shortcut unneeded walk of (empty) summary LSDBs */
   if (ospf_db_summary_isempty (nbr))
-    {
-      /* Sanity check:
-       *
-       * Must be here either:
-       * - Initial DBD (ospf_nsm.c)
-       *   - M must be set
-       * or
-       * - finishing Exchange, and DB-Summary list empty
-       *   - from ospf_db_desc_proc()
-       *   - M must not be set
-       */
-      if (nbr->state >= NSM_Exchange)
-	assert (!IS_SET_DD_M(nbr->dd_flags));
-      else
-        assert (IS_SET_DD_M(nbr->dd_flags));
-
-      return length;
-    }
+    goto empty;
 
   /* Describe LSA Header from Database Summary List. */
   lsdb = &nbr->db_sum;
@@ -2785,9 +2769,17 @@ ospf_make_db_desc (struct ospf_interface
   /* Update 'More' bit */
   if (ospf_db_summary_isempty (nbr))
     {
-      UNSET_FLAG (nbr->dd_flags, OSPF_DD_FLAG_M);
-      /* Rewrite DD flags */
-      stream_putc_at (s, pp, nbr->dd_flags);
+empty:
+      if (nbr->state >= NSM_Exchange)
+        {
+          UNSET_FLAG (nbr->dd_flags, OSPF_DD_FLAG_M);
+          /* Rewrite DD flags */
+          stream_putc_at (s, pp, nbr->dd_flags);
+        }
+      else
+        {
+          assert (IS_SET_DD_M(nbr->dd_flags));
+        }
     }
   return length;
 }
