--- daily.sh.orig	2017-03-26 12:06:00 UTC
+++ daily.sh
@@ -113,7 +113,7 @@ main () {
         # only try to su if we are root (or sudo)
         if [[ "$EUID" -eq 0 ]]; then
             echo "Re-running ${DAILY_SCRIPT} as ${LIBRENMS_USER} user"
-            su -l "$LIBRENMS_USER" -c "$DAILY_SCRIPT $@"
+            sudo -u "$LIBRENMS_USER" "$DAILY_SCRIPT"
             exit;
         fi
 
@@ -123,27 +123,6 @@ main () {
     fi
 
     if [[ -z "$arg" ]]; then
-        up=$(php daily.php -f update >&2; echo $?)
-        if [[ "$up" == "0" ]]; then
-            $DAILY_SCRIPT no-code-update
-            exit
-        elif [[ "$up" == "1" ]]; then
-            # Update to Master-Branch
-            old_ver=$(git show --pretty="%H" -s HEAD)
-            status_run 'Updating to latest codebase' 'git pull --quiet' 'update'
-            new_ver=$(git show --pretty="%H" -s HEAD)
-            if [ "$old_ver" != "$new_ver" ]; then
-                status_run "Updated from $old_ver to $new_ver" ''
-            fi
-        elif [[ "$up" == "3" ]]; then
-            # Update to last Tag
-            old_ver=$(git describe --exact-match --tags $(git log -n1 --pretty='%h'))
-            status_run 'Updating to latest release' 'git fetch --tags && git checkout $(git describe --tags $(git rev-list --tags --max-count=1))' 'update'
-            new_ver=$(git describe --exact-match --tags $(git log -n1 --pretty='%h'))
-            if [[ "$old_ver" != "$new_ver" ]]; then
-                status_run "Updated from $old_ver to $new_ver" ''
-            fi
-        fi
 
         cnf=$(echo $(grep '\[.distributed_poller.\]' config.php | egrep -v -e '^//' -e '^#' | cut -d = -f 2 | sed 's/;//g'))
         if ((${BASH_VERSINFO[0]} < 4)); then
@@ -167,7 +146,6 @@ main () {
             post-pull)
                 # List all tasks to do after pull in the order of execution
                 status_run 'Updating SQL-Schema' 'php includes/sql-schema/update.php'
-                status_run 'Updating submodules' "$DAILY_SCRIPT submodules"
                 status_run 'Cleaning up DB' "$DAILY_SCRIPT cleanup"
                 status_run 'Fetching notifications' "$DAILY_SCRIPT notifications"
                 status_run 'Caching PeeringDB data' "$DAILY_SCRIPT peeringdb"
