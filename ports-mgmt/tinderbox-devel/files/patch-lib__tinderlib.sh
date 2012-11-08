--- ./lib/tinderlib.sh.orig	2012-11-07 10:17:43.000000000 +0100
+++ ./lib/tinderlib.sh	2012-11-07 10:18:27.000000000 +0100
@@ -23,7 +23,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.9 2012/04/04 10:38:41 beat Exp $
+# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.10 2012/05/21 01:19:28 marcus Exp $
 #
 
 tinderLocJail () {
@@ -225,6 +225,7 @@
 requestMount () {
     # set up defaults
     _type=""
+    _options=""
     _srcloc=""
     _dstloc=""
     _nullfs=0
@@ -632,7 +633,7 @@
 
     for r in ${reqs} ; do
         if [ "${use_pkgng}" = "yes" ]; then 
-            if [ -z $(pkg info -qgO ${r}) ]; then
+            if [ -z $(pkg info -q ${r}) ]; then
                 missing="${missing} ${r}"
                 error=1
             fi
