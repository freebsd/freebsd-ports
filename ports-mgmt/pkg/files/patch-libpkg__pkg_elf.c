--- ./libpkg/pkg_elf.c.orig	2013-07-06 05:48:19.000000000 -0500
+++ ./libpkg/pkg_elf.c	2013-09-05 06:33:00.416129335 -0500
@@ -271,6 +271,10 @@
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
@@ -484,7 +488,7 @@
 	uint32_t version = 0;
 	int ret = EPKG_OK;
 	int i;
-	const char *abi, *endian_corres_str, *wordsize_corres_str;
+	const char *abi, *endian_corres_str, *wordsize_corres_str, *fpu;
 
 	if (elf_version(EV_CURRENT) == EV_NONE) {
 		pkg_emit_error("ELF library initialization failed: %s",
@@ -569,10 +573,28 @@
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
