--- src/vmod_querystring.c.orig	2020-09-21 14:52:07 UTC
+++ src/vmod_querystring.c
@@ -208,6 +208,17 @@ qs_match_regex(VRT_CTX, const struct qs_
 	return (VRT_re_match(ctx, s, qsf->ptr));
 }
 
+static void
+qs_free_regex(void *priv)
+{
+	vre_t *re;
+
+	AN(priv);
+	re = priv;
+	VRE_free(&re);
+	AZ(re);
+}
+
 static int
 qs_match_glob(VRT_CTX, const struct qs_filter *qsf, const char *s,
     unsigned keep)
@@ -595,7 +606,7 @@ vmod_filter_add_regex(VRT_CTX, struct VP
 	}
 
 	qsf->match = qs_match_regex;
-	qsf->free = VRT_re_fini;
+	qsf->free = qs_free_regex;
 	VTAILQ_INSERT_TAIL(&obj->filters, qsf, list);
 }
 
