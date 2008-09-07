--- ./lib/tc_command.pl.orig	2008-08-15 20:23:07.000000000 +0300
+++ ./lib/tc_command.pl	2008-09-07 09:37:07.000000000 +0300
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150 2008/08/15 17:23:07 marcus Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.1 2008/09/05 21:52:24 marcus Exp $
 #
 
 my $pb;
@@ -1668,7 +1668,7 @@
                             . "\n");
         } else {
                 cleanup($ds, 1,
-                        "There is no BuildPortsQueue configured in the datastore.\n"
+                        "There are no more queued ports for this host in the datastore.\n"
                 );
         }
 }
