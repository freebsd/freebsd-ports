--- install.pl	2007-10-24 00:32:29.000000000 +0000
+++ install.pl	2008-06-13 02:52:36.000000000 +0000
@@ -38,8 +38,8 @@
 
 #========================== config ===========================
 my $INIT_DIR    = '/etc/init.d';
-my $USRBIN_DIR  = '/usr/bin';
-my $URRSBIN_DIR = '/usr/sbin';
+my $USRBIN_DIR  = '%%PREFIX%%/bin';
+my $URRSBIN_DIR = '%%PREFIX%%/sbin';
 
 my $RUNLEVEL;    ### This should only be set if install.pl
                  ### cannot determine the correct runlevel
@@ -302,7 +302,7 @@
             &stop_fwknop();
         }
 
-        for my $dir qw| /usr/lib /var/run /var/log /var/lib | {
+        for my $dir qw| %%PREFIX%%/lib /usr/lib /var/run /var/log /var/lib | {
             unless (-d $dir) {
                 mkdir $dir or die "[*] Could not mkdir $dir: $!";
             }
@@ -463,7 +463,7 @@
             "$USRBIN_DIR/fwknop.tmp: $!";
         for my $line (@lines) {
             ### change the lib dir to new homedir path
-            if ($line =~ m|^\s*use\s+lib\s+\'/usr/lib/fwknop\';|) {
+            if ($line =~ m|^\s*use\s+lib\s+\'%%PREFIX%%/lib/fwknop\';|) {
                 print P "use lib '", $config{'FWKNOP_MOD_DIR'}, "';\n";
             } else {
                 print P $line;
@@ -725,8 +725,8 @@
     unless (-d $INIT_DIR) {
         if (-d '/etc/rc.d/init.d') {
             $INIT_DIR = '/etc/rc.d/init.d';
-        } elsif (-d '/etc/rc.d') {
-            $INIT_DIR = '/etc/rc.d';
+        } elsif (-d '%%PREFIX%%/etc/rc.d') {
+            $INIT_DIR = '%%PREFIX%%/etc/rc.d';
         } elsif (-d '/etc/init.d') {
             $INIT_DIR = '/etc/init.d';
         } else {
@@ -1010,7 +1010,7 @@
 
     ### default location to put man pages, but check with
     ### /etc/man.config
-    my $mpath = '/usr/share/man/man8';
+    my $mpath = '%%PREFIX%%/man/man8';
     if (-e '/etc/man.config') {
         ### prefer to install $manpage in /usr/local/man/man8 if
         ### this directory is configured in /etc/man.config
@@ -1202,7 +1202,7 @@
             print "[+] Module $mod_name is already installed in the ",
                 "system perl tree, skipping.\n";
         } else {
-            ### install the module in the /usr/lib/fwknop directory because
+            ### install the module in the %%PREFIX%%/lib/fwknop directory because
             ### it is not already installed.
             $install_module = 1;
         }
