--- muttlib.c.orig	2016-10-08 19:35:50 UTC
+++ muttlib.c
@@ -802,16 +802,15 @@ void mutt_merge_envelopes(ENVELOPE* base
 void _mutt_mktemp (char *s, size_t slen, const char *prefix, const char *suffix,
                    const char *src, int line)
 {
-  size_t n = snprintf (s, slen, "%s/%s-%s-%d-%d-%ld%ld%s%s",
-      NONULL (Tempdir), NONULL (prefix), NONULL (Hostname),
-      (int) getuid (), (int) getpid (), random (), random (),
-      suffix ? "." : "", NONULL (suffix));
+  size_t n = snprintf (s, slen, "%s/mutt-%s-XXXXXXXX", NONULL (Tempdir), NONULL (Hostname));
   if (n >= slen)
     dprint (1, (debugfile, "%s:%d: ERROR: insufficient buffer space to hold temporary filename! slen=%zu but need %zu\n",
 	    src, line, slen, n));
-  dprint (3, (debugfile, "%s:%d: mutt_mktemp returns \"%s\".\n", src, line, s));
-  if (unlink (s) && errno != ENOENT)
-    dprint (1, (debugfile, "%s:%d: ERROR: unlink(\"%s\"): %s (errno %d)\n", src, line, s, strerror (errno), errno));
+  if (mktemp (s)) { 
+    dprint (3, (debugfile, "%s:%d: mutt_mktemp returns \"%s\".\n", src, line, s));
+  } else {
+    dprint (1, (debugfile, "%s:%d: ERROR: mktemp(\"%s\"): %s (errno %d)\n", src, line, s, strerror (errno), errno));
+  }
 }
 
 void mutt_free_alias (ALIAS **p)
