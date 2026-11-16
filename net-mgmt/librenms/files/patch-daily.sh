--- daily.sh.orig	2026-11-16 09:09:03 UTC
+++ daily.sh
@@ -23,13 +23,13 @@ LIBRENMS_DIR=$(dirname "$DAILY_SCRIPT")
 # define DAILY_SCRIPT as the full path to this script and LIBRENMS_DIR as the directory this script is in
 DAILY_SCRIPT=$(readlink -f "$0")
 LIBRENMS_DIR=$(dirname "$DAILY_SCRIPT")
-COMPOSER="php ${LIBRENMS_DIR}/scripts/composer_wrapper.php --no-interaction"
+COMPOSER="%%LOCALBASE%%/bin/php ${LIBRENMS_DIR}/scripts/composer_wrapper.php --no-interaction"
 # exists while test patches applied with lnms patch:apply are present
 PATCHES_FILE="${LIBRENMS_DIR}/storage/app/patches/patches.json"
 
 # set log_file, using librenms 'log_dir' config setting, if set
 # otherwise we default to <LibreNMS Install Directory>/logs
-LOG_DIR=$(php -r "@include '${LIBRENMS_DIR}/config.php'; echo isset(\$config['log_dir']) ? \$config['log_dir'] : '${LIBRENMS_DIR}/logs';")
+LOG_DIR=$(%%LOCALBASE%%/bin/php -r "@include '${LIBRENMS_DIR}/config.php'; echo isset(\$config['log_dir']) ? \$config['log_dir'] : '${LIBRENMS_DIR}/logs';")
 
 # get the librenms user
 # shellcheck source=.env.example
@@ -73,7 +73,7 @@ status_run() {
 
     printf "%-50s" "${arg_text}"
     log_line "${arg_text}"
-    tmp=$(bash -c "${arg_command}" 2>&1)
+    tmp=$(%%LOCALBASE%%/bin/bash -c "${arg_command}" 2>&1)
     exit_code=$?
     echo "${tmp}" >> "${log_file}"
     log_line "Returned: ${exit_code}"
@@ -85,7 +85,7 @@ status_run() {
     else
         printf " \\033[0;31mFAIL\\033[0m\\n"
         if [[ "${arg_option}" == "update" ]]; then
-            php "${LIBRENMS_DIR}/daily.php" -f notify -o "${tmp}"
+            %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f notify -o "${tmp}"
         fi
         if [[ -n "${tmp}" ]]; then
             # print output in case of failure
@@ -130,7 +130,7 @@ call_daily_php() {
     args=("$@")
 
     for arg in "${args[@]}"; do
-        php "${LIBRENMS_DIR}/daily.php" -f "${arg}"
+        %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f "${arg}"
     done
 }
 
@@ -152,7 +152,7 @@ set_notifiable_result() {
     arg_type=$1
     arg_result=$2
 
-    php "${LIBRENMS_DIR}/daily.php" -f handle_notifiable -t "${arg_type}" -r "${arg_result}"
+    %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f handle_notifiable -t "${arg_type}" -r "${arg_result}"
 }
 
 #######################################
@@ -168,12 +168,12 @@ check_dependencies() {
     # attempt to install python requirements, will likely fail
     pip3 install -r requirements.txt > /dev/null 2>&1
 
-    ver_71=$(php -r "echo (int)version_compare(PHP_VERSION, '7.1.3', '<');")
-    ver_72=$(php -r "echo (int)version_compare(PHP_VERSION, '7.2.5', '<');")
-    ver_73=$(php -r "echo (int)version_compare(PHP_VERSION, '7.3', '<');")
-    ver_81=$(php -r "echo (int)version_compare(PHP_VERSION, '8.1', '<');")
-    ver_82=$(php -r "echo (int)version_compare(PHP_VERSION, '8.2', '<');")
-    ver_84=$(php -r "echo (int)version_compare(PHP_VERSION, '8.4', '<');")
+    ver_71=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.1.3', '<');")
+    ver_72=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.2.5', '<');")
+    ver_73=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.3', '<');")
+    ver_81=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '8.1', '<');")
+    ver_82=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '8.2', '<');")
+    ver_84=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '8.4', '<');")
     python3=$(python3 -c "import sys;print(int(sys.version_info < (3, 4)))" 2> /dev/null)
     phpver="master"
     pythonver="master"
@@ -311,7 +311,7 @@ main () {
     fi
 
     if [[ -z "$arg" ]]; then
-        up=$(php daily.php -f update >&2; echo $?)
+        up=$(%%LOCALBASE%%/bin/php daily.php -f update >&2; echo $?)
         if [[ "$up" == "0" ]]; then
             "${DAILY_SCRIPT}" no-code-update || return $?
             set_notifiable_result update 1  # make sure there are no update notifications if update is disabled
