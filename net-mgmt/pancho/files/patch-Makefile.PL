--- Makefile.PL.orig	Mon Jan  6 22:22:54 2003
+++ Makefile.PL	Mon Jan  6 22:26:56 2003
@@ -52,24 +52,26 @@
    print "Configuring Pancho.\n";
 }
 
-my @missing_mods;
-my @upgrade_mods;
-# check for modules
-foreach my $mod (keys %$DEPS) {
-   my $eval = "require $mod";
-   eval $eval;
-   if ($@) {
-      push (@missing_mods, $mod);
-   }
-   elsif ($mod->VERSION < $DEPS->{$mod}) {
-      push (@upgrade_mods, $mod);
-   }
-}
-
-if ($NOASK) {
-   installMods(\@missing_mods, 'missing');
-   installMods(\@upgrade_mods, 'upgrade');
-}
+# FreeBSD port : inhibits dependancy checks here
+# and use port's one
+#my @missing_mods;
+#my @upgrade_mods;
+## check for modules
+#foreach my $mod (keys %$DEPS) {
+#   my $eval = "require $mod";
+#   eval $eval;
+#   if ($@) {
+#      push (@missing_mods, $mod);
+#   }
+#   elsif ($mod->VERSION < $DEPS->{$mod}) {
+#      push (@upgrade_mods, $mod);
+#   }
+#}
+#
+#if ($NOASK) {
+#   installMods(\@missing_mods, 'missing');
+#   installMods(\@upgrade_mods, 'upgrade');
+#}
 
 if ($ALONE) {
    system("perl build_pancho.PL ALONE");
@@ -109,25 +111,25 @@
 }
 
 # override install in order to create conf dir and copy config
-sub MY::install {
-    package MY;
-    my $inherited = shift->SUPER::install(@_);
-
-    # commands to actually create and copy the files
-    my $mkdir = "\t\$(MKPATH) \$(SYS_CONFDIR)\n";
-
-    my $copy  = "\t\@ if [ -f \"\$(SYS_CONFDIR)/pancho.conf\" ]; then \\\n"; 
-    $copy    .= "\t\techo;\\\n\t\techo Not copying configuration file.  One already exists.;\\\n\t\techo;\\\n";
-    $copy    .= "\telse \\\n";
-    $copy    .= "\t\t\$(CP) pancho.conf \$(SYS_CONFDIR);\\\n";
-    $copy    .= "\t\techo;\\\n\t\techo Configuration file has been installed into \$(SYS_CONFDIR);\\\n\t\techo;\\\n";
-    $copy    .= "\tfi\n";
-
-    # add copy of config file into SYS_CONFDIR
-    $inherited =~ s|(^install\s*::.*)|$1\n$mkdir$copy|m;
-    
-    $inherited;
-}
+#sub MY::install {
+#    package MY;
+#    my $inherited = shift->SUPER::install(@_);
+#
+#    # commands to actually create and copy the files
+#    my $mkdir = "\t\$(MKPATH) \$(SYS_CONFDIR)\n";
+#
+#    my $copy  = "\t\@ if [ -f \"\$(SYS_CONFDIR)/pancho.conf\" ]; then \\\n"; 
+#    $copy    .= "\t\techo;\\\n\t\techo Not copying configuration file.  One already exists.;\\\n\t\techo;\\\n";
+#    $copy    .= "\telse \\\n";
+#    $copy    .= "\t\t\$(CP) pancho.conf \$(SYS_CONFDIR);\\\n";
+#    $copy    .= "\t\techo;\\\n\t\techo Configuration file has been installed into \$(SYS_CONFDIR);\\\n\t\techo;\\\n";
+#    $copy    .= "\tfi\n";
+#
+#    # add copy of config file into SYS_CONFDIR
+#    $inherited =~ s|(^install\s*::.*)|$1\n$mkdir$copy|m;
+#    
+#    $inherited;
+#}
 
 # override realclean to remove pancho and pancho.conf
 sub MY::realclean {
