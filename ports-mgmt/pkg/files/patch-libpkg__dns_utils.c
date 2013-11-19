--- ./libpkg/dns_utils.c.orig	2013-07-06 05:48:19.000000000 -0500
+++ ./libpkg/dns_utils.c	2013-11-19 11:13:45.349130754 -0600
@@ -40,6 +40,65 @@
 	unsigned char buf[1024];
 } query_t;
 
+static int
+srv_priority_cmp(const void *a, const void *b)
+{
+	const struct dns_srvinfo *da, *db;
+	
+	da = *(struct dns_srvinfo * const *)a;
+	db = *(struct dns_srvinfo * const *)b;
+
+	return ((da->priority > db->priority) - (da->priority < db->priority));
+}
+
+static int
+srv_final_cmp(const void *a, const void *b)
+{
+	const struct dns_srvinfo *da, *db;
+	int res;
+	
+	da = *(struct dns_srvinfo * const *)a;
+	db = *(struct dns_srvinfo * const *)b;
+
+	res = ((da->priority > db->priority) - (da->priority < db->priority));
+	if (res == 0)
+		res = ((db->finalweight > da->finalweight) - (db->finalweight < da->finalweight));
+
+	return (res);
+}
+
+static void
+compute_weight(struct dns_srvinfo **d, int first, int last)
+{
+	int i, j;
+	int totalweight = 0;
+	int *chosen;
+
+	for (i = 0; i <= last; i++)
+		totalweight += d[i]->weight;
+
+	if (totalweight == 0)
+		return;
+
+	chosen = malloc(sizeof(int) * (last - first + 1));
+
+	for (i = 0; i <= last; i++) {
+		for (;;) {
+			chosen[i] = random() % (d[i]->weight * 100 / totalweight);
+			for (j = 0; j < i; j++) {
+				if (chosen[i] == chosen[j])
+					break;
+			}
+			if (j == i) {
+				d[i]->finalweight = chosen[i];
+				break;
+			}
+		}
+	}
+
+	free(chosen);
+}
+
 struct dns_srvinfo *
 dns_getsrvinfo(const char *zone)
 {
@@ -49,6 +108,7 @@
 	struct dns_srvinfo **res, *first;
 	unsigned char *end, *p;
 	unsigned int type, class, ttl, priority, weight, port;
+	int f, l;
 
 	if ((len = res_query(zone, C_IN, T_SRV, q.buf, sizeof(q.buf))) == -1 ||
 	    len < (int)sizeof(HEADER))
@@ -120,12 +180,31 @@
 		res[n]->weight = weight;
 		res[n]->port = port;
 		res[n]->next = NULL;
+		res[n]->finalweight = 0;
 		strlcpy(res[n]->host, host, MAXHOSTNAMELEN);
 
 		p += len;
 		n++;
 	}
 
+	/* order by priority */
+	qsort(res, n, sizeof(res[0]), srv_priority_cmp);
+
+	priority = 0;
+	f = 0;
+	l = 0;
+	for (i = 0; i < n; i++) {
+		if (res[i]->priority != priority) {
+			if (f != l)
+				compute_weight(res, f, l);
+			f = i;
+			priority = res[i]->priority;
+		}
+		l = i;
+	}
+
+	qsort(res, n, sizeof(res[0]), srv_final_cmp);
+
 	for (i = 0; i < n - 1; i++)
 		res[i]->next = res[i + 1];
 
