--- ./lib/Tinderbox/TinderboxDS.pm.orig	2008-08-07 07:27:49.000000000 +0300
+++ ./lib/Tinderbox/TinderboxDS.pm	2008-09-07 09:37:07.000000000 +0300
@@ -23,7 +23,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/Tinderbox/TinderboxDS.pm,v 1.88 2008/08/07 04:27:49 marcus Exp $
+# $MCom: portstools/tinderbox/lib/Tinderbox/TinderboxDS.pm,v 1.88.2.2 2008/09/05 21:07:14 marcus Exp $
 #
 
 package Tinderbox::TinderboxDS;
@@ -42,6 +42,7 @@
 use DBI;
 use Carp;
 use Digest::MD5 qw(md5_hex);
+use POSIX qw(strftime);
 use vars qw(
     $DB_DRIVER
     $DB_HOST
@@ -362,8 +363,12 @@
 sub reorgBuildPortsQueue {
         my $self = shift;
 
+        my $enq_time = time - 25200;
+        my $enq_sql = strftime("%Y-%m-%d %H:%M:%S", localtime($enq_time));
+
         my $rc = $self->_doQuery(
-                "DELETE FROM build_ports_queue WHERE enqueue_date<=NOW()-25200 AND status != 'ENQUEUED'"
+                "DELETE FROM build_ports_queue WHERE enqueue_date<=? AND status != 'ENQUEUED'",
+                [$enq_sql]
         );
 
         return $rc;
