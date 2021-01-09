--- shell/hush.c.orig	2021-01-01 13:30:58 UTC
+++ shell/hush.c
@@ -348,7 +348,7 @@
 #if !(defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) \
 	|| defined(__APPLE__) \
     )
-# include <malloc.h>   /* for malloc_trim */
+# include <stdlib.h>   /* for malloc_trim */
 #endif
 #include <glob.h>
 /* #include <dmalloc.h> */
@@ -2091,6 +2091,18 @@ static void hush_exit(int exitcode)
 #endif
 }
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 1202000
+int
+sigisemptyset(const sigset_t *set)
+{
+	int i;
+
+	for (i = 0; i < _SIG_WORDS; i++)
+		if (set->__bits[i] != 0)
+			return (0);
+	return (1);
+}
+#endif
 
 //TODO: return a mask of ALL handled sigs?
 static int check_and_run_traps(void)
