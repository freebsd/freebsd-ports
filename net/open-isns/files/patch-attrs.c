--- attrs.c.orig	2021-02-06 13:40:34 UTC
+++ attrs.c
@@ -777,7 +777,7 @@ isns_attr_decode(buf_t *bp, isns_attr_t **result)
 {
 	isns_attr_t	*attr = NULL;
 	isns_value_t	*value;
-	uint32_t	tag, len;
+	uint32_t	tag, len=0;
 
 	if (!buf_get32(bp, &tag)
 	 || !buf_get32(bp, &len))
