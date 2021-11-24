--- libcork/src/libcork/posix/env.c.orig	2019-07-24 14:01:14 UTC
+++ libcork/src/libcork/posix/env.c
@@ -194,12 +194,19 @@ cork_env_set_vars(void *user_data, struct cork_hash_ta
  *
  * [1] http://www.gnu.org/software/gnulib/manual/html_node/clearenv.html
  */
+
+#if (defined(__FreeBSD__) && (__FreeBSD__ < 14))
+/* Since FreeBSD 14.0-CURRENT, the clearenv(3) function was added to stdlib.
+ * See https://reviews.freebsd.org/R10:597b02675751e48dd04777f1e91fee382bf3a966
+ */
+
 static void
 clearenv(void)
 {
     *environ = NULL;
 }
 
+#endif
 #else
 /* Otherwise assume that we have clearenv available. */
 #endif
