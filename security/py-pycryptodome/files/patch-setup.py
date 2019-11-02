commit b3a394d0837ff92919d35d01de9952b8809e802d
Author: Helder Eijs <helderijs@gmail.com>
Date:   Wed Aug 28 07:52:19 2019 +0200

    Force UTF-8 encoding when translating files

diff --git ./setup.py ./setup.py
index 9d88bc1e..1d70caad 100644
--- ./setup.py
+++ ./setup.py
@@ -222,14 +222,18 @@ def create_cryptodome_lib():
                 if full_file_name_src != "py.typed":
                     continue

-            with open(full_file_name_dst, "rt") as fd:
+            if sys.version_info[0] > 2:
+                extra_param = { "encoding": "utf-8" }
+            else:
+                extra_param = {}
+            with open(full_file_name_dst, "rt", **extra_param) as fd:
                 content = (fd.read().
                            replace("Crypto.", "Cryptodome.").
                            replace("Crypto ", "Cryptodome ").
                            replace("'Crypto'", "'Cryptodome'").
                            replace('"Crypto"', '"Cryptodome"'))
             os.remove(full_file_name_dst)
-            with open(full_file_name_dst, "wt") as fd:
+            with open(full_file_name_dst, "wt", **extra_param) as fd:
                 fd.write(content)
