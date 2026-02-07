--- bsm.c.orig	2014-01-14 22:51:19 UTC
+++ bsm.c
@@ -330,7 +330,7 @@ bsm_copy_states(struct bsm_sequence *bs_
 	 * Make sure that we initialize the new tailq head to NULL
 	 * otherwise we would be recursively adding states.
 	 */
-	dprintf("%s: copying states from sequence %p\n", __func__, bs_old);
+	d_printf("%s: copying states from sequence %p\n", __func__, bs_old);
 	TAILQ_INIT(&bs_new->bs_mhead);
 	TAILQ_FOREACH(bm, &bs_old->bs_mhead, bm_glue) {
 		bm2 = calloc(1, sizeof(*bm2));
@@ -361,7 +361,7 @@ bsm_free_sequence(struct bsm_sequence *b
 {
 	struct bsm_state *bm;
 
-	dprintf("%s: freeing sequence %p\n", __func__, bs);
+	d_printf("%s: freeing sequence %p\n", __func__, bs);
 	assert((bs->bs_seq_flags & BSM_SEQUENCE_DYNAMIC) != 0);
 	bsm_free_raw_data(bs);
 	while (!TAILQ_EMPTY(&bs->bs_mhead)) {
@@ -421,7 +421,7 @@ bsm_sequence_clone(struct bsm_sequence *
 		bsmtrace_error(0, "%s: calloc failed", __func__);
 		return (NULL);
 	}
-	dprintf("%u:%s: sequence %p cloned and linked\n",
+	d_printf("%u:%s: sequence %p cloned and linked\n",
 	    time(NULL), bs->bs_label, bs_new);
 	*bs_new = *bs;
 	/*
@@ -506,7 +506,7 @@ bsm_sequence_scan(struct bsm_record_data
 			bs->bs_seq_flags |= BSM_SEQUENCE_DESTROY;
 			continue;
 		}
-		dprintf("%s: state transition cur=%p\n", bs->bs_label,
+		d_printf("%s: state transition cur=%p\n", bs->bs_label,
 		    TAILQ_NEXT(bm, bm_glue));
 		bs->bs_cur_state = TAILQ_NEXT(bm, bm_glue);
 	}
@@ -529,7 +529,7 @@ bsm_sequence_scan(struct bsm_record_data
 			bsm_log_sequence(bs, bd);
 			continue;
 		}
-		dprintf("%d:%s: state transition\n", time(NULL), bs->bs_label);
+		d_printf("%d:%s: state transition\n", time(NULL), bs->bs_label);
 		subj = bsm_get_subj(bs, bd);
 		bs_dyn = bsm_sequence_clone(bs, subj, bd);
 		if (bs_dyn == NULL)
@@ -555,7 +555,7 @@ bsm_loop(char *atrail)
 		bsmtrace_error(1, "%s: %s", opts.aflag, strerror(errno));
 	if (strcmp(opts.aflag, DEFAULT_AUDIT_TRAIL) == 0)
 		audit_pipe_fd = fileno(fp);
-	dprintf("opened '%s' for audit monitoring\n", opts.aflag);
+	d_printf("opened '%s' for audit monitoring\n", opts.aflag);
 	/*
 	 * Process the BSM record, one token at a time.
 	 */
