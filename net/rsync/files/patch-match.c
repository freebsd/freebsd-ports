--- match.c.orig
+++ match.c
@@ -166,7 +166,9 @@
 	OFF_T offset, aligned_offset, end;
 	int32 k, want_i, aligned_i, backup;
 	char sum2[MAX_DIGEST_LEN];
+	int32 consecutive_false_offsets = 0;
 	uint32 s1, s2, sum;
+	uchar last_false_flags = 0;
 	int more;
 	schar *map;
 
@@ -203,6 +205,8 @@
 
 	do {
 		int done_csum2 = 0;
+		int matched_block = 0;
+		const char *last_false_sum2 = NULL;
 		uint32 hash_entry;
 		int32 i, *prev;
 		int32 chain_len = 0;
@@ -214,14 +218,18 @@
 
 		if (tablesize == TRADITIONAL_TABLESIZE) {
 			hash_entry = SUM2HASH2(s1,s2);
-			if ((i = hash_table[hash_entry]) < 0)
+			if ((i = hash_table[hash_entry]) < 0) {
+				consecutive_false_offsets = 0;
 				goto null_hash;
+			}
 			sum = (s1 & 0xffff) | (s2 << 16);
 		} else {
 			sum = (s1 & 0xffff) | (s2 << 16);
 			hash_entry = BIG_SUM2HASH(sum);
-			if ((i = hash_table[hash_entry]) < 0)
+			if ((i = hash_table[hash_entry]) < 0) {
+				consecutive_false_offsets = 0;
 				goto null_hash;
+			}
 		}
 		prev = &hash_table[hash_entry];
 
@@ -237,11 +245,21 @@
 				*prev = s->sums[i].chain;
 				continue;
 			}
-			prev = &s->sums[i].chain;
-
-			if (sum != s->sums[i].sum1)
+            l = (int32)MIN((OFF_T)s->blength, len-offset);
+			if (sum != s->sums[i].sum1 || l != s->sums[i].len) {
+				prev = &s->sums[i].chain;
 				continue;
+			}
 
+			if (last_false_sum2
+			 && (!(s->sums[i].flags & SUMFLG_SAME_OFFSET)
+			  || (last_false_flags & SUMFLG_SAME_OFFSET))
+			 && memcmp(sum2_at(s, i), last_false_sum2, s->s2length) == 0) {
+				*prev = s->sums[i].chain;
+				continue;
+			}
+			prev = &s->sums[i].chain;
+
 			/* Bound the work spent on a single pathological hash
 			 * bucket.  If this weak checksum matches more than
 			 * MAX_CHAIN_LEN records, stop scanning and treat this
@@ -249,11 +267,6 @@
 			 * is sent literally, never corrupted. */
 			if (++chain_len > MAX_CHAIN_LEN)
 				break;
-
-			/* also make sure the two blocks are the same length */
-			l = (int32)MIN((OFF_T)s->blength, len-offset);
-			if (l != s->sums[i].len)
-				continue;
 
 			if (DEBUG_GTE(DELTASUM, 3)) {
 				rprintf(FINFO,
@@ -269,6 +282,8 @@
 
 			if (memcmp(sum2, sum2_at(s, i), s->s2length) != 0) {
 				false_alarms++;
+				last_false_sum2 = sum2_at(s, i);
+				last_false_flags = s->sums[i].flags;
 				continue;
 			}
 
@@ -341,8 +356,29 @@
 			s1 = sum & 0xFFFF;
 			s2 = sum >> 16;
 			matches++;
+			matched_block = 1;
+			consecutive_false_offsets = 0;
 			break;
 		} while ((i = s->sums[i].chain) >= 0);
+		/* If we computed a strong checksum (weak collision) and the entire
+		 * chain failed to match, don't let repeated collisions force a
+		 * 1-byte walk with a full strong-checksum calculation on every byte. */
+		if (!matched_block && (done_csum2 || chain_len > MAX_CHAIN_LEN)) {
+			if (++consecutive_false_offsets >= 4 && k > 1) {
+				OFF_T skip = MIN((OFF_T)(k - 1), end - 1 - offset);
+				if (skip > 0) {
+					offset += skip;
+					k = (int32)MIN((OFF_T)s->blength, len-offset);
+					map = (schar *)map_ptr(buf, offset, k);
+					sum = get_checksum1((char *)map, k);
+					s1 = sum & 0xFFFF;
+					s2 = sum >> 16;
+				}
+				consecutive_false_offsets = 3;
+			}
+		}
+		else if (!matched_block)
+			consecutive_false_offsets = 0;
 
 	  null_hash:
 		backup = (int32)(offset - last_match);
