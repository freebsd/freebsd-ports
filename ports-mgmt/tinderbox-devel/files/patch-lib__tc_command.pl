Index: portstools/tinderbox/lib/tc_command.pl
diff -u portstools/tinderbox/lib/tc_command.pl:1.150.2.12 portstools/tinderbox/lib/tc_command.pl:1.150.2.16
--- portstools/tinderbox/lib/tc_command.pl:1.150.2.12	Wed Feb 11 03:50:34 2009
+++ portstools/tinderbox/lib/tc_command.pl	Sat Apr 25 15:42:13 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.12 2009/02/11 08:50:34 beat Exp $
+# $MCom: portstools/tinderbox/lib/tc_command.pl,v 1.150.2.16 2009/04/25 19:42:13 marcus Exp $
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
@@ -178,7 +179,8 @@
         },
         "addJail" => {
                 func => \&addJail,
-                help => "Add a jail to the datastore",
+                help =>
+                    "Add a jail to the datastore (do NOT call this directly; use createJail instead)",
                 usage =>
                     "-j <jail name> -u CSUP|CVSUP|USER|NONE -t <jail tag> [-d <jail description>] [-m <src mount source>] [-a <arch>]",
                 optstr => 'm:j:t:u:d:a:',
@@ -678,6 +680,15 @@
         cleanup($ds, 1, undef);
 }
 
+sub trimstr {
+        my $str = shift;
+
+        $str =~ s/^\s+//;
+        $str =~ s/\s+$//;
+
+        return $str;
+}
+
 #---------------------------------------------------------------------------
 # Main dispatching function
 #---------------------------------------------------------------------------
@@ -1302,8 +1313,11 @@
         $build->setName($name);
         $build->setJailId($jCls->getId());
         $build->setPortsTreeId($pCls->getId());
-        $build->setDescription($opts->{'d'}) if ($opts->{'d'});
+        if ($opts->{'d'}) {
+                my $descr = trimstr($opts->{'d'});
 
+                $build->setDescription($descr);
+        }
         my $rc = $ds->addBuild($build);
 
         if (!$rc) {
@@ -1341,8 +1355,12 @@
         $jail->setArch($arch);
         $jail->setTag($tag);
         $jail->setUpdateCmd($ucmd);
-        $jail->setDescription($opts->{'d'}) if ($opts->{'d'});
-        $jail->setSrcMount($opts->{'m'})    if ($opts->{'m'});
+        if ($opts->{'d'}) {
+                my $descr = trimstr($opts->{'d'});
+
+                $jail->setDescription($descr);
+        }
+        $jail->setSrcMount($opts->{'m'}) if ($opts->{'m'});
 
         my $rc = $ds->addJail($jail);
 
@@ -1372,9 +1390,13 @@
 
         $portstree->setName($name);
         $portstree->setUpdateCmd($ucmd);
-        $portstree->setDescription($opts->{'d'}) if ($opts->{'d'});
-        $portstree->setPortsMount($opts->{'m'})  if ($opts->{'m'});
-        $portstree->setCVSwebURL($opts->{'w'})   if ($opts->{'w'});
+        if ($opts->{'d'}) {
+                my $descr = trimstr($opts->{'d'});
+
+                $portstree->setDescription($descr);
+        }
+        $portstree->setPortsMount($opts->{'m'}) if ($opts->{'m'});
+        $portstree->setCVSwebURL($opts->{'w'})  if ($opts->{'w'});
         $portstree->setLastBuilt($ds->getTime());
 
         my $rc = $ds->addPortsTree($portstree);
@@ -1487,7 +1509,15 @@
                 }
         }
 
-        $ds->addBuildPortsQueueEntry($build, $opts->{'d'}, $priority, $user_id);
+        my $rc = $ds->addBuildPortsQueueEntry($build, $opts->{'d'}, $priority, $user_id);
+	if (!$rc) {
+                cleanup($ds, 1,
+                              "Failed to add port "
+                            . $opts->{'d'}
+                            . " to the datastore: "
+                            . $ds->getError()
+                            . ".\n");
+        }
 }
 
 sub addPortFailPattern {
@@ -3090,7 +3120,7 @@
                         }
 
                         $rc =
-                            $ds->updatePortLastBuiltStatus($port, $dest,
+                            $ds->updatePortLastStatus($port, $dest,
                                 $ds->getPortLastBuiltStatus($port, $src));
                         if (!$rc) {
                                 warn
@@ -3217,6 +3247,10 @@
         my $portdir = $ENV{'PORTSDIR'} . "/" . $port;
         return if (!-d $portdir);
 
+        # Canonicalize the port directory.
+        $port = abs_path($portdir);
+        $port =~ s|$ENV{'PORTSDIR'}/||;
+
         if (defined($deps)) {
                 my @list;
                 push @list, $cache->BuildDependsList($port);
