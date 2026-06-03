--- plugins/experimental/uri_signing/match.cc.orig	2024-11-12 19:49:58 UTC
+++ plugins/experimental/uri_signing/match.cc
@@ -16,7 +16,8 @@
  * limitations under the License.
  */
 
-#include <regex.h>
+#define PCRE2_CODE_UNIT_WIDTH 8
+#include <pcre2.h>
 #include "common.h"
 
 #include <cstring>
@@ -30,27 +31,39 @@ match_regex(const char *pattern, const char *uri)
 bool
 match_regex(const char *pattern, const char *uri)
 {
-  struct re_pattern_buffer pat_buff;
+  int errorcode;
+  PCRE2_SIZE erroroffset;
 
-  pat_buff.translate = nullptr;
-  pat_buff.fastmap   = nullptr;
-  pat_buff.buffer    = nullptr;
-  pat_buff.allocated = 0;
+  pcre2_code *re = pcre2_compile(
+    (PCRE2_SPTR)pattern,             // the pattern to compile
+    PCRE2_ZERO_TERMINATED,           // indicates pattern is zero-terminated
+    0,                               // default options
+    &errorcode,                      // for error code
+    &erroroffset,                    // for error offset
+    nullptr                          // use default compile context
+  );
 
-  re_syntax_options = RE_SYNTAX_POSIX_MINIMAL_EXTENDED;
-
-  PluginDebug("Testing regex pattern /%s/ against \"%s\"", pattern, uri);
-
-  const char *comp_err = re_compile_pattern(pattern, strlen(pattern), &pat_buff);
-
-  if (comp_err) {
-    PluginDebug("Regex Compilation ERROR: %s", comp_err);
+  if (re == nullptr) {
+    PCRE2_UCHAR buffer[256];
+    pcre2_get_error_message(errorcode, buffer, sizeof(buffer));
+    PluginDebug("Regex Compilation ERROR: %s", buffer);
     return false;
   }
 
-  int match_ret;
-  match_ret = re_match(&pat_buff, uri, strlen(uri), 0, nullptr);
-  regfree(&pat_buff);
+  pcre2_match_data *match_data = pcre2_match_data_create_from_pattern(re, nullptr);
+
+  int match_ret = pcre2_match(
+    re,                              // the compiled pattern
+    (PCRE2_SPTR)uri,                 // the subject string
+    strlen(uri),                     // the length of the subject
+    0,                               // start at offset 0 in the subject
+    0,                               // default options
+    match_data,                      // block for storing the result
+    nullptr                          // use default match context
+  );
+
+  pcre2_match_data_free(match_data);
+  pcre2_code_free(re);
 
   return match_ret >= 0;
 }
