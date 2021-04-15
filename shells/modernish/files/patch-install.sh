--- install.sh.orig	2021-04-15 11:21:11 UTC
+++ install.sh
@@ -119,7 +119,7 @@ case ${opt_s+s} in
 	( * )	MSH_SHELL=$opt_s
 		export MSH_SHELL
 		echo "Relaunching ${0##*/} with $MSH_SHELL..." >&2
-		exec "$MSH_SHELL" "$MSH_PREFIX/${0##*/}" --relaunch "$@" ;;
+		exec "$MSH_SHELL" -x "$MSH_PREFIX/${0##*/}" --relaunch "$@" ;;
 	esac ;;
 esac
 
