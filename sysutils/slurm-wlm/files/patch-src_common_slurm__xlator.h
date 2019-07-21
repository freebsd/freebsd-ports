--- src/common/slurm_xlator.h.orig	2019-05-28 17:23:14 UTC
+++ src/common/slurm_xlator.h
@@ -300,7 +300,9 @@
  * The header file used only for #define values. */
 
 /* strlcpy.[ch] functions */
+#if (!HAVE_STRLCPY)	// Match this to src/common/strlcpy.c
 #define	strlcpy			slurm_strlcpy
+#endif
 
 /* switch.[ch] functions
  * None exported today.
