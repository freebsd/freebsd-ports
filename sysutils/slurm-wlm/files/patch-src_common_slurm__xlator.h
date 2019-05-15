--- src/common/slurm_xlator.h.orig	2019-04-12 04:20:25 UTC
+++ src/common/slurm_xlator.h
@@ -299,7 +299,9 @@
  * The header file used only for #define values. */
 
 /* strlcpy.[ch] functions */
+#if (!HAVE_STRLCPY)	// Match this to src/common/strlcpy.c
 #define	strlcpy			slurm_strlcpy
+#endif
 
 /* switch.[ch] functions
  * None exported today.
