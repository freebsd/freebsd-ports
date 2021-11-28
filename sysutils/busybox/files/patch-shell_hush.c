--- shell/hush.c.orig	2021-08-15 18:44:35 UTC
+++ shell/hush.c
@@ -346,7 +346,7 @@
 #if !(defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) \
 	|| defined(__APPLE__) \
     )
-# include <malloc.h>   /* for malloc_trim */
+# include <stdlib.h>   /* for malloc_trim */
 #endif
 #include <glob.h>
 /* #include <dmalloc.h> */
@@ -2211,6 +2211,18 @@ static int check_and_run_traps(void)
 	return last_sig;
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
 
 static const char *get_cwd(int force)
 {
