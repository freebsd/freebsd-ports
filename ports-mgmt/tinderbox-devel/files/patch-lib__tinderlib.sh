Index: portstools/tinderbox/lib/tinderlib.sh
diff -u portstools/tinderbox/lib/tinderlib.sh:1.55.2.4 portstools/tinderbox/lib/tinderlib.sh:1.55.2.5
--- portstools/tinderbox/lib/tinderlib.sh:1.55.2.4	Mon Nov 10 02:03:02 2008
+++ portstools/tinderbox/lib/tinderlib.sh	Sat Mar 14 19:57:13 2009
@@ -23,7 +23,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.4 2008/11/10 07:03:02 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.5 2009/03/14 23:57:13 marcus Exp $
 #
 
 tinderLocJail () {
@@ -131,7 +131,14 @@
 
     pids="XXX"
     while [ ! -z "${pids}" ]; do
-	pids=$(fstat -f "${dir}" | tail +2 | awk '{print $3}' | sort -u)
+	# Lsof is more reliable when it comes to nullfs, so prefer it if
+	# found.
+	lsof=$(which lsof 2>/dev/null)
+	if [ -n "${lsof}" ]; then
+	    pids=$(${lsof} | fgrep "${dir}" | awk '{print $2}' | sort -u)
+	else
+	    pids=$(fstat -f "${dir}" | tail +2 | awk '{print $3}' | sort -u)
+	fi
 
 	if [ ! -z "${pids}" ]; then
 	    echo "Killing off pids in ${dir}"
