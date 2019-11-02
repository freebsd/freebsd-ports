--- src/cdf.c.orig	2019-10-22 21:52:28 UTC
+++ src/cdf.c
@@ -35,7 +35,7 @@
 #include "file.h"
 
 #ifndef lint
-FILE_RCSID("@(#)$File: cdf.c,v 1.114 2019/02/20 02:35:27 christos Exp $")
+FILE_RCSID("@(#)$File: cdf.c,v 1.116 2019/08/26 14:31:39 christos Exp $")
 #endif
 
 #include <assert.h>
@@ -53,6 +53,10 @@ FILE_RCSID("@(#)$File: cdf.c,v 1.114 2019/02/20 02:35:
 #define EFTYPE EINVAL
 #endif
 
+#ifndef SIZE_T_MAX
+#define SIZE_T_MAX CAST(size_t, ~0ULL)
+#endif
+
 #include "cdf.h"
 
 #ifdef CDF_DEBUG
@@ -405,7 +409,12 @@ cdf_read_sector(const cdf_info_t *info, void *buf, siz
     const cdf_header_t *h, cdf_secid_t id)
 {
 	size_t ss = CDF_SEC_SIZE(h);
-	size_t pos = CDF_SEC_POS(h, id);
+	size_t pos;
+
+	if (SIZE_T_MAX / ss < CAST(size_t, id))
+		return -1;
+
+	pos = CDF_SEC_POS(h, id);
 	assert(ss == len);
 	return cdf_read(info, CAST(off_t, pos), RCAST(char *, buf) + offs, len);
 }
@@ -415,7 +424,12 @@ cdf_read_short_sector(const cdf_stream_t *sst, void *b
     size_t len, const cdf_header_t *h, cdf_secid_t id)
 {
 	size_t ss = CDF_SHORT_SEC_SIZE(h);
-	size_t pos = CDF_SHORT_SEC_POS(h, id);
+	size_t pos;
+
+	if (SIZE_T_MAX / ss < CAST(size_t, id))
+		return -1;
+
+	pos = CDF_SHORT_SEC_POS(h, id);
 	assert(ss == len);
 	if (pos + len > CDF_SEC_SIZE(h) * sst->sst_len) {
 		DPRINTF(("Out of bounds read %" SIZE_T_FORMAT "u > %"
@@ -1013,8 +1027,9 @@ cdf_read_property_info(const cdf_stream_t *sst, const 
 				goto out;
 			}
 			nelements = CDF_GETUINT32(q, 1);
-			if (nelements == 0) {
-				DPRINTF(("CDF_VECTOR with nelements == 0\n"));
+			if (nelements > CDF_ELEMENT_LIMIT || nelements == 0) {
+				DPRINTF(("CDF_VECTOR with nelements == %"
+				    SIZE_T_FORMAT "u\n", nelements));
 				goto out;
 			}
 			slen = 2;
@@ -1056,8 +1071,6 @@ cdf_read_property_info(const cdf_stream_t *sst, const 
 					goto out;
 				inp += nelem;
 			}
-			DPRINTF(("nelements = %" SIZE_T_FORMAT "u\n",
-			    nelements));
 			for (j = 0; j < nelements && i < sh.sh_properties;
 			    j++, i++)
 			{
