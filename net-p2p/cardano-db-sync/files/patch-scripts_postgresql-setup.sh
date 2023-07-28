--- scripts/postgresql-setup.sh.orig	2023-07-05 14:55:16 UTC
+++ scripts/postgresql-setup.sh
@@ -161,17 +161,11 @@ function create_snapshot {
 	pg_dump --no-owner --schema=public --jobs="${numcores}" "${PGDATABASE}" --format=directory --file="${tmp_dir}/db/"
 	lstate_gz_file=$(basename "${ledger_file}").gz
 	gzip --to-stdout "${ledger_file}" > "${tmp_dir}/$(basename "${ledger_file}").gz"
-	tree "${tmp_dir}"
 	# Use plain tar here because the database dump files and the ledger state file are already gzipped.
 	tar cvf - --directory "${tmp_dir}" "db" "${lstate_gz_file}" | tee "${tgz_file}.tmp" \
 		| sha256sum | head -c 64 | sed -e "s/$/  ${tgz_file}\n/" > "${tgz_file}.sha256sum"
 	mv "${tgz_file}.tmp" "${tgz_file}"
 	rm "${recursive}" "${force}" "${tmp_dir}"
-	if test "$(tar "${test}" --file "${tgz_file}")" ; then
-	  echo "Tar reports the snapshot file as being corrupt."
-	  echo "It is not safe to drop the database and restore using this file."
-	  exit 1
-	  fi
 	echo "Created ${tgz_file} + .sha256sum"
 }
 
