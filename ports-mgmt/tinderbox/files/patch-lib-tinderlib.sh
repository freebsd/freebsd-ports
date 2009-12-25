--- lib/tinderlib.sh.orig	2009-11-27 18:32:31.000000000 +0100
+++ lib/tinderlib.sh	2009-12-25 21:07:17.000000000 +0100
@@ -23,7 +23,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.5 2009/03/14 23:57:13 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tinderlib.sh,v 1.55.2.6 2009/12/24 17:23:32 marcus Exp $
 #
 
 tinderLocJail () {
@@ -505,7 +505,6 @@
     jailBase=$(tinderLoc jail ${jail})
     eval "export __MAKE_CONF=${jailBase}/make.conf" >/dev/null 2>&1
     eval "export LOCALBASE=/nonexistentlocal" >/dev/null 2>&1
-    eval "export X11BASE=/nonexistentx" >/dev/null 2>&1
     eval "export PKG_DBDIR=/nonexistentdb" >/dev/null 2>&1
     if [ x"${OPTIONS_ENABLED}" != x"1" ]; then
         eval "export PORT_DBDIR=/nonexistentportdb" >/dev/null 2>&1
