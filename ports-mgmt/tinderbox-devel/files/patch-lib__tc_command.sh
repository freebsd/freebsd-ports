Index: portstools/tinderbox/lib/tc_command.sh
diff -u portstools/tinderbox/lib/tc_command.sh:1.101.2.14 portstools/tinderbox/lib/tc_command.sh:1.101.2.15
--- ./lib/tc_command.sh:1.101.2.14	Sun Feb 15 12:22:28 2009
+++ ./lib/tc_command.sh	Fri Mar 27 23:52:57 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.14 2009/02/15 17:22:28 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.15 2009/03/28 03:52:57 marcus Exp $
 #
 
 export _defaultUpdateHost="cvsup12.FreeBSD.org"
@@ -247,8 +247,9 @@
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
