--- sayaka.sh.orig	2015-07-26 15:58:13.000000000 +0900
+++ sayaka.sh	2015-07-28 14:15:42.646976000 +0900
@@ -27,11 +27,29 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 
-SAYAKA_HOME=${HOME}/.sayaka
+: ${SAYAKA_HOME:=${HOME}/.sayaka}
 #SAYAKA_HOME=.
 
+BINDIR=@@BINDIR@@
+DATADIR=@@DATADIR@@
+
+die() {
+	echo "$@"
+	exit 1
+}
+
+checklinks() {
+	for f in ${BINDIR}/cellsize ${DATADIR}/*.php ${DATADIR}/*.png; do
+		[ -L ${f##*/} ] || ln -s $f .
+	done
+}
+
+[ -d $SAYAKA_HOME ] || mkdir $SAYAKA_HOME || die "Can't create ${SAYAKA_HOME}."
+
 cd $SAYAKA_HOME
 
+checklinks
+
 cmd=$1
 [ $# -ne 0 ] && shift
 case $cmd in
