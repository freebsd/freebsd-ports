--- tests/run-check.sh.orig	2024-05-26 22:09:20 UTC
+++ tests/run-check.sh
@@ -13,7 +13,7 @@ do
 do
 	tests_count="$((tests_count + 1))"
 	rm -rf test-database*
-	if ${CC:-cc} -Isrc -DTEST -o ./a.out "$test_file" -L. -lnewsraft && env LD_LIBRARY_PATH=. ./a.out; then
+	if ${CC:-cc} `pkg-config --cflags sqlite3` -Isrc -DTEST -o ./a.out "$test_file" -L. -lnewsraft && env LD_LIBRARY_PATH=. ./a.out; then
 		echo "[OKAY] $test_file"
 		okays_count="$((okays_count + 1))"
 	else
