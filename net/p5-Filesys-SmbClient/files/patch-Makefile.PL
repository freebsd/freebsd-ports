--- Makefile.PL.orig	Sun Aug 10 11:25:48 2003
+++ Makefile.PL	Sun Aug 10 11:29:22 2003
@@ -5,36 +5,8 @@
 # special flag for AIX
 ($^O =~ m/AIX/i) ? ($ccfl = '-qcpluscmt') : ($ccfl = '');
 
-# path libsmbclient.h
-my $include = try_to_find("libsmbclient.h");
-$include = prompt("Where can I find libsmbclient.h ?", $include);
-warn_user("$include/libsmbclient.h") if (!-r "$include/libsmbclient.h");
-
-# path libsmbclient.so
-my $lib = try_to_find("libsmbclient.so");
-$lib = prompt("Where can I find libsmbclient.so ?",$lib);
-warn_user("libsmbclient.so") if (!-r "$lib/libsmbclient.so");
-
-# tests demande ?
-my $ans = 
-  prompt("Do you want make tests ?(you will be prompted for server / \n".
-	   "worgroup / share / user / password to make read write access.",
-	   "yes");
-if ($ans =~ /^y(es)?$/i) 
-  {
-    my $server = prompt("Server ?","localhost");
-    my $share = prompt("Share ?","homes");
-    my $workgroup = prompt("Workgroup/Domain ?","");
-    my $user = prompt("Smb user ?",$ENV{'USER'});
-    my $pass = prompt("Smb password ?");
-    open(FILE,">.c") || warn "Can't create .c for test: $!\n";
-    print FILE $server,"\t",$share,"\t",$workgroup,"\t",$user,"\t",$pass;
-    close FILE;
-  }
-
-# Trace for debug
-$ans = prompt("Compile module with trace to STDERR ?", "no");
-if ($ans =~ /^y(es)?$/i) { $define = "-DVERBOSE"; }
+my $include = '%%LOCALBASE%%/include/';
+my $lib = '%%LOCALBASE%%/lib/';
 
 # Create config.h for alloca via configure
 system("./configure") == 0 or die "Can't run configure:$!\n";
