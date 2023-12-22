src/a12/net/dir_supp.c:390:43: error: incompatible function pointer types passing 'int (const FTSENT **, const FTSENT **)' (aka 'int (const struct _ftsent **, const struct _ftsent **)') to parameter of type 'int (*)(const FTSENT *const *, const FTSENT *const *)' (aka 'int (*)(const struct _ftsent *const *, const struct _ftsent *const *)') [-Wincompatible-function-pointer-types]
  390 |         if (!(fts = fts_open(path, FTS_PHYSICAL, comp_alpha)))
      |                                                  ^~~~~~~~~~
/usr/include/fts.h:129:12: note: passing argument to parameter here
  129 |             int (*)(const FTSENT * const *, const FTSENT * const *));
      |                   ^

--- a12/net/dir_supp.c.orig	2023-12-19 00:13:54 UTC
+++ a12/net/dir_supp.c
@@ -189,7 +189,7 @@ FILE* file_to_membuf(FILE* applin, char** out, size_t*
 	return applbuf;
 }
 
-static int comp_alpha(const FTSENT** a, const FTSENT** b)
+static int comp_alpha(const FTSENT* const* a, const FTSENT* const* b)
 {
 	return strcmp((*a)->fts_name, (*b)->fts_name);
 }
