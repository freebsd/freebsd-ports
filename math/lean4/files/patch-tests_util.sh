-- Fix mktemp usage to be compatible with FreeBSD.
-- FreeBSD's mktemp does not support --tmpdir/--directory flags the same way
-- GNU coreutils does; on FreeBSD those flags create the directory in CWD and
-- return a relative path, which breaks tests that pushd into subdirectories.
--- tests/util.sh.orig	2026-05-26 18:04:51 UTC
+++ tests/util.sh
@@ -5,7 +5,7 @@ DIFF="diff -au --strip-trailing-cr --color=always"
 DIFF="diff -au --strip-trailing-cr --color=always"
 
 # Temporary directory to store unnamed output files
-TMP_DIR="$(mktemp --tmpdir --directory lean4-test-suite.XXXXXXXXXX)"
+TMP_DIR="$(mktemp -d "${TMPDIR:-/tmp}/lean4-test-suite.XXXXXXXXXX")"
 trap 'rm -rf "$TMP_DIR"' EXIT
 
 function fail {
