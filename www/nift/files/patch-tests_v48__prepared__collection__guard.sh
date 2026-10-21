--- tests/v48_prepared_collection_guard.sh.orig	2026-10-20 16:09:02 UTC
+++ tests/v48_prepared_collection_guard.sh
@@ -8,7 +8,7 @@ t=$(mktemp -d); trap 'rm -rf "$t"' EXIT
 NIFT=${NIFT:-./nift}
 case "$NIFT" in /*) B="$NIFT";; *) B="$(pwd)/$NIFT";; esac
 t=$(mktemp -d); trap 'rm -rf "$t"' EXIT
-run(){ printf '%s\n' "$2" > "$t/p.f"; : > "$t/t"; local r; for r in 1 2 3 4 5; do /usr/bin/time -f "%e" "$B" "$t/p.f" >/dev/null 2>>"$t/t"; done; python3 -c "import statistics;print(int(statistics.median([float(x) for x in open('$t/t')])*1000))"; }
+run(){ printf '%s\n' "$2" > "$t/p.f"; : > "$t/t"; local r; for r in 1 2 3 4 5; do /usr/bin/time -p "$B" "$t/p.f" >/dev/null 2>>"$t/t"; done; python3 -c "import statistics;print(int(statistics.median([float(x.split()[1]) for x in open('$t/t') if x.startswith('real ')])*1000))"; }
 push=$(run push 'arr := []
 i := 1
 while(i <= 100000) { arr.push(i); i += 1 }
@@ -28,4 +28,4 @@ done
   IFS=: read -r v label <<<"$name"
   if [ "$v" -gt "$bound" ]; then echo "FAIL $label scaling: value=${v}ms bound=${bound}ms (push=${push}ms)" >&2; exit 1; fi
 done
-echo "PASS v4.8 prepared collection-method scaling guard (push ${push}ms, contains ${contains}ms, set ${sete}ms, bound ${bound}ms)"
\ No newline at end of file
+echo "PASS v4.8 prepared collection-method scaling guard (push ${push}ms, contains ${contains}ms, set ${sete}ms, bound ${bound}ms)"
