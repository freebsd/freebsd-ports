Index: src/racoon/isakmp_frag.c
===================================================================
RCS file: /cvsroot/src/crypto/dist/ipsec-tools/src/racoon/isakmp_frag.c,v
retrieving revision 1.5
retrieving revision 1.7
diff -p -u -r1.5 -r1.7
--- src/racoon/isakmp_frag.c	22 Apr 2009 11:24:20 -0000	1.5
+++ src/racoon/isakmp_frag.c	23 Jul 2017 05:40:27 -0000	1.7
@@ -1,4 +1,4 @@
-/*	$NetBSD: isakmp_frag.c,v 1.5 2009/04/22 11:24:20 tteras Exp $	*/
+/*	$NetBSD: isakmp_frag.c,v 1.7 2017/07/23 05:40:27 christos Exp $	*/
 
 /* Id: isakmp_frag.c,v 1.4 2004/11/13 17:31:36 manubsd Exp */
 
@@ -173,6 +173,43 @@ vendorid_frag_cap(gen)
 	return ntohl(hp[MD5_DIGEST_LENGTH / sizeof(*hp)]);
 }
 
+static int 
+isakmp_frag_insert(struct ph1handle *iph1, struct isakmp_frag_item *item)
+{
+	struct isakmp_frag_item *pitem = NULL;
+	struct isakmp_frag_item *citem = iph1->frag_chain;
+
+	/* no frag yet, just insert at beginning of list */
+	if (iph1->frag_chain == NULL) {
+		iph1->frag_chain = item;
+		return 0;
+	}
+
+	do {
+		/* duplicate fragment number, abort (CVE-2016-10396) */
+		if (citem->frag_num == item->frag_num)
+			return -1;
+
+		/* need to insert before current item */
+		if (citem->frag_num > item->frag_num) {
+			if (pitem != NULL)
+				pitem->frag_next = item;
+			else
+				/* insert at the beginning of the list  */
+				iph1->frag_chain = item;
+			item->frag_next = citem;
+			return 0;
+		}
+
+		pitem = citem;
+		citem = citem->frag_next;
+	} while (citem != NULL);
+
+	/* we reached the end of the list, insert */
+	pitem->frag_next = item;
+	return 0;
+}
+
 int 
 isakmp_frag_extract(iph1, msg)
 	struct ph1handle *iph1;
@@ -224,39 +261,43 @@ isakmp_frag_extract(iph1, msg)
 	item->frag_next = NULL;
 	item->frag_packet = buf;
 
-	/* Look for the last frag while inserting the new item in the chain */
-	if (item->frag_last)
-		last_frag = item->frag_num;
+	/* Check for the last frag before inserting the new item in the chain */
+	if (item->frag_last) {
+		/* if we have the last fragment, indices must match */
+		if (iph1->frag_last_index != 0 &&
+		    item->frag_last != iph1->frag_last_index) {
+			plog(LLV_ERROR, LOCATION, NULL,
+			     "Repeated last fragment index mismatch\n");
+			racoon_free(item);
+			vfree(buf);
+			return -1;
+		}
 
-	if (iph1->frag_chain == NULL) {
-		iph1->frag_chain = item;
-	} else {
-		struct isakmp_frag_item *current;
+		last_frag = iph1->frag_last_index = item->frag_num;
+	}
 
-		current = iph1->frag_chain;
-		while (current->frag_next) {
-			if (current->frag_last)
-				last_frag = item->frag_num;
-			current = current->frag_next;
-		}
-		current->frag_next = item;
+	/* insert fragment into chain */
+	if (isakmp_frag_insert(iph1, item) == -1) {
+		plog(LLV_ERROR, LOCATION, NULL,
+		    "Repeated fragment index mismatch\n");
+		racoon_free(item);
+		vfree(buf);
+		return -1;
 	}
 
-	/* If we saw the last frag, check if the chain is complete */
+	/* If we saw the last frag, check if the chain is complete
+	 * we have a sorted list now, so just walk through */
 	if (last_frag != 0) {
+		item = iph1->frag_chain;
 		for (i = 1; i <= last_frag; i++) {
-			item = iph1->frag_chain;
-			do {
-				if (item->frag_num == i)
-					break;
-				item = item->frag_next;
-			} while (item != NULL);
-
+			if (item->frag_num != i)
+				break;
+			item = item->frag_next;
 			if (item == NULL) /* Not found */
 				break;
 		}
 
-		if (item != NULL) /* It is complete */
+		if (i > last_frag) /* It is complete */
 			return 1;
 	}
 		
@@ -291,15 +332,9 @@ isakmp_frag_reassembly(iph1)
 	}
 	data = buf->v;
 
+	item = iph1->frag_chain;
 	for (i = 1; i <= frag_count; i++) {
-		item = iph1->frag_chain;
-		do {
-			if (item->frag_num == i)
-				break;
-			item = item->frag_next;
-		} while (item != NULL);
-
-		if (item == NULL) {
+		if (item->frag_num != i) {
 			plog(LLV_ERROR, LOCATION, NULL, 
 			    "Missing fragment #%d\n", i);
 			vfree(buf);
@@ -308,6 +343,7 @@ isakmp_frag_reassembly(iph1)
 		}
 		memcpy(data, item->frag_packet->v, item->frag_packet->l);
 		data += item->frag_packet->l;
+		item = item->frag_next;
 	}
 
 out:
