--- tests/progress_pty_smoke.sh.orig	2026-10-20 16:14:40 UTC
+++ tests/progress_pty_smoke.sh
@@ -61,7 +61,7 @@ pty_invoke() {
   for arg in "$@"; do wrapper+=" $(printf '%q' "$arg")"; done
   wrapper+=" ; } ; __status=\$? ; printf '\\n__NIFT_PROGRESS_EXIT__=%s\\n' \"\$__status\" ; exit \"\$__status\""
   case "$platform" in
-    Darwin)
+    Darwin|FreeBSD)
       script -q "$transcript" /bin/sh -c "$wrapper" >"$TMP/pty.out" 2>&1 || true
       ;;
     *)
