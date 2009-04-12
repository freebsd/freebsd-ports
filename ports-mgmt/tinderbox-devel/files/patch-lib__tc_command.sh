Index: portstools/tinderbox/lib/tc_command.sh
diff -u portstools/tinderbox/lib/tc_command.sh:1.101.2.14 portstools/tinderbox/lib/tc_command.sh:1.101.2.16
--- portstools/tinderbox/lib/tc_command.sh:1.101.2.14	Sun Feb 15 12:22:28 2009
+++ portstools/tinderbox/lib/tc_command.sh	Sat Mar 28 13:24:33 2009
@@ -24,10 +24,10 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.14 2009/02/15 17:22:28 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.sh,v 1.101.2.16 2009/03/28 17:24:33 marcus Exp $
 #
 
-export _defaultUpdateHost="cvsup12.FreeBSD.org"
+export _defaultUpdateHost="cvsup17.FreeBSD.org"
 export _defaultUpdateType="CSUP"
 
 #---------------------------------------------------------------------------
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
