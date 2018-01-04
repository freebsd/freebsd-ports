--- etc/ngshared.pm.orig	2018-01-04 17:27:27 UTC
+++ etc/ngshared.pm
@@ -231,7 +231,7 @@ sub init {
     my ($cgi, $params) = getparams();
     getdebug($app, $params->{host}, $params->{service});
 
-    $errmsg = readi18nfile($cgi->param('language'));
+    $errmsg = readi18nfile($cgi->multi_param('language'));
     if ($errmsg ne q()) {
         debug(DBWRN, $errmsg);
     }
@@ -381,7 +381,7 @@ sub getparams {
                 my @rval = $cgi->param($ii);
                 $rval{$ii} = \@rval;
             } elsif ($ii eq 'db' || $ii eq 'label') {
-                $rval{$ii} = [$cgi->param($ii),];
+                $rval{$ii} = [$cgi->multi_param($ii),];
             } else {
                 $rval{$ii} = $cgi->param($ii);
             }
