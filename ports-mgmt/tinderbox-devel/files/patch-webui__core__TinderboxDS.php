--- ./webui/core/TinderboxDS.php.orig	2009-02-24 21:36:38.000000000 +0200
+++ ./webui/core/TinderboxDS.php	2009-03-25 06:14:12.244205304 +0200
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/webui/core/TinderboxDS.php,v 1.36.2.6 2009/02/01 19:43:27 beat Exp $
+# $MCom: portstools/tinderbox/webui/core/TinderboxDS.php,v 1.36.2.7 2009/03/13 07:57:24 beat Exp $
 #
 
     require_once 'DB.php';
@@ -388,7 +388,7 @@
 	    }
             $query = "SELECT p.port_id,
                              p.port_directory,
-                             TRIM(TRAILING '@FreeBSD.org' FROM p.port_maintainer) as port_maintainer,
+                             REPLACE(p.port_maintainer, '@FreeBSD.org', '') as port_maintainer,
                              p.port_name,
                              p.port_comment,
                              bp.last_built,
