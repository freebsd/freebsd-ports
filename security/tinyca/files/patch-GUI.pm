--- lib/GUI.pm-orig	2014-07-20 22:28:16.000000000 +0200
+++ lib/GUI.pm	2014-07-20 22:33:27.000000000 +0200
@@ -992,7 +992,7 @@
    $piter = $store->append($root);
    $store->set($piter, 0 => $t);
 
-   for my $l qw(CN EMAIL O OU C ST L) {
+   for my $l (qw(CN EMAIL O OU C ST L)) {
       if(defined($parsed->{$l})) {
          if($l eq "OU") {
             foreach my $ou (@{$parsed->{'OU'}}) {
@@ -1017,7 +1017,7 @@
       $piter = $store->append($root);
       $store->set($piter, 0 => $t);
 
-      for my $l qw(CN EMAIL O OU C ST L) {
+      for my $l (qw(CN EMAIL O OU C ST L)) {
          if(defined($parsed->{'ISSUERDN'}->{$l})) {
             if($l eq "OU") {
                foreach my $ou (@{$parsed->{'ISSUERDN'}->{'OU'}}) {
@@ -1043,7 +1043,7 @@
       $piter = $store->append($root);
       $store->set($piter, 0 => $t);
 
-      for my $l qw(STATUS NOTBEFORE NOTAFTER) {
+      for my $l (qw(STATUS NOTBEFORE NOTAFTER)) {
          if(defined($parsed->{$l})) {
             $citer = $store->append($piter);
             $store->set($citer, 
@@ -1059,7 +1059,7 @@
    $store->set($piter, 0 => $t);
 
 
-   for my $l qw(STATUS SERIAL KEYSIZE PK_ALGORITHM SIG_ALGORITHM TYPE) {
+   for my $l (qw(STATUS SERIAL KEYSIZE PK_ALGORITHM SIG_ALGORITHM TYPE)) {
       if(defined($parsed->{$l})) {
          $citer = $store->append($piter);
          $store->set($citer, 
@@ -1074,7 +1074,7 @@
       $piter = $store->append($root);
       $store->set($piter, 0 => $t);
 
-      for my $l qw(FINGERPRINTMD5 FINGERPRINTSHA1) {
+      for my $l (qw(FINGERPRINTMD5 FINGERPRINTSHA1)) {
          if(defined($parsed->{$l})) {
             $citer = $store->append($piter);
             $store->set($citer, 
@@ -1263,7 +1263,7 @@
    # table for request data
    my $cc=0;
    my $ous = 1;
-   if(defined($opts->{'OU'})) {
+   if(defined($opts->{'OU'}) and ref($opts->{'OU'}) eq 'ARRAY') {
       $ous = @{$opts->{'OU'}} - 1;
    }
    $reqtable = Gtk2::Table->new(1, 13 + $ous, 0);
@@ -1311,7 +1311,7 @@
          _("Organization Name (eg. company):"),
          \$opts->{'O'}, $reqtable, 10, 1);
 
-   if(defined($opts->{'OU'})) {
+   if(defined($opts->{'OU'}) and ref($opts->{'OU'}) eq 'ARRAY') {
       foreach my $ou (@{$opts->{'OU'}}) {
          $entry = GUI::HELPERS::entry_to_table(
                _("Organizational Unit Name (eg. section):"),
@@ -2545,7 +2545,7 @@
       return;
     }
    
-   $aboutdialog->set_name("TinyCA2");
+   $aboutdialog->set_program_name("TinyCA2");
    $aboutdialog->set_version($main->{'version'});
    $aboutdialog->set_copyright("2002-2006 Stephan Martin");
    $aboutdialog->set_license("GNU Public License (GPL)");
@@ -2558,6 +2558,8 @@
          _("French: Thibault Le Meur <Thibault.Lemeur\@supelec.fr>"));
 
    $aboutdialog->show_all();
+   $aboutdialog->run;
+   $aboutdialog->destroy;
 
    return;
 }
@@ -2658,7 +2660,7 @@
 
    my ($box, $button_ok, $button_cancel, $t);
 
-   $t = _("The Certificate will be longer valid than your CA!");
+   $t = _("The certificate will be valid longer than its CA!");
    $t .= "\n";
    $t .= _("This may cause problems with some software!!");
 
@@ -3118,9 +3120,9 @@
    for $value (keys %values) {
       my $display_name = $values{$value};
       my $key = Gtk2::RadioButton->new($previous_key, $display_name);
-      $key->set_active(1) if(defined($$var) && $$var eq $value);
       $key->signal_connect('toggled' =>
 			   sub{GUI::CALLBACK::toggle_to_var($key, $var, $value)});
+      $key->set_active(1) if(defined($$var) && $$var eq $value);
       $radiobox->add($key);
       $previous_key = $key;
    }
