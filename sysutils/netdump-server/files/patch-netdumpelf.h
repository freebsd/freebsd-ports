--- netdumpelf.h.orig	Fri Sep  3 23:53:20 2004
+++ netdumpelf.h	Sun Mar 20 12:49:10 2005
@@ -1,7 +1,21 @@
 #include <sys/time.h>
-#include <linux/types.h>
+#include <sys/types.h>
 #include <elf.h>
 
+typedef __uint32_t __u32;
+typedef __uint64_t __u64;
+typedef __uint16_t __u16;
+typedef __uint8_t __u8;
+typedef uid_t __kernel_uid_t;
+typedef gid_t __kernel_gid_t;
+typedef Elf_Note Elf32_Nhdr;
+typedef Elf_Note Elf64_Nhdr;
+
+#if __FreeBSD_version < 500000
+#define ELFMAG "\177ELF"
+#define SELFMAG 4
+#endif
+
 #ifndef NT_TASKSTRUCT
 #define NT_TASKSTRUCT	4
 #endif
@@ -87,9 +101,9 @@
 #define CLIENT_BYTE_ORDER(client)  \
 	((client->machine_type == EM_386 || \
 	 client->machine_type == EM_X86_64 || \
-         client->machine_type == EM_IA_64) ? __LITTLE_ENDIAN : __BIG_ENDIAN)
+         client->machine_type == EM_IA_64) ? LITTLE_ENDIAN : BIG_ENDIAN)
 
-#define BYTE_SWAP_REQUIRED(client) (__BYTE_ORDER != CLIENT_BYTE_ORDER(client))
+#define BYTE_SWAP_REQUIRED(client) (BYTE_ORDER != CLIENT_BYTE_ORDER(client))
 
 typedef unsigned short u16;
 
