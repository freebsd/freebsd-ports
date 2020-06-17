--- src/string_utils.c.orig	2020-02-24 11:50:22 UTC
+++ src/string_utils.c
@@ -16,6 +16,7 @@
    along with this program; if not, see <http://www.gnu.org/licenses/>.
    */
 
+#include <glib.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <assert.h>
@@ -62,3 +63,19 @@ fs_str_copy (char *dest, char *end, const char *src)
     return ptr;
 }
 
+int
+strverscmp (const char *s1,
+            const char *s2)
+{
+    gchar *tmp1, *tmp2;
+    gint ret;
+
+    tmp1 = g_utf8_collate_key_for_filename(s1, -1);
+    tmp2 = g_utf8_collate_key_for_filename(s2, -1);
+
+    ret = strcmp(tmp1, tmp2);
+
+    g_free(tmp1);
+    g_free(tmp2);
+    return ret;
+}
