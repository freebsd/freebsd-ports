--- src/password-store.sh.orig	2023-08-30 23:03:53 UTC
+++ src/password-store.sh
@@ -225,14 +225,6 @@ tmpdir() {
 		}
 		trap remove_tmpfile EXIT
 	else
-		[[ $warn -eq 1 ]] && yesno "$(cat <<-_EOF
-		Your system does not have /dev/shm, which means that it may
-		be difficult to entirely erase the temporary non-encrypted
-		password file after editing.
-
-		Are you sure you would like to continue?
-		_EOF
-		)"
 		SECURE_TMPDIR="$(mktemp -d "${TMPDIR:-/tmp}/$template")"
 		shred_tmpfile() {
 			find "$SECURE_TMPDIR" -type f -exec $SHRED {} +
