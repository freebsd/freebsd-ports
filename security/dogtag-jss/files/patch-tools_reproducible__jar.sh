--- tools/reproducible_jar.sh.orig	2026-07-16 09:37:55 UTC
+++ tools/reproducible_jar.sh
@@ -51,8 +51,8 @@ abs_jar="$(realpath "$1")"
 }
 
 abs_jar="$(realpath "$1")"
-abs_path="$(realpath "$2")"
-abs_output="$(realpath "$3")"
+abs_path="$(cd "$(dirname "$2")" && pwd)/$(basename "$2")"
+abs_output="$(cd "$(dirname "$3")" && pwd)/$(basename "$3")"
 
 extract "$abs_jar" "$abs_path"
 normalize_timestamps "$abs_path"
