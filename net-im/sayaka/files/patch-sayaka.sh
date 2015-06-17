--- sayaka.sh.orig	2015-06-14 09:43:42 UTC
+++ sayaka.sh
@@ -27,9 +27,26 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 
-SAYAKA_HOME=${HOME}/.sayaka
+: ${SAYAKA_HOME:=${HOME}/.sayaka}
 #SAYAKA_HOME=.
 
+DATADIR=@@DATADIR@@
+
+die() {
+	echo "$@"
+	exit 1
+}
+
+mklinks() {
+	mkdir $SAYAKA_HOME || die "Can't create ${SAYAKA_HOME}."
+	cd $SAYAKA_HOME
+	for f in ${DATADIR}/*.php ${DATADIR}/*.png; do
+		ln -s $f .
+	done
+}
+
+[ -d $SAYAKA_HOME ] || mklinks
+
 cd $SAYAKA_HOME
 
 cmd=$1
