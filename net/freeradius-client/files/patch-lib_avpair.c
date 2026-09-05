Make rc_avpair_gen() iterative.  Response attributes were parsed
recursively without a depth limit, before the response authenticator
was verified, so a spoofed reply with many attributes could exhaust
the stack of a threaded caller.

Upstream issue: https://github.com/FreeRADIUS/freeradius-client/issues/134
Obtained from:  https://github.com/FreeRADIUS/freeradius-client/commit/a82f7bf548750e4937fbb833372cf65577ea0c6b

--- lib/avpair.c.orig	2021-07-29 14:49:30 UTC
+++ lib/avpair.c
@@ -175,45 +175,41 @@ VALUE_PAIR *rc_avpair_new (rc_handle const *rh, uint32
  * @note Uses recursion.
  *
  * @param rh a handle to parsed configuration.
- * @param pair a pointer to a #VALUE_PAIR structure.
+ * @param next a pointer to the next #VALUE_PAIR structure.
  * @param ptr the value (e.g., the actual username).
  * @param length the length of ptr, or -1 if to calculate (in case of strings).
  * @param vendorpec The vendor ID in case of a vendor specific value - 0 otherwise.
  * @return value_pair list or %NULL on failure.
  */
-VALUE_PAIR *rc_avpair_gen(rc_handle const *rh, VALUE_PAIR *pair, unsigned char const *ptr,
+VALUE_PAIR *rc_avpair_gen(rc_handle const *rh, VALUE_PAIR *next, unsigned char const *ptr,
 			  int length, uint32_t vendorpec)
 {
 	int attrlen, x_len;
 	unsigned char const *x_ptr;
 	uint32_t attribute, lvalue;
 	DICT_ATTR *attr;
-	VALUE_PAIR *rpair;
+	VALUE_PAIR *head, **last, *pair;
 	char buffer[(AUTH_STRING_LEN * 2) + 1];
 	/* For hex string conversion. */
 	char hex[3];
 
+	head = NULL;
+	last = &head;
+
+next_attribute:
 	if (length < 2) {
 		rc_log(LOG_ERR, "rc_avpair_gen: received attribute with "
 		    "invalid length");
-		goto shithappens;
+		goto error;
 	}
 	attrlen = ptr[1];
 	if (length < attrlen || attrlen < 2) {
 		rc_log(LOG_ERR, "rc_avpair_gen: received attribute with "
 		    "invalid length");
-		goto shithappens;
+		goto error;
 	}
 
-	/* Advance to the next attribute and process recursively */
-	if (length != attrlen) {
-		pair = rc_avpair_gen(rh, pair, ptr + attrlen, length - attrlen,
-		    vendorpec);
-		if ((pair == NULL) && (vendorpec != 0))
-			return NULL;
-	}
-
-	/* Actual processing */
+	/* decode the attribute */
 	attribute = ptr[0];
 	ptr += 2;
 	attrlen -= 2;
@@ -233,9 +229,15 @@ VALUE_PAIR *rc_avpair_gen(rc_handle const *rh, VALUE_P
 			    "attribute with unknown Vendor-Id %d", vendorpec);
 			goto skipit;
 		}
-		/* Process recursively */
-		return rc_avpair_gen(rh, pair, ptr + 4, attrlen - 4,
-		    vendorpec);
+
+		/* Process recursively, because VSAs */
+		pair = rc_avpair_gen(rh, NULL, ptr + 4, attrlen - 4,
+				      vendorpec);
+		if (!pair) goto skipit;
+
+		*last = pair;
+		while (*last) last = &((*last)->next);
+		goto skipit;
 	}
 
 	/* Normal */
@@ -260,16 +262,16 @@ VALUE_PAIR *rc_avpair_gen(rc_handle const *rh, VALUE_P
 		goto skipit;
 	}
 
-	rpair = malloc(sizeof(*rpair));
-	if (rpair == NULL) {
+	pair = malloc(sizeof(*pair));
+	if (pair == NULL) {
 		rc_log(LOG_CRIT, "rc_avpair_gen: out of memory");
-		goto shithappens;
+		goto error;
 	}
-	memset(rpair, '\0', sizeof(*rpair));
+	memset(pair, '\0', sizeof(*pair));
 
-	/* Insert this new pair at the beginning of the list */
-	rpair->next = pair;
-	pair = rpair;
+	/* Insert this new pair at the end of the list */
+	*last = pair;
+	last = &(pair->next);
 	strcpy(pair->name, attr->name);
 	pair->vendor = attr->vendor;
 	pair->attribute = attr->value;
@@ -329,13 +331,21 @@ skipit:
 	}
 
 skipit:
-	return pair;
+	/*
+	 *	Skip the attribute
+	 */
+	ptr += attrlen;
+	length -= (attrlen + 2);
 
-shithappens:
-	while (pair != NULL) {
-		rpair = pair->next;
-		free(pair);
-		pair = rpair;
+	if (!length) return head;
+
+	goto next_attribute;
+
+error:
+	while (head != NULL) {
+		pair = head->next;
+		free(head);
+		head = pair;
 	}
 	return NULL;
 }
