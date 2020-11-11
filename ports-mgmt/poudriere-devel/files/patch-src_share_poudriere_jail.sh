--- src/share/poudriere/jail.sh.orig	2020-11-11 22:16:56 UTC
+++ src/share/poudriere/jail.sh
@@ -174,7 +174,7 @@ update_version() {
 	local version_extra="$1"
 
 	if [ -r "${SRC_BASE}/sys/conf/newvers.sh" ]; then
-		eval `grep "^[RB][A-Z]*=" ${SRC_BASE}/sys/conf/newvers.sh `
+		eval `grep "^REVISION=\|^BRANCH=" ${SRC_BASE}/sys/conf/newvers.sh `
 		RELEASE=${REVISION}-${BRANCH}
 	else
 		RELEASE=$(jget ${JAILNAME} version)
