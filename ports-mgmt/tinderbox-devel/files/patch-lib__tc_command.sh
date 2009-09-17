--- portstools/tinderbox/lib/tc_command.sh.orig	2009-02-24 20:36:38.000000000 +0100
+++ portstools/tinderbox/lib/tc_command.sh	2009-09-17 19:59:26.000000000 +0200
@@ -24,10 +24,10 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.14 2009/02/15 17:22:28 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.18 2009/05/10 18:02:34 marcus Exp $
 #
 
-export _defaultUpdateHost="cvsup12.FreeBSD.org"
+export _defaultUpdateHost="cvsup17.FreeBSD.org"
 export _defaultUpdateType="CSUP"
 
 #---------------------------------------------------------------------------
@@ -160,16 +160,11 @@
 
     if [ ! -x ${dir}/update.sh ]; then
 	echo "updateTree: ${what} ${name}: missing update script!"
-	exit 1
+	return 1
     fi
 
     echo "${name}: updating ${what} with ${updateCmd}"
 
-    if ! requestMount -t ${what} ${flag} ${name}; then
-	echo "updateTree: ${what} ${name}: mount failed"
-	exit 1
-    fi
-
     if [ "${updateCmd}" = "USER" ]; then
         eval ${dir}/update.sh ${name} > ${dir}/update.log 2>&1
     else
@@ -178,11 +173,8 @@
     if [ $? -ne 0 ]; then
 	echo "updateTree: ${what} ${name}: update failed"
 	echo "    see ${dir}/update.log for more details"
-	cleanupMounts -t ${what} ${flag} ${name}
-	exit 1
+	return 1
     fi
-
-    cleanupMounts -t ${what} ${flag} ${name}
 }
 
 #---------------------------------------------------------------------------
@@ -247,8 +239,9 @@
     do_load=0
     db_driver=$(getDbDriver)
     dbinfo=$(getDbInfo ${db_driver})
+    db_res=$?
     genschema=$(tinderLoc scripts sql/genschema)
-    if [ $? = 0 ]; then
+    if [ ${db_res} = 0 ]; then
         db_admin_host_name=${dbinfo%:*}
 	db_admin_host=${db_admin_host_name%:*}
         db_name=${db_admin_host_name##*:}
@@ -575,9 +568,20 @@
 	echo "updateJail: hook preJailUpdate failed. Terminating."
 	return 1
     fi
+    if ! requestMount -t jail -j ${jailName}; then
+	echo "updateJail: ${jailName}: mount failed"
+	exit 1
+    fi
     updateTree jail ${jailName} -j $(tinderLoc jail ${jailName})
     rc=$?
     execute_hook "postJailUpdate" "JAIL=${jailName} RC=${rc} PB=${pb}"
+
+    cleanupMounts -t jail -j ${jailName}
+
+    if [ ${rc} -ne 0 ]; then
+	exit ${rc}
+    fi
+
     return 0
 }
 
@@ -925,10 +929,25 @@
 	echo "${portsTreeName}: hook prePortsTreeUpdate failed. Terminating."
 	return 1
     fi
+    if ! requestMount -t portstree -p ${portsTreeName}; then
+	echo "updatePortsTree: ${portsTreeName}: mount failed"
+	exit 1
+    fi
     updateTree portstree ${portsTreeName} \
 	       -p $(tinderLoc portstree ${portsTreeName})
     rc=$?
     execute_hook "postPortsTreeUpdate" "PORTSTREE=${portsTreeName} \"UPDATE_CMD=${updateCmd}\" PB=${pb} RC=${rc}"
+    if [ $? -ne 0 ]; then
+	echo "updatePortsTree: ${portsTreeName}: hook postPortsTreeUpdate failed. Terminating."
+        cleanupMounts -t portstree -p ${portsTreeName}
+	return 1
+    fi
+
+    cleanupMounts -t portstree -p ${portsTreeName}
+
+    if [ ${rc} -ne 0 ]; then
+	exit ${rc}
+    fi
 
     # Update the last-built time
     ${tc} updatePortsTreeLastBuilt -p ${portsTreeName}
@@ -1649,7 +1668,7 @@
     # Set up the chrooted environment
     osmajor=$(echo ${jail} | sed -E -e 's|(^[[:digit:]]+).*$|\1|')
     case ${osmajor} in
-    6|7|8)	tinderbuild_setup;;
+    6|7|8|9)	tinderbuild_setup;;
     *)		echo "tinderbuild: unhandled OS version: ${osmajor}"
 		tinderbuild_cleanup 1
 		;;
