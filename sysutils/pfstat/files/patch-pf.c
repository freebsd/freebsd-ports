--- pf.c.orig	2007-01-11 16:01:58 UTC
+++ pf.c
@@ -46,6 +46,7 @@ static const char rcsid[] = "$Id: pf.c,v 1.1.1.1 2007/
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <libpfctl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -167,20 +168,29 @@ query_counters(int fd, void (*cb)(int, const char *, i
 static int
 query_counters(int fd, void (*cb)(int, const char *, int, double))
 {
-	struct pf_status s;
-	int i;
+	struct pfctl_status *s;
+	struct pfctl_status_counter *np;
 
-	memset(&s, 0, sizeof(s));
-	if (ioctl(fd, DIOCGETSTATUS, &s)) {
-		fprintf(stderr, "ioctl: DIOCGETSTATUS: %s\n", strerror(errno));
+	s = pfctl_get_status(fd);
+	if (s  == NULL) {
+		fputs("pfctl_get_status failure.\n",stderr);
 		return (1);
 	}
-	(*cb)(COL_TYPE_SINCE, "", 0, s.since);
-	(*cb)(COL_TYPE_GLOBAL, "", 0, s.states);
-	for (i = 0; i < FCNT_MAX; ++i)
-		(*cb)(COL_TYPE_GLOBAL, "", 1 + i, s.fcounters[i]);
-	for (i = 0; i < PFRES_MAX; ++i)
-		(*cb)(COL_TYPE_GLOBAL, "", 1 + FCNT_MAX + i, s.counters[i]);
+
+	(*cb)(COL_TYPE_SINCE, "", 0, s->since);
+	(*cb)(COL_TYPE_GLOBAL, "", 0, s->states);
+
+	TAILQ_FOREACH(np, &s->fcounters, entry) {
+		if (np->id < FCNT_MAX)
+			(*cb)(COL_TYPE_GLOBAL, "", 1 + np->id, np->counter);
+	}
+
+	TAILQ_FOREACH(np, &s->counters, entry) {
+		if (np->id < PFRES_MAX)
+			(*cb)(COL_TYPE_GLOBAL, "", 1 + FCNT_MAX + np->id, np->counter);
+	}
+
+	pfctl_free_status(s);
 	return (0);
 }
