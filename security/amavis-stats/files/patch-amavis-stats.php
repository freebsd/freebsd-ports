--- amavis-stats.php.orig      Sat Mar 27 17:25:27 2004
+++ amavis-stats.php   Sun Jun  6 01:21:35 2004
@@ -286,7 +286,7 @@
 function asLoadStats () {
     global $as_libdir, $virus, $pid, $psid, $iid, $bid,$nid,$nsid, $lastupdate, $maxi;

-    $as_libdir    = "/var/lib/amavis-stats";
+    $as_libdir    = "/usr/local/www/amavis-stats";
     $as_statefile = $as_libdir . "/amavis-stats.state";
     $as_namefile  = $as_libdir . "/amavis-stats.names";
     $as_seenfile  = $as_libdir . "/amavis-stats.seen";
