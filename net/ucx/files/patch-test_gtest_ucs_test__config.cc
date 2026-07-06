--- test/gtest/ucs/test_config.cc.orig	2026-02-05 12:41:56 UTC
+++ test/gtest/ucs/test_config.cc
@@ -365,22 +365,18 @@ class test_config : public ucs::test { (protected)
         std::string
         dump(ucs_config_print_flags_t flags, const char *filter = nullptr) const
         {
-            char *dump_data = nullptr;
+	    char *dump_data = nullptr;
             size_t dump_size;
-            char line_buf[1024];
             std::string res;
 
             FILE *file = open_memstream(&dump_data, &dump_size);
             ucs_config_parser_print_opts(file, "", &m_opts, car_opts_table,
                                          nullptr, UCS_DEFAULT_ENV_PREFIX, flags,
                                          filter);
-            fseek(file, 0, SEEK_SET);
-
-            while (fgets(line_buf, sizeof(line_buf), file)) {
-                res += line_buf;
-            }
-
             fclose(file);
+            if (dump_data != nullptr) {
+                res = std::string(dump_data, dump_size);
+            }
             free(dump_data);
             return res;
         }
@@ -432,12 +428,19 @@ class test_config : public ucs::test { (protected)
         ucs_config_parser_print_opts(file, "", *opts, car_opts_table, prefix,
                                      UCS_DEFAULT_ENV_PREFIX,
                                      (ucs_config_print_flags_t)flags, nullptr);
-
+	fclose(file);
         /* Sanity check - all lines begin with UCS_ */
         unsigned num_lines = 0;
-        fseek(file, 0, SEEK_SET);
-        while (fgets(line_buf, sizeof(line_buf), file)) {
-            if (line_buf[0] == '\n') {
+        char *pos = dump_data;
+        char *end = dump_data + dump_size;
+        while (pos < end) {
+            char *nl = (char*)memchr(pos, '\n', end - pos);
+            size_t len = nl ? (size_t)(nl - pos) : (size_t)(end - pos);
+            if (len >= sizeof(line_buf)) len = sizeof(line_buf) - 1;
+            memcpy(line_buf, pos, len);
+            line_buf[len] = '\0';
+            pos = nl ? nl + 1 : end;
+            if (line_buf[0] == '\n'|| line_buf[0] == '\0') {
                 continue;
             }
 
@@ -465,7 +468,7 @@ class test_config : public ucs::test { (protected)
 
                 size_t cnt = 0;
                 for (size_t i = 2 + strlen("alias of: ") + 1;
-                     line_buf[i] != '\n'; i++) {
+                    line_buf[i] != '\n' && line_buf[i] != '\0'; i++) {
                     alias[cnt++] = line_buf[i];
                 }
             }
