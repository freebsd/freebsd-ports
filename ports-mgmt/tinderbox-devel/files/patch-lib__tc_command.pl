Index: portstools/tinderbox/lib/tc_command.pl
diff -u portstools/tinderbox/lib/tc_command.pl:1.150.2.12 portstools/tinderbox/lib/tc_command.pl:1.150.2.14
--- portstools/tinderbox/lib/tc_command.pl:1.150.2.12	Wed Feb 11 03:50:34 2009
+++ portstools/tinderbox/lib/tc_command.pl	Sat Mar 28 13:28:23 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.12 2009/02/11 08:50:34 beat Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.14 2009/03/28 17:28:23 marcus Exp $
 #
 
 my $pb;
@@ -46,6 +46,7 @@
 use Tinderbox::MakeCache;
 use Getopt::Std;
 use Text::Wrap;
+use Cwd 'abs_path';
 use vars qw(
     %COMMANDS
     $TINDERBOX_HOST
@@ -3090,7 +3091,7 @@
                         }
 
                         $rc =
-                            $ds->updatePortLastBuiltStatus($port, $dest,
+                            $ds->updatePortLastStatus($port, $dest,
                                 $ds->getPortLastBuiltStatus($port, $src));
                         if (!$rc) {
                                 warn
@@ -3217,6 +3218,10 @@
         my $portdir = $ENV{'PORTSDIR'} . "/" . $port;
         return if (!-d $portdir);
 
+        # Canonicalize the port directory.
+        $port = abs_path($portdir);
+        $port =~ s|$ENV{'PORTSDIR'}/||;
+
         if (defined($deps)) {
                 my @list;
                 push @list, $cache->BuildDependsList($port);
