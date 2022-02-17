--- libpkg/pkg_elf.c.orig	2021-11-12 08:57:25 UTC
+++ libpkg/pkg_elf.c
@@ -825,7 +825,7 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
 	int fd, i;
 	int ret = EPKG_OK;
 	const char *arch, *abi, *endian_corres_str, *wordsize_corres_str, *fpu;
-	bool checkroot;
+	bool checkroot, cheriabi;
 	struct os_info loi;
 
 	const char *abi_files[] = {
@@ -835,6 +835,7 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
 	};
 
 	arch = NULL;
+	cheriabi = false;
 
 	if (oi == NULL) {
 		memset(&loi, 0, sizeof(loi));
@@ -1002,6 +1003,15 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
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
@@ -1044,8 +1054,14 @@ pkg_get_myarch_elfparse(char *dest, size_t sz, struct 
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
