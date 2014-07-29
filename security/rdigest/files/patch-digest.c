$NetBSD: patch-ac,v 1.2 2005/01/21 02:18:23 tv Exp $

--- digest.c.orig	2005-01-20 21:10:03.000000000 -0500
+++ digest.c
@@ -43,9 +43,14 @@ __RCSID("$NetBSD: digest.c,v 1.8 2003/07
 #endif
 
 
+#include <sys/queue.h>
+#include <sys/stat.h>
+
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
+#include <fcntl.h>
+#include <fts.h>
 #ifdef HAVE_LOCALE_H
 #include <locale.h>
 #endif
@@ -147,21 +152,178 @@ digest_file(char *fn, alg_t *alg)
 	return (rc);
 }
 
+struct excl {
+	LIST_ENTRY(excl) n;
+	const char *p;
+};
+
+LIST_HEAD(, excl) excl;
+
+static void
+exclude(const char *p)
+{
+	struct excl *e;
+
+	e = malloc(sizeof(struct excl));
+	e->p = p;
+	LIST_INSERT_HEAD(&excl, e, n);
+}
+
+static int
+skip(const char *p)
+{
+	struct excl *e;
+
+#ifdef LIST_FOREACH
+	LIST_FOREACH(e, &excl, n)
+#else
+	for (e = excl.lh_first; e; e = e->n.le_next)
+#endif
+		if (strcmp(e->p, p) == 0)
+			return (1);
+
+	return (0);
+}
+
+static int
+compar(const FTSENT **fa, const FTSENT **fb)
+{
+	return (strcmp((*fa)->fts_name, (*fb)->fts_name));
+}
+
+static int
+digest_directory(char *dn, alg_t *alg)
+{
+	char	in[BUFSIZ * 20], dot[2];
+	char	*digest;
+	int	cc, rc, l, fd, cwd;
+	char	*pathlist[2];
+	FTS	*ftsp;
+	FTSENT	*f;
+
+	rc = 1;
+	l = alg->hash_len * 2;
+	digest = malloc(l + 1);
+	sprintf(dot, ".");
+	pathlist[0] = dot;
+	pathlist[1] = NULL;
+
+	if ((cwd = open(".", O_RDONLY)) == -1 ||
+	    chdir(dn) == -1 ||
+	    (ftsp = fts_open(pathlist,
+			     FTS_COMFOLLOW | FTS_NOCHDIR | FTS_PHYSICAL,
+			     compar)) == NULL) {
+		(void) fprintf(stderr, "%s\n", dn);
+		free(digest);
+		return (0);
+	}
+
+	(*alg->hash_init)(&alg->hash_ctx);
+
+	while ((f = fts_read(ftsp)) != NULL) {
+		/* skip the second pass on a directory */
+		if (f->fts_info == FTS_DP)
+			continue;
+
+		/* skip directories named CVS, RCS, or SCCS */
+		if ((f->fts_info == FTS_NS ||
+		     S_ISDIR(f->fts_statp->st_mode)) &&
+		    skip(f->fts_name)) {
+			fts_set(ftsp, f, FTS_SKIP);
+			continue;
+		}
+
+		/* try to handle things based on stat info */
+		if (f->fts_info != FTS_NS) {
+				/* only mention directories */
+			if (S_ISDIR(f->fts_statp->st_mode)) {
+				(*alg->hash_init)(&alg->hash_ctx2);
+				(*alg->hash_update)(&alg->hash_ctx2, "d ", 2);
+				(*alg->hash_update)(&alg->hash_ctx2, f->fts_path, f->fts_pathlen);
+				(*alg->hash_end)(&alg->hash_ctx2, digest);
+				digest[l] = '\n';
+				(*alg->hash_update)(&alg->hash_ctx, digest, l + 1);
+
+				/* hash the filename and then the contents separately */
+			} else if (S_ISREG(f->fts_statp->st_mode)) {
+				if ((fd = open(f->fts_path, O_RDONLY)) != -1) {
+					(*alg->hash_init)(&alg->hash_ctx2);
+					(*alg->hash_update)(&alg->hash_ctx2, "f ", 2);
+					(*alg->hash_update)(&alg->hash_ctx2, f->fts_path, f->fts_pathlen);
+					(*alg->hash_end)(&alg->hash_ctx2, &digest[0]);
+					digest[l] = '\n';
+					(*alg->hash_update)(&alg->hash_ctx, digest, 33);
+
+					(*alg->hash_init)(&alg->hash_ctx2);
+					while ((cc = read(fd, in, sizeof(in))) > 0) {
+						(*alg->hash_update)(&alg->hash_ctx2, in, cc);
+					}
+					close(fd);
+					(*alg->hash_end)(&alg->hash_ctx2, digest);
+					digest[l] = '\n';
+					(*alg->hash_update)(&alg->hash_ctx, digest, l + 1);
+				} else {
+					(void) fprintf(stderr, "%s\n", f->fts_path);
+					rc = 0;
+				}
+
+			/* hash in symlinks as well, along with the link contents */
+			} else if (S_ISLNK(f->fts_statp->st_mode)) {
+				if ((cc = readlink(f->fts_path, in, sizeof(in))) > 0) {
+					(*alg->hash_init)(&alg->hash_ctx2);
+					(*alg->hash_update)(&alg->hash_ctx2, "l ", 2);
+					(*alg->hash_update)(&alg->hash_ctx2, f->fts_path, f->fts_pathlen);
+					(*alg->hash_end)(&alg->hash_ctx2, digest);
+					digest[l] = '\n';
+					(*alg->hash_update)(&alg->hash_ctx, digest, l + 1);
+
+					(*alg->hash_init)(&alg->hash_ctx2);
+					(*alg->hash_update)(&alg->hash_ctx2, in, cc);
+					(*alg->hash_end)(&alg->hash_ctx2, digest);
+					digest[l] = '\n';
+					(*alg->hash_update)(&alg->hash_ctx, digest, l + 1);
+				} else {
+					(void) fprintf(stderr, "%s\n", f->fts_path);
+					rc = 0;
+				}
+			}
+		}
+	}
+
+	fts_close(ftsp);
+	fchdir(cwd);
+	close(cwd);
+
+	if (rc == 1) {
+		(*alg->hash_end)(&alg->hash_ctx, digest);
+		(void) printf("%s (%s) = %s\n", alg->name, dn, digest);
+	}
+
+	free(digest);
+	return (rc);
+}
+
 int
 main(int argc, char **argv)
 {
 	alg_t  *alg;
 	int	rval;
 	int	i;
+	struct stat st;
+
+	LIST_INIT(&excl);
 
 #ifdef HAVE_SETLOCALE
 	(void) setlocale(LC_ALL, "");
 #endif
-	while ((i = getopt(argc, argv, "V")) != -1) {
+	while ((i = getopt(argc, argv, "Vx:")) != -1) {
 		switch(i) {
 		case 'V':
 			printf("%s\n", VERSION);
 			return EXIT_SUCCESS;
+		case 'x':
+			exclude(optarg);
+			break;
 		}
 	}
 	argc -= optind;
@@ -186,7 +348,9 @@ main(int argc, char **argv)
 		}
 	} else {
 		for (i = 0 ; i < argc ; i++) {
-			if (!digest_file(argv[i], alg)) {
+			if (stat(argv[i], &st) == -1 ||
+			    (S_ISREG(st.st_mode) && !digest_file(argv[i], alg)) ||
+			    (S_ISDIR(st.st_mode) && !digest_directory(argv[i], alg))) {
 				(void) fprintf(stderr, "%s\n", argv[i]);
 				rval = EXIT_FAILURE;
 			}
