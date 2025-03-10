From c03a02388257e21810c534d50a93658e61a83494 Mon Sep 17 00:00:00 2001
From: Brooks Davis <brooks@one-eyed-alien.net>
Date: Wed, 28 Feb 2024 18:12:40 +0000
Subject: [PATCH] MINOR: tools: use public interface for FreeBSD
 get_exec_path()

Where possible (FreeBSD 13+), use the public, documented interface to
the ELF auxiliary argument vector: elf_aux_info().

__elf_aux_vector is a private interface exported so that the runtime
linker can set its value during process startup and not intended for
public consumption.  In FreeBSD 15 it has been removed from libc and
moved to libsys.
---
 src/tools.c |   14 ++++++++++++++
 1 file changed, 14 insertions(+)

diff --git a/src/tools.c b/src/tools.c
index e1ba241..4759222 100644
--- src/tools.c
+++ src/tools.c
@@ -17,9 +17,14 @@
 #endif
 
 #if defined(__FreeBSD__)
+#include <sys/param.h>
+#if __FreeBSD_version < 1300058
 #include <elf.h>
 #include <dlfcn.h>
 extern void *__elf_aux_vector;
+#else
+#include <sys/auxv.h>
+#endif
 #endif
 
 #if defined(__NetBSD__)
@@ -5018,6 +5023,7 @@ const char *get_exec_path()
 	if (execfn && execfn != ENOENT)
 		ret = (const char *)execfn;
 #elif defined(__FreeBSD__)
+#if __FreeBSD_version < 1300058
 	Elf_Auxinfo *auxv;
 	for (auxv = __elf_aux_vector; auxv->a_type != AT_NULL; ++auxv) {
 		if (auxv->a_type == AT_EXECPATH) {
@@ -5025,6 +5031,14 @@ const char *get_exec_path()
 			break;
 		}
 	}
+#else
+	static char execpath[MAXPATHLEN];
+
+	if (execpath[0] == '\0')
+		elf_aux_info(AT_EXECPATH, execpath, MAXPATHLEN);
+	if (execpath[0] != '\0')
+		ret = execpath;
+#endif
 #elif defined(__NetBSD__)
 	AuxInfo *auxv;
 	for (auxv = _dlauxinfo(); auxv->a_type != AT_NULL; ++auxv) {
-- 
1.7.10.4

