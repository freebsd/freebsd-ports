e2fsprogs is developed on GNU/Linux and with glibc in particular,
which uses a qsort_r() function interface differing from FreeBSD's,
both WRT argument ordering on qsort_r() itself, as well as 
the thunk argument on hash_cmp() is first on FreeBSD, last on glibc.
This applies to FreeBSD 11 and 12 and might change on FreeBSD 13.

Watch https://reviews.freebsd.org/D17083

--- e2fsck/rehash.c.orig	2021-01-29 22:02:31 UTC
+++ e2fsck/rehash.c
@@ -305,7 +305,7 @@ static EXT2_QSORT_TYPE name_cf_cmp(const struct name_c
 }
 
 /* Used for sorting the hash entry */
-static EXT2_QSORT_TYPE hash_cmp(const void *a, const void *b, void *arg)
+static EXT2_QSORT_TYPE hash_cmp(void *arg, const void *a, const void *b)
 {
 	const struct name_cmp_ctx *ctx = (struct name_cmp_ctx *) arg;
 	const struct hash_entry *he_a = (const struct hash_entry *) a;
@@ -1049,10 +1049,10 @@ retry_nohash:
 resort:
 	if (fd.compress && fd.num_array > 1)
 		qsort_r(fd.harray+2, fd.num_array-2, sizeof(struct hash_entry),
-			hash_cmp, &name_cmp_ctx);
+			&name_cmp_ctx, hash_cmp);
 	else
 		qsort_r(fd.harray, fd.num_array, sizeof(struct hash_entry),
-			hash_cmp, &name_cmp_ctx);
+			&name_cmp_ctx, hash_cmp);
 
 	/*
 	 * Look for duplicates
