--- lib/Mail/SpamAssassin/BayesStore/DBM.pm	(revision 903517)
+++ lib/Mail/SpamAssassin/BayesStore/DBM.pm	(working copy)
@@ -1438,6 +1438,9 @@
     # bayes directory
     my $main = $self->{bayes}->{main};
     my $path = $main->sed_path($main->{conf}->{bayes_path});
+
+    # prevent dirname() from tainting the result, it assumes $1 is not tainted
+    local($1,$2,$3);  # Bug 6310
     my $dir = dirname($path);
 
     # make temporary copy since old dbm and new dbm may have same name

