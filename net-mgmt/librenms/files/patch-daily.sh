--- daily.sh.orig	2024-07-09 01:33:51 UTC
+++ daily.sh
@@ -23,11 +23,11 @@ LIBRENMS_DIR=$(dirname "$DAILY_SCRIPT")
 # define DAILY_SCRIPT as the full path to this script and LIBRENMS_DIR as the directory this script is in
 DAILY_SCRIPT=$(readlink -f "$0")
 LIBRENMS_DIR=$(dirname "$DAILY_SCRIPT")
-COMPOSER="php ${LIBRENMS_DIR}/scripts/composer_wrapper.php --no-interaction"
+COMPOSER="%%LOCALBASE%%/bin/php ${LIBRENMS_DIR}/scripts/composer_wrapper.php --no-interaction"
 
 # set log_file, using librenms 'log_dir' config setting, if set
 # otherwise we default to <LibreNMS Install Directory>/logs
-LOG_DIR=$(php -r "@include '${LIBRENMS_DIR}/config.php'; echo isset(\$config['log_dir']) ? \$config['log_dir'] : '${LIBRENMS_DIR}/logs';")
+LOG_DIR=$(%%LOCALBASE%%/bin/php -r "@include '${LIBRENMS_DIR}/config.php'; echo isset(\$config['log_dir']) ? \$config['log_dir'] : '${LIBRENMS_DIR}/logs';")
 
 # get the librenms user
 # shellcheck source=.env.example
@@ -60,7 +60,7 @@ status_run() {
 
     printf "%-50s" "${arg_text}"
     echo "${arg_text}" >> "${log_file}"
-    tmp=$(bash -c "${arg_command}" 2>&1)
+    tmp=$(%%LOCALBASE%%/bin/bash -c "${arg_command}" 2>&1)
     exit_code=$?
     echo "${tmp}" >> "${log_file}"
     echo "Returned: ${exit_code}" >> "${log_file}"
@@ -72,7 +72,7 @@ status_run() {
     else
         printf " \\033[0;31mFAIL\\033[0m\\n"
         if [[ "${arg_option}" == "update" ]]; then
-            php "${LIBRENMS_DIR}/daily.php" -f notify -o "${tmp}"
+            %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f notify -o "${tmp}"
         fi
         if [[ -n "${tmp}" ]]; then
             # print output in case of failure
@@ -99,7 +99,7 @@ call_daily_php() {
     args=("$@")
 
     for arg in "${args[@]}"; do
-        php "${LIBRENMS_DIR}/daily.php" -f "${arg}"
+        %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f "${arg}"
     done
 }
 
@@ -121,7 +121,7 @@ set_notifiable_result() {
     arg_type=$1
     arg_result=$2
 
-    php "${LIBRENMS_DIR}/daily.php" -f handle_notifiable -t "${arg_type}" -r "${arg_result}"
+    %%LOCALBASE%%/bin/php "${LIBRENMS_DIR}/daily.php" -f handle_notifiable -t "${arg_type}" -r "${arg_result}"
 }
 
 #######################################
@@ -135,10 +135,10 @@ check_dependencies() {
     branch=$(git rev-parse --abbrev-ref HEAD)
     scripts/check_requirements.py > /dev/null 2>&1 || pip3 install -r requirements.txt > /dev/null 2>&1
 
-    ver_71=$(php -r "echo (int)version_compare(PHP_VERSION, '7.1.3', '<');")
-    ver_72=$(php -r "echo (int)version_compare(PHP_VERSION, '7.2.5', '<');")
-    ver_73=$(php -r "echo (int)version_compare(PHP_VERSION, '7.3', '<');")
-    ver_81=$(php -r "echo (int)version_compare(PHP_VERSION, '8.1', '<');")
+    ver_71=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.1.3', '<');")
+    ver_72=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.2.5', '<');")
+    ver_73=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '7.3', '<');")
+    ver_81=$(%%LOCALBASE%%/bin/php -r "echo (int)version_compare(PHP_VERSION, '8.1', '<');")
     python3=$(python3 -c "import sys;print(int(sys.version_info < (3, 4)))" 2> /dev/null)
     python_deps=$("${LIBRENMS_DIR}/scripts/check_requirements.py" > /dev/null 2>&1; echo $?)
     phpver="master"
@@ -276,7 +276,7 @@ main () {
     fi
 
     if [[ -z "$arg" ]]; then
-        up=$(php daily.php -f update >&2; echo $?)
+        up=$(%%LOCALBASE%%/bin/php daily.php -f update >&2; echo $?)
         if [[ "$up" == "0" ]]; then
             "${DAILY_SCRIPT}" no-code-update
             set_notifiable_result update 1  # make sure there are no update notifications if update is disabled
