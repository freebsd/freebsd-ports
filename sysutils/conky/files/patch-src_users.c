--- src/users.c.orig	2008-03-31 00:56:42.000000000 -0400
+++ src/users.c	2008-06-03 17:04:27.000000000 -0400
@@ -34,6 +34,123 @@
 #include <stdlib.h>
 #include <time.h>
 
+#ifdef __FreeBSD__
+/* The code for this is adapted directly from src/usr.bin/users/users.c */
+#include <sys/types.h>
+#include <unistd.h>
+
+FILE *_utmp_file = NULL;
+char (*_ut_names)[UT_NAMESIZE];
+char (*_ut_lines)[UT_LINESIZE];
+int _ut_ncnt = 0;
+int _ut_lcnt = 0;
+
+int nscmp(const void *, const void *);
+int lscmp(const void *, const void *);
+void slurputmp(void);
+
+int nscmp(const void *p, const void *q)
+{
+	return(strncmp(p, q, UT_NAMESIZE));
+}
+
+int lscmp(const void *p, const void *q)
+{
+	return(strncmp(p, q, UT_LINESIZE));
+}
+
+void slurputmp(void)
+{
+	struct utmp _ut;
+	int nmax = 0;
+	int lmax = 0;
+
+	_ut_ncnt = 0;
+	_ut_lcnt = 0;
+
+	if (_utmp_file == NULL)
+		if (!(_utmp_file = fopen(_PATH_UTMP, "r")))
+			ERR("error opening utmp");
+	
+	while (fread((char*)&_ut, sizeof(_ut), 1, _utmp_file) == 1) {
+		if (*_ut.ut_name) {
+			if (_ut_ncnt >= nmax) {
+				nmax += 32;
+				_ut_names = realloc(_ut_names, sizeof(*_ut_names) * nmax);
+				if (!_ut_names)
+					ERR("error realloc'ing");
+			}
+			(void)strncpy(_ut_names[_ut_ncnt], _ut.ut_name, UT_NAMESIZE);
+			++_ut_ncnt;
+
+		}
+		if (*_ut.ut_line) {
+			if (_ut_lcnt >= lmax) {
+				lmax += 32;
+				_ut_lines = realloc(_ut_lines, sizeof(*_ut_lines) * lmax);
+				if (!_ut_lines)
+					ERR("error realloc'ing");
+			}
+			(void)strncpy(_ut_lines[_ut_lcnt], _ut.ut_line, UT_LINESIZE);
+			++_ut_lcnt;
+		}
+	}
+
+	fclose(_utmp_file);
+	_utmp_file = NULL;
+}
+	
+static void user_name(char *ptr)
+{
+	int cnt;
+	char buf[UT_NAMESIZE + 1];
+
+	if (_ut_ncnt) {
+		qsort(_ut_names, _ut_ncnt, UT_NAMESIZE, nscmp);
+		for (cnt = 0; cnt < _ut_ncnt; ++cnt)
+			if (cnt == 0 || strncmp(_ut_names[cnt], _ut_names[cnt - 1], UT_NAMESIZE)) {
+				(void)snprintf(buf, sizeof(buf), "%s ", _ut_names[cnt]);
+				(void)strncat(ptr, buf, sizeof(buf));
+			}
+	}
+}
+
+static void user_num(int *ptr)
+{
+	int cnt;
+	*ptr = 0;
+
+	if (_ut_ncnt) {
+		qsort(_ut_names, _ut_ncnt, UT_NAMESIZE, nscmp);
+		for (cnt = 0; cnt < _ut_ncnt; ++cnt)
+			if (cnt == 0 || strncmp(_ut_names[cnt], _ut_names[cnt - 1], UT_NAMESIZE))
+				++*ptr;
+	}
+}
+
+static void user_term(char *ptr)
+{
+	int cnt;
+	char buf[UT_LINESIZE + 1];
+
+	if (_ut_lcnt) {
+		qsort(_ut_lines, _ut_lcnt, UT_LINESIZE, lscmp);
+		for (cnt = 0; cnt < _ut_lcnt; ++cnt)
+			if (cnt == 0 || strncmp(_ut_lines[cnt], _ut_lines[cnt - 1], UT_LINESIZE)) {
+				(void)snprintf(buf, sizeof(buf), "%s ", _ut_lines[cnt]);
+				(void)strncat(ptr, buf, sizeof(buf));
+			}
+	}
+}
+
+static void user_time(char *ptr)
+{
+	/* idk my bff jill? */
+	strncpy(ptr, "Not implemented", 16);
+}
+
+#else /* __FreeBSD__ */
+
 static void user_name(char *ptr)
 {
 	const struct utmp *usr = 0;
@@ -101,6 +218,7 @@
 		}
 	}
 }
+#endif /* !__FreeBSD__ */
 
 static void users_alloc(struct information *ptr)
 {
@@ -122,6 +240,9 @@
 	char temp[512] = "";
 	int t;
 	users_alloc(current_info);
+#ifdef __FreeBSD__
+	slurputmp();
+#endif
 	user_name(temp);
 	if (temp != NULL) {
 		if (current_info->users.names) {
