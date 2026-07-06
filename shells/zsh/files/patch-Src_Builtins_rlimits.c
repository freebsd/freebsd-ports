--- Src/Builtins/rlimits.c.orig	2022-05-08 06:18:22 UTC
+++ Src/Builtins/rlimits.c
@@ -172,6 +172,14 @@ static const resinfo_T known_resources[] = {
     {RLIMIT_TCACHE, "cachedthreads", ZLIMTYPE_NUMBER, 1,
 		'N', "cached threads"},
 # endif
+# ifdef RLIMIT_PIPEBUF		/* FreeBSD 14.2+ */
+    {RLIMIT_PIPEBUF, "pipebuf", ZLIMTYPE_MEMORY, 1024,
+		'y', "pipe buffer size (kbytes)"},
+# endif
+# ifdef RLIMIT_VMM		/* FreeBSD 15+ */
+    {RLIMIT_VMM, "virtualmachines", ZLIMTYPE_NUMBER, 1,
+		'V', "virtual machines"},
+# endif
 };
 
 /* resinfo[RLIMIT_XXX] points to the corresponding entry
