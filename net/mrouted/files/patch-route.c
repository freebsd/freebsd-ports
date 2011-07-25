--- route.c.orig	2011-07-25 21:42:18.000000000 +0200
+++ route.c	2011-07-25 21:42:46.000000000 +0200
@@ -1399,8 +1399,10 @@ void dump_routes(FILE *fp)
 		inet_fmts(r->rt_origin, r->rt_originmask, s1, sizeof(s1)),
 		(r->rt_gateway == 0) ? "" : inet_fmt(r->rt_gateway, s2, sizeof(s2)));
 
-	fprintf(fp, (r->rt_metric == UNREACHABLE) ? "  NR " : "%4u ",
-		r->rt_metric);
+	if (r->rt_metric == UNREACHABLE)
+		fprintf(fp, "  NR ");
+	else
+		fprintf(fp, "%4u ", r->rt_metric);
 
 	fprintf(fp, "  %3u %c%c %3u   ", r->rt_timer,
 		(r->rt_flags & RTF_CHANGED) ? 'C' : '.',
