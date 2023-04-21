--- bgpd/bgp_lcommunity.c.orig	2023-03-13 14:01:47 UTC
+++ bgpd/bgp_lcommunity.c
@@ -211,12 +211,13 @@ static void set_lcommunity_string(struct lcommunity *l
 	}
 
 	/* 1 space + lcom->size lcom strings + null terminator */
-	size_t str_buf_sz = BUFSIZ;
+	size_t str_buf_sz = (LCOMMUNITY_STRLEN * lcom->size) + 2;
 	str_buf = XCALLOC(MTYPE_LCOMMUNITY_STR, str_buf_sz);
 
+	len = 0;
 	for (i = 0; i < lcom->size; i++) {
 		if (i > 0)
-			strlcat(str_buf, " ", str_buf_sz);
+			len = strlcat(str_buf, " ", str_buf_sz);
 
 		pnt = lcom->val + (i * LCOMMUNITY_SIZE);
 		pnt = ptr_get_be32(pnt, &global);
@@ -229,11 +230,22 @@ static void set_lcommunity_string(struct lcommunity *l
 		snprintf(lcsb, sizeof(lcsb), "%u:%u:%u", global, local1,
 			 local2);
 
+		/*
+		 * Aliases can cause havoc, if the alias length is greater
+		 * than the LCOMMUNITY_STRLEN for a particular item
+		 * then we need to realloc the memory associated
+		 * with the string so that it can fit
+		 */
 		const char *com2alias =
 			translate_alias ? bgp_community2alias(lcsb) : lcsb;
+		size_t individual_len = strlen(com2alias);
+		if (individual_len + len > str_buf_sz) {
+			str_buf_sz = individual_len + len + 1;
+			str_buf = XREALLOC(MTYPE_LCOMMUNITY_STR, str_buf,
+					   str_buf_sz);
+		}
 
 		len = strlcat(str_buf, com2alias, str_buf_sz);
-		assert((unsigned int)len < str_buf_sz);
 
 		if (make_json) {
 			json_string = json_object_new_string(com2alias);
