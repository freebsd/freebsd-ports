--- src/share/poudriere/common.sh.orig	2025-10-13 14:51:41 UTC
+++ src/share/poudriere/common.sh
@@ -993,7 +993,7 @@ jstart() {
 	jail -c persist "name=${name:?}" \
 		"path=${mpath:?}" \
 		"host.hostname=${BUILDER_HOSTNAME-${name}}" \
-		"${network}" ${JAIL_PARAMS-}
+		${network} ${JAIL_PARAMS-}
 	# Allow networking in -n jail
 	jail -c persist "name=${name}-n" \
 		"path=${mpath:?}" \
