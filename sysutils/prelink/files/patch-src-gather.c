diff -Nur src/gather.c src/gather.c
--- src/gather.c	2013-02-19 23:54:34.000000000 +0200
+++ src/gather.c	2013-02-19 23:50:31.000000000 +0200
@@ -235,7 +235,8 @@
 	    }
 	}
 
-      depends[ndepends] = strdupa (p);
+      depends[ndepends] = alloca (strlen(p) + 1);
+      strcpy(depends[ndepends], p);
       ++ndepends;
     } while (!feof (f));
 
@@ -495,7 +496,11 @@
 }
 
 static int
+#if __LINUX__
 gather_exec (DSO *dso, const struct stat64 *st)
+#else
+gather_exec (DSO *dso, const struct stat *st)
+#endif
 {
   int i, j;
   Elf_Data *data;
@@ -635,7 +640,11 @@
 }
 
 static int
+#if __LINUX__
 gather_func (const char *name, const struct stat64 *st, int type,
+#else
+gather_func (const char *name, const struct stat *st, int type,
+#endif
 	     struct FTW *ftwp)
 {
   unsigned char e_ident [sizeof (Elf64_Ehdr) + sizeof (Elf64_Phdr)];
@@ -901,7 +910,11 @@
 }
 
 static int
+#if __LINUX__
 gather_binlib (const char *name, const struct stat64 *st)
+#else
+gather_binlib (const char *name, const struct stat *st)
+#endif
 {
   unsigned char e_ident [EI_NIDENT + 2];
   int fd, type;
@@ -1014,9 +1027,17 @@
 int
 gather_object (const char *name, int deref, int onefs)
 {
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
 
+#if __LINUX__
   if (stat64 (name, &st) < 0)
+#else
+  if (stat (name, &st) < 0)
+#endif
     {
       if (implicit)
 	return 0;
@@ -1039,7 +1060,11 @@
       if (!all && implicit && ! deref)
 	return 0;
       ++implicit;
+#if __LINUX__
       ret = nftw64 (name, gather_func, 20, flags | FTW_ACTIONRETVAL);
+#else
+      ret = nftw (name, gather_func, 20, flags | FTW_ACTIONRETVAL);
+#endif
       --implicit;
       if (ret < 0)
 	error (0, errno, "Failed searching %s", name);
@@ -1300,9 +1325,17 @@
   const char *canon_name;
   struct prelink_dir *path;
   size_t len;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
 
+#if __LINUX__
   if (stat64 (name, &st) < 0)
+#else
+  if (stat (name, &st) < 0)
+#endif
     {
       if (implicit)
 	return 0;
@@ -1421,7 +1454,11 @@
 	{
 	  glob_t g;
 
+#ifdef GLOB_PERIOD
 	  if (!glob (p, GLOB_BRACE | GLOB_PERIOD, NULL, &g))
+#else
+	  if (!glob (p, GLOB_BRACE, NULL, &g))
+#endif
 	    {
 	      size_t n;
 
