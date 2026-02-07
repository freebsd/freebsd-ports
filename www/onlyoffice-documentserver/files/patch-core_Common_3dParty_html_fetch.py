--- core/Common/3dParty/html/fetch.py.orig	2025-04-16 08:37:24 UTC
+++ core/Common/3dParty/html/fetch.py
@@ -8,16 +8,16 @@ import os
 
 base_directory = os.getcwd()
 
-if not base.is_dir("gumbo-parser"):
-  base.cmd("git", ["clone", "https://github.com/google/gumbo-parser.git"])
-  base.cmd_in_dir("gumbo-parser", "git", ["checkout", "aa91b27b02c0c80c482e24348a457ed7c3c088e0"])
+if base.is_dir("gumbo-parser"):
+#  base.cmd("git", ["clone", "https://github.com/google/gumbo-parser.git"])
+#  base.cmd_in_dir("gumbo-parser", "git", ["checkout", "aa91b27b02c0c80c482e24348a457ed7c3c088e0"])
 
   # fix gumbo
   base.replaceInFile(base_directory + "/gumbo-parser/src/tag.c", "isspace(*c)", "isspace((unsigned char)*c)")
 
-if not base.is_dir("katana-parser"):
-  base.cmd("git", ["clone", "https://github.com/jasenhuang/katana-parser.git"])
-  base.cmd_in_dir("katana-parser", "git", ["checkout", "be6df458d4540eee375c513958dcb862a391cdd1"])
+if base.is_dir("katana-parser"):
+#  base.cmd("git", ["clone", "https://github.com/jasenhuang/katana-parser.git"])
+#  base.cmd_in_dir("katana-parser", "git", ["checkout", "be6df458d4540eee375c513958dcb862a391cdd1"])
 
   # fix katana
   base.replaceInFileUtf8(base_directory + "/katana-parser/src/tokenizer.c", "static inline bool katana_is_html_space(char c);", "static inline bool2 katana_is_html_space(char c);")
