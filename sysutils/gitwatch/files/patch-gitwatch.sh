--- gitwatch.sh.orig	2020-11-15 05:05:21 UTC
+++ gitwatch.sh
@@ -43,6 +43,9 @@ COMMITMSG="Scripted auto-commit on change (%d) by gitw
 LISTCHANGES=-1
 LISTCHANGES_COLOR="--color=always"
 GIT_DIR=""
+GIT="$(which git)"
+INW="$(which inotifywait)";
+EVENTS="${EVENTS:-close_write,move,move_self,delete,create,modify}"
 
 # Print a message about how to use this script
 shelp () {
@@ -97,12 +100,6 @@ shelp () {
     echo "It is therefore recommended to terminate the script before changing the repo's"
     echo "config and restarting it afterwards."
     echo ""
-    echo "By default, gitwatch tries to use the binaries \"git\" and \"inotifywait\","
-    echo "expecting to find them in the PATH (it uses 'which' to check this and  will"
-    echo "abort with an error if they cannot be found). If you want to use binaries"
-    echo "that are named differently and/or located outside of your PATH, you can define"
-    echo "replacements in the environment variables GW_GIT_BIN and GW_INW_BIN for git"
-    echo "and inotifywait, respectively."
 }
 
 # print all arguments to stderr
@@ -118,11 +115,6 @@ cleanup () {
     exit 0
 }
 
-# Tests for the availability of a command
-is_command () {
-	hash "$1" 2>/dev/null
-}
-
 ###############################################################################
 
 while getopts b:d:h:g:L:l:m:p:r:s:e: option # Process command line options
@@ -149,65 +141,20 @@ if [ $# -ne 1 ]; then # If no command line arguments a
     exit # and exit
 fi
 
-# if custom bin names are given for git or inotifywait, use those; otherwise fall back to "git" and "inotifywait"
-if [ -z "$GW_GIT_BIN" ]; then GIT="git"; else GIT="$GW_GIT_BIN"; fi
-
-if [ -z "$GW_INW_BIN" ]; then
-    # if Mac, use fswatch
-    if [ "$(uname)" != "Darwin" ]; then
-        INW="inotifywait";
-        EVENTS="${EVENTS:-close_write,move,move_self,delete,create,modify}"
-    else
-        INW="fswatch";
-        # default events specified via a mask, see
-        # https://emcrisostomo.github.io/fswatch/doc/1.14.0/fswatch.html/Invoking-fswatch.html#Numeric-Event-Flags
-        # default of 414 = MovedTo + MovedFrom + Renamed + Removed + Updated + Created
-        #                = 256 + 128+ 16 + 8 + 4 + 2
-        EVENTS="${EVENTS:---event=414}"
-    fi;
-else
-    INW="$GW_INW_BIN";
-fi
-
-# Check availability of selected binaries and die if not met
-for cmd in "$GIT" "$INW"; do
-	is_command "$cmd" || { stderr "Error: Required command '$cmd' not found." ; exit 1; }
-done
-unset cmd
-
 ###############################################################################
 
 SLEEP_PID="" # pid of timeout subprocess
 
 trap "cleanup" EXIT # make sure the timeout is killed when exiting script
 
-
 # Expand the path to the target to absolute path
-if [ "$(uname)" != "Darwin" ]; then
-    IN=$(readlink -f "$1")
-else
-    if is_command "greadlink"; then
-      IN=$(greadlink -f "$1")
-    else
-      IN=$(readlink -f "$1")
-      if [ $? -eq 1 ]; then
-        echo "Seems like your readlink doesn't support '-f'. Running without. Please 'brew install coreutils'."
-        IN=$(readlink "$1")
-      fi
-    fi;
-fi;
+IN=$(readlink -f "$1")
 
-
 if [ -d "$1" ]; then # if the target is a directory
 
     TARGETDIR=$(sed -e "s/\/*$//" <<<"$IN") # dir to CD into before using git commands: trim trailing slash, if any
     # construct inotifywait-commandline
-    if [ "$(uname)" != "Darwin" ]; then
-        INW_ARGS=("-qmr" "-e" "$EVENTS" "--exclude" "'(\.git/|\.git$)'" "\"$TARGETDIR\"")
-    else
-        # still need to fix EVENTS since it wants them listed one-by-one
-        INW_ARGS=("--recursive" "$EVENTS" "--exclude" "'(\.git/|\.git$)'" "\"$TARGETDIR\"")
-    fi;
+    INW_ARGS=("-qmr" "-e" "$EVENTS" "--exclude" "'(\.git/|\.git$)'" "\"$TARGETDIR\"")
     GIT_ADD_ARGS="--all ." # add "." (CWD) recursively to index
     GIT_COMMIT_ARGS="" # add -a switch to "commit" call just to be sure
 
@@ -215,11 +162,7 @@ elif [ -f "$1" ]; then # if the target is a single fil
 
     TARGETDIR=$(dirname "$IN") # dir to CD into before using git commands: extract from file name
     # construct inotifywait-commandline
-    if [ "$(uname)" != "Darwin" ]; then
-        INW_ARGS=("-qm" "-e" "$EVENTS" "$IN")
-    else
-        INW_ARGS=("$EVENTS" "$IN")
-    fi
+    INW_ARGS=("-qm" "-e" "$EVENTS" "$IN")
 
     GIT_ADD_ARGS="$IN" # add only the selected file to index
     GIT_COMMIT_ARGS="" # no need to add anything more to "commit" call
@@ -260,6 +203,8 @@ if [ -n "$REMOTE" ]; then # are we pushing to a remote
             PUSH_CMD="$GIT push $REMOTE $BRANCH"
         fi
     fi
+elif [ -n $($GIT config --get remote.origin.url) ] ; then
+	PUSH_CMD="$GIT push"
 else
     PUSH_CMD="" # if not remote is selected, make sure push command is empty
 fi
