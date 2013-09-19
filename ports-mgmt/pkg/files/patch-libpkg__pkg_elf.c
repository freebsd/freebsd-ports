--- ./libpkg/pkg_elf.c.orig	2013-07-06 12:48:19.000000000 +0200
+++ ./libpkg/pkg_elf.c	2013-09-19 21:49:03.825014672 +0200
@@ -87,6 +87,8 @@
 		  const char *name, bool is_shlib)
 {
 	const char *pkgname, *pkgversion;
+	struct pkg_file *file = NULL;
+	const char *filepath;
 
 	switch(filter_system_shlibs(name, NULL, 0)) {
 	case EPKG_OK:		/* A non-system library */
@@ -100,6 +102,15 @@
 		if (is_shlib)
 			return (EPKG_OK);
 
+		/* Search in libraries we do provide */
+		while (pkg_files(pkg, &file) == EPKG_OK) {
+			filepath = pkg_file_path(file);
+			if (strcmp(&filepath[strlen(filepath) - strlen(name)], name) == 0) {
+				pkg_addshlib_required(pkg, name);
+				return (EPKG_OK);
+			}
+		}
+
 		pkg_get(pkg, PKG_NAME, &pkgname, PKG_VERSION, &pkgversion);
 		warnx("(%s-%s) %s - shared library %s not found",
 		      pkgname, pkgversion, fpath, name);
@@ -271,6 +282,10 @@
 			ret = EPKG_END; /* Some error occurred, ignore this file */
 			goto cleanup;
 		}
+		if (data->d_buf == NULL) {
+			ret = EPKG_END; /* No osname available */
+			goto cleanup;
+		}
 		osname = (const char *) data->d_buf + sizeof(Elf_Note);
 		if (strncasecmp(osname, "freebsd", sizeof("freebsd")) != 0 &&
 		    strncasecmp(osname, "dragonfly", sizeof("dragonfly")) != 0) {
@@ -323,7 +338,7 @@
 		if (dyn->d_tag != DT_RPATH && dyn->d_tag != DT_RUNPATH)
 			continue;
 		
-		shlib_list_from_rpath(elf_strptr(e, sh_link, dyn->d_un.d_val), 
+		shlib_list_from_rpath(elf_strptr(e, sh_link, dyn->d_un.d_val),
 				      dirname(fpath));
 		break;
 	}
@@ -377,11 +392,11 @@
 }
 
 int
-pkg_analyse_files(struct pkgdb *db, struct pkg *pkg)
+pkg_analyse_files(struct pkgdb *db, struct pkg *pkg, const char *stage)
 {
 	struct pkg_file *file = NULL;
 	int ret = EPKG_OK;
-	const char *fpath;
+	char fpath[MAXPATHLEN];
 	bool autodeps = false;
 	bool developer = false;
 	int (*action)(void *, struct pkg *, const char *, const char *, bool);
@@ -410,7 +425,10 @@
 				PKG_CONTAINS_H_OR_LA);
 
 	while (pkg_files(pkg, &file) == EPKG_OK) {
-		fpath = pkg_file_path(file);
+		if (stage != NULL)
+			snprintf(fpath, MAXPATHLEN, "%s/%s", stage, pkg_file_path(file));
+		else
+			strlcpy(fpath, pkg_file_path(file), MAXPATHLEN);
 
 		ret = analyse_elf(pkg, fpath, action, db);
 		if (developer) {
@@ -484,7 +502,7 @@
 	uint32_t version = 0;
 	int ret = EPKG_OK;
 	int i;
-	const char *abi, *endian_corres_str, *wordsize_corres_str;
+	const char *abi, *endian_corres_str, *wordsize_corres_str, *fpu;
 
 	if (elf_version(EV_CURRENT) == EV_NONE) {
 		pkg_emit_error("ELF library initialization failed: %s",
@@ -569,10 +587,28 @@
 		endian_corres_str = elf_corres_to_string(endian_corres,
 		    (int)elfhdr.e_ident[EI_DATA]);
 
+		/* FreeBSD doesn't support the hard-float ABI yet */
+		fpu = "softfp";
+		if ((elfhdr.e_flags & 0xFF000000) != 0) {
+			/* This is an EABI file, the conformance level is set */
+			abi = "eabi";
+		} else if (elfhdr.e_ident[EI_OSABI] != ELFOSABI_NONE) {
+			/*
+			 * EABI executables all have this field set to
+			 * ELFOSABI_NONE, therefore it must be an oabi file.
+			 */
+			abi = "oabi";
+                } else {
+			/*
+			 * We may have failed to positively detect the ABI,
+			 * set the ABI to unknown. If we end up here one of
+			 * the above cases should be fixed for the binary.
+			 */
+			pkg_emit_error("unknown ARM ABI");
+			goto cleanup;
+		}
 		snprintf(dest + strlen(dest), sz - strlen(dest), ":%s:%s:%s",
-		    endian_corres_str,
-		    (elfhdr.e_flags & EF_ARM_NEW_ABI) > 0 ? "eabi" : "oabi",
-		    (elfhdr.e_flags & EF_ARM_VFP_FLOAT) > 0 ? "softfp" : "vfp");
+		    endian_corres_str, abi, fpu);
 		break;
 	case EM_MIPS:
 		/*
