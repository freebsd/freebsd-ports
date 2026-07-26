--- scripts/postgresql-setup.sh.orig	2026-06-17 11:51:59 UTC
+++ scripts/postgresql-setup.sh
@@ -208,11 +208,6 @@ function create_snapshot {
 	  sha256sum | head -c 64 | sed -e "s/$/  ${tgz_file}\n/" > "${tgz_file}.sha256sum"
 	mv "${tgz_file}.tmp" "${tgz_file}"
 	rm "${recursive}" "${force}" "${tmp_dir}"
-	if test "$(tar "${test}" --file "${tgz_file}")" ; then
-	  echo "Tar reports the snapshot file as being corrupt."
-	  echo "It is not safe to drop the database and restore using this file."
-	  exit 1
-	fi
 	echo "Created ${tgz_file} + .sha256sum"
 }
 
