--- Makefile.PL.orig	2015-09-17 12:02:49 UTC
+++ Makefile.PL
@@ -69,12 +69,12 @@ if ( $^O eq 'linux' ) {
 }
 
 configure_requires 'DBIx::Class' => '0.082801';
-require DBIx::Class::Optional::Dependencies;
-
-my $deploy_deps = DBIx::Class::Optional::Dependencies->req_list_for('deploy');
-foreach my $k (keys %$deploy_deps) {
-    requires $k => $deploy_deps->{$k};
-}
+#require DBIx::Class::Optional::Dependencies;
+#
+#my $deploy_deps = DBIx::Class::Optional::Dependencies->req_list_for('deploy');
+#foreach my $k (keys %$deploy_deps) {
+#    requires $k => $deploy_deps->{$k};
+#}
 
 recommends 'Graph' => 0;
 recommends 'GraphViz' => 0;
