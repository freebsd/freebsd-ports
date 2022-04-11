--- libpkg/pkg_elf.c.orig	2021-11-12 08:57:25 UTC
+++ libpkg/pkg_elf.c
@@ -715,6 +715,62 @@ aeabi_parse_arm_attributes(void *data, size_t length)
 #undef MOVE
 }
 
+/*
+ * elf_note_analyse_cheribsd() looks for a second ELF note indicating that
+ * a binary was built for CheriBSD and overwrites OS information relevant for
+ * CheriBSD.
+ */
+static void
+elf_note_analyse_cheribsd(Elf_Data *data, GElf_Ehdr *elfhdr, struct os_info *oi)
+{
+	Elf_Note note;
+	char *src;
+	uint32_t version = 0;
+
+	if (strcmp(oi->name, "FreeBSD") != 0) {
+		/*
+		 * Don't overwrite values if a binary was built for a vendor
+		 * other than FreeBSD.
+		 */
+		return;
+	}
+
+	src = data->d_buf;
+
+	while ((uintptr_t)src < ((uintptr_t)data->d_buf + data->d_size)) {
+		memcpy(&note, src, sizeof(note));
+		src += sizeof(note);
+		if (strncmp((const char *)src, "CheriBSD",
+		    note.n_namesz) == 0) {
+			if (note.n_type == NT_VERSION) {
+				break;
+			}
+		}
+		src += roundup2(note.n_namesz + note.n_descsz, 4);
+	}
+	if ((uintptr_t)src >= ((uintptr_t)data->d_buf + data->d_size)) {
+		return;
+	}
+
+	/* Overwrite a vendor with CheriBSD. */
+	free(oi->name);
+	oi->name = xstrdup(src);
+
+	src += roundup2(note.n_namesz, 4);
+	if (elfhdr->e_ident[EI_DATA] == ELFDATA2MSB)
+		version = be32dec(src);
+	else
+		version = le32dec(src);
+
+	/*
+	 * Overwrite a version with a CheriBSD ABI version.
+	 *
+	 * Note that minor and major versions are left from FreeBSD.
+	 */
+	free(oi->version);
+	xasprintf(&oi->version, "%d", version);
+}
+
 static bool
 elf_note_analyse(Elf_Data *data, GElf_Ehdr *elfhdr, struct os_info *oi)
 {
@@ -809,6 +865,7 @@ elf_note_analyse(Elf_Data *data, GElf_Ehdr *elfhdr, st
 		xasprintf(&oi->version, "%d", version / 100000);
 	}
 
+	elf_note_analyse_cheribsd(data, elfhdr, oi);
 	return (true);
 }
 
@@ -825,16 +882,18 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
 	int fd, i;
 	int ret = EPKG_OK;
 	const char *arch, *abi, *endian_corres_str, *wordsize_corres_str, *fpu;
-	bool checkroot;
+	bool checkroot, cheriabi;
 	struct os_info loi;
 
 	const char *abi_files[] = {
 		getenv("ABI_FILE"),
+		"/usr/sbin/pkg" PKG_SUFFIX,
 		_PATH_UNAME,
 		_PATH_BSHELL,
 	};
 
 	arch = NULL;
+	cheriabi = false;
 
 	if (oi == NULL) {
 		memset(&loi, 0, sizeof(loi));
@@ -1002,6 +1061,15 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
 		    ":%s:%s:%s:%s:%s", arch, wordsize_corres_str,
 		    endian_corres_str, abi, fpu);
 		break;
+	case EM_AARCH64:
+#if defined(EF_AARCH64_CHERI_PURECAP)
+		if (elfhdr.e_flags & EF_AARCH64_CHERI_PURECAP) {
+			cheriabi = true;
+		}
+#endif
+		snprintf(dest + strlen(dest), sz - strlen(dest), ":%s:%s%s",
+		    arch, wordsize_corres_str, cheriabi ? ":cheri" : "");
+		break;
 	case EM_MIPS:
 		/*
 		 * this is taken from binutils sources:
@@ -1044,8 +1112,14 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
 				abi = "unknown";
 				break;
 		}
-		snprintf(dest + strlen(dest), sz - strlen(dest), ":%s:%s:%s",
-		    arch, wordsize_corres_str, abi);
+#if defined(EF_RISCV_CHERIABI)
+		if (elfhdr.e_flags & EF_RISCV_CHERIABI) {
+			cheriabi = true;
+		}
+#endif
+		snprintf(dest + strlen(dest), sz - strlen(dest),
+		    ":%s:%s%s:%s",
+		    arch, wordsize_corres_str, cheriabi ? ":cheri" : "", abi);
 		break;
 #endif
 	case EM_PPC:
