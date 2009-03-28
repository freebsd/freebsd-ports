Index: portstools/tinderbox/lib/tc_command.pl
diff -u portstools/tinderbox/lib/tc_command.pl:1.150.2.12 portstools/tinderbox/lib/tc_command.pl:1.150.2.13
--- ./lib/tc_command.pl:1.150.2.12	Wed Feb 11 03:50:34 2009
+++ ./lib/tc_command.pl	Fri Mar 27 00:16:27 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.12 2009/02/11 08:50:34 beat Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.13 2009/03/27 04:16:27 marcus Exp $
 #
 
 my $pb;
@@ -3090,7 +3090,7 @@
                         }
 
                         $rc =
-                            $ds->updatePortLastBuiltStatus($port, $dest,
+                            $ds->updatePortLastStatus($port, $dest,
                                 $ds->getPortLastBuiltStatus($port, $src));
                         if (!$rc) {
                                 warn
