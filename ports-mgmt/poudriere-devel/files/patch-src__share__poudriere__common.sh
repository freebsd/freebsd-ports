--- ./src/share/poudriere/common.sh.orig	2013-12-30 15:33:59.000000000 -0600
+++ ./src/share/poudriere/common.sh	2013-12-30 20:19:11.627128632 -0600
@@ -2996,6 +2996,7 @@
 
 parallel_run() {
 	local cmd="$1"
+	local ret=0
 	shift 1
 
 	if [ ${NBPARALLEL} -eq ${PARALLEL_JOBS} ]; then
@@ -3008,11 +3009,13 @@
 	_SHOULD_REAP=$((_SHOULD_REAP + 1))
 	if [ ${_SHOULD_REAP} -eq 16 ]; then
 		_SHOULD_REAP=0
-		_reap_children || return $?
+		_reap_children || ret=$?
 	fi
 
 	PARALLEL_CHILD=1 parallel_exec $cmd "$@" &
 	PARALLEL_PIDS="${PARALLEL_PIDS} $! "
+
+	return ${ret}
 }
 
 find_all_pool_references() {
