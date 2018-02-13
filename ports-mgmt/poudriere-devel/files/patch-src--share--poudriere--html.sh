commit 8f9fdcc9691dcb6ab3619bbced22beb108bfcbb1
Author: Bryan Drewery <bryan@shatow.net>
Date:   Sat Feb 3 16:39:51 2018 -0800

    HTML: Hide harmless shared lock failures

diff --git src/share/poudriere/include/html.sh src/share/poudriere/include/html.sh
index c56cb6520..98bcd84f4 100644
--- src/share/poudriere/include/html.sh
+++ src/share/poudriere/include/html.sh
@@ -78,11 +78,11 @@ html_json_main() {
 build_all_json() {
 	critical_start
 	build_json
-	if slock_acquire "json_jail_${MASTERNAME}"; then
+	if slock_acquire "json_jail_${MASTERNAME}" 2>/dev/null; then
 		build_jail_json
 		slock_release "json_jail_${MASTERNAME}"
 	fi
-	if slock_acquire "json_top"; then
+	if slock_acquire "json_top" 2>/dev/null; then
 		build_top_json
 		slock_release "json_top"
 	fi
@@ -173,7 +173,7 @@ install_html_files() {
 	local base="$2"
 	local dest="$3"
 
-	slock_acquire html_base || return 0
+	slock_acquire html_base 2>/dev/null || return 0
 
 	# Update the base copy
 	mkdir -p "${base}"
