--- lib/Wiki.pm.orig	Sun Aug 22 13:49:50 2004
+++ lib/Wiki.pm	Mon Nov  8 12:56:01 2004
@@ -41,7 +41,7 @@
 	# 設定を読み込み
 	my $setupfile = shift || 'setup.dat';
 	$self->{"config"} = &Util::load_config_hash(undef,$setupfile);
-	die "setup file ${setupfile} not found" if scalar(%{$self->{"config"}}) == 0;
+	die "setup file ${setupfile} not found" if (keys %{$self->{"config"}} == 0);
 	$self->{"config"}->{"plugin_dir"} = "."         unless exists($self->{"config"}->{"plugin_dir"});
 	$self->{"config"}->{"frontpage"}  = "FrontPage" unless exists($self->{"config"}->{"frontpage"});
 	unshift(@INC, $self->{"config"}->{"plugin_dir"});
@@ -1444,7 +1444,7 @@
 sub farm_is_enable {
 	my $self = shift;
 	my $farm_config = &Util::load_config_hash($self,$self->config('farmconf_file'));
-	if($farm_config->{usefarm}==1){
+	if(defined $farm_config->{usefarm} and $farm_config->{usefarm}==1){
 		return 1;
 	} else {
 		return 0;
