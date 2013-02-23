diff -Nur src/prelink.h src/prelink.h
--- src/prelink.h	2013-02-19 23:54:34.000000000 +0200
+++ src/prelink.h	2013-02-20 00:02:54.000000000 +0200
@@ -19,7 +19,9 @@
 #ifndef PRELINK_H
 #define PRELINK_H
 
-#include <elf.h>
+#include "../gelf/elf.h"
+#define _SYS_ELF32_H_ 1
+#define _SYS_ELF64_H_ 1
 #include <libelf.h>
 #include <gelfx.h>
 #include <stdint.h>
@@ -253,7 +255,11 @@
 int adjust_mdebug (DSO *dso, int n, GElf_Addr start, GElf_Addr adjust);
 int finalize_mdebug (DSO *dso);
 int relocate_dso (DSO *dso, GElf_Addr base);
+#if __LINUX__
 int copy_fd_to_file (int fdin, const char *name, struct stat64 *st);
+#else
+int copy_fd_to_file (int fdin, const char *name, struct stat *st);
+#endif
 int update_dso (DSO *dso, const char *);
 int prepare_write_dso (DSO *dso);
 int write_dso (DSO *dso);
@@ -368,7 +374,11 @@
   GElf_Word checksum;
   GElf_Addr base, end, layend, pltgot;
   dev_t dev;
+#if __LINUX__
   ino64_t ino;
+#else
+  ino_t ino;
+#endif
 #define ET_BAD			(ET_NUM)
 #define ET_CACHE_EXEC		(ET_NUM + 1)
 #define ET_CACHE_DYN		(ET_NUM + 2)
@@ -478,7 +488,11 @@
 int prelink_print_cache (void);
 int prelink_save_cache (int do_warn);
 struct prelink_entry *
+#if __LINUX__
   prelink_find_entry (const char *filename, const struct stat64 *stp,
+#else
+  prelink_find_entry (const char *filename, const struct stat *stp,
+#endif
 		      int insert);
 struct prelink_conflict *
   prelink_conflict (struct prelink_info *info, GElf_Word r_sym,
@@ -517,7 +531,11 @@
 
 int undo_all (void);
 
+#if __LINUX__
 char *prelink_canonicalize (const char *name, struct stat64 *stp);
+#else
+char *prelink_canonicalize (const char *name, struct stat *stp);
+#endif
 
 extern const char *dynamic_linker;
 extern const char *ld_library_path;
