--- src/wl.c.orig	Wed Apr 19 21:42:30 2006
+++ src/wl.c	Mon Jun  4 21:49:40 2007
@@ -4,12 +4,92 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <time.h>
-#include <argz.h>
+#include <assert.h>
+#include <errno.h>
 #include "wl.h"
 #include "opts.h"
 int wl_index = 0;
 char*wl = NULL;
 size_t wl_max = 0;
+
+// -------------------- XXX ---------------------
+
+static char *
+argz_next (argz, argz_len, entry)
+     char *argz;
+     size_t argz_len;
+     const char *entry;
+{
+  assert ((argz && argz_len) || (!argz && !argz_len));
+
+  if (entry)
+    {
+      /* Either ARGZ/ARGZ_LEN is empty, or ENTRY points into an address
+	 within the ARGZ vector.  */
+      assert ((!argz && !argz_len)
+	      || ((argz <= entry) && (entry < (argz + argz_len))));
+
+      /* Move to the char immediately after the terminating
+	 '\0' of ENTRY.  */
+      entry = 1+ strchr (entry, '\0');
+
+      /* Return either the new ENTRY, or else NULL if ARGZ is
+	 exhausted.  */
+      return (entry >= argz + argz_len) ? 0 : (char *) entry;
+    }
+  else
+    {
+      /* This should probably be flagged as a programmer error,
+	 since starting an argz_next loop with the iterator set
+	 to ARGZ is safer.  To preserve semantics, handle the NULL
+	 case by returning the start of ARGZ (if any).  */
+      if (argz_len > 0)
+	return argz;
+      else
+	return 0;
+    }
+}
+
+static int
+argz_append (char **argz, size_t *argz_len, const char *buf, size_t buf_len)
+{
+  size_t new_argz_len = *argz_len + buf_len;
+  char *new_argz = realloc (*argz, new_argz_len);
+  if (new_argz)
+    {
+      memcpy (new_argz + *argz_len, buf, buf_len);
+      *argz = new_argz;
+      *argz_len = new_argz_len;
+      return 0;
+    }
+  else
+    return ENOMEM;
+}
+
+static int
+argz_add (char **argz, size_t *argz_len, const char *str)
+{
+  return argz_append (argz, argz_len, str, strlen (str) + 1);
+}
+
+static void
+argz_delete (char **argz, size_t *argz_len, char *entry)
+{
+  if (entry)
+    /* Get rid of the old value for NAME.  */
+    {
+      size_t entry_len = strlen (entry) + 1;
+      *argz_len -= entry_len;
+      memmove (entry, entry + entry_len, *argz_len - (entry - *argz));
+      if (*argz_len == 0)
+	{
+	  free (*argz);
+	  *argz = 0;
+	}
+    }
+}
+
+// -------------------- XXX ---------------------
 
 void 
 wl_init ()
