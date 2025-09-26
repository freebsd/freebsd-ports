--- wg-quick/freebsd.bash.orig	2021-09-13 22:43:31 UTC
+++ wg-quick/freebsd.bash
@@ -27,6 +27,7 @@ SAVE_CONFIG=0
 CONFIG_FILE=""
 PROGRAM="${0##*/}"
 ARGS=( "$@" )
+FREEBSD_MAJOR_VERSION=$(freebsd-version | cut -d. -f1)
 
 cmd() {
 	echo "[#] $*" >&3
@@ -283,20 +284,28 @@ monitor_daemon() {
 	echo "[+] Backgrounding route monitor" >&2
 	(make_temp
 	trap 'del_routes; clean_temp; exit 0' INT TERM EXIT
+	local event grep_for pid
+	if [[ "$FREEBSD_MAJOR_VERSION" -lt 14 ]]; then
+		grep_for="RTM_"
+	elif [[ $AUTO_ROUTE4 -eq 1 || $AUTO_ROUTE6 -eq 1 ]]; then
+		grep_for="iface" # needs refinement
+	else
+		grep_for="(add/repl|delete) iface iface#[0-9]{1,4} $INTERFACE "
+	fi
 	exec >/dev/null 2>&1
-	exec 19< <(exec route -n monitor)
-	local event pid=$!
+	exec 19< <(exec sh -c "route -n monitor | grep -E --line-buffered '$grep_for'")
+	monitor_ppid=$!
 	# TODO: this should also check to see if the endpoint actually changes
 	# in response to incoming packets, and then call set_endpoint_direct_route
 	# then too. That function should be able to gracefully cleanup if the
 	# endpoints change.
 	while read -u 19 -r event; do
-		[[ $event == RTM_* ]] || continue
 		ifconfig "$INTERFACE" >/dev/null 2>&1 || break
 		[[ $AUTO_ROUTE4 -eq 1 || $AUTO_ROUTE6 -eq 1 ]] && set_endpoint_direct_route
 		# TODO: set the mtu as well, but only if up
 	done
-	kill $pid) & disown
+	pkill -P "$monitor_ppid" route || true
+	) & disown
 }
 
 HAVE_SET_DNS=0
