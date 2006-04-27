--- ../MailScanner-install-4.52.2.orig/lib/MailScanner/Exim.pm	Wed Apr 26 09:25:10 2006
+++ lib/MailScanner/Exim.pm	Wed Apr 26 09:26:00 2006
@@ -251,7 +251,7 @@
 
   my %metadata;
   my($InHeader, $InSubject, $InDel, @headers, $msginfo, $from, @to, $subject);
-  my($ip, $sender, @acl, $line);
+  my($ip, $sender, @acl, @aclc, @aclm, $line, $acltype);
 
   # Seek to the start of the file in case anyone read the file
   # between me opening it and locking it.
@@ -287,13 +287,24 @@
     #$line eq "" and $metadata{"dv_$1"} = 1, next;
     #$metadata{"dv_$1"} = $line;
     #$metadata{dashvars}{$1} = 1;
-    if($1 eq "acl") {
+    # ACLs can be -acl or -aclc or -aclm.
+    $acltype = $1;
+    if($acltype =~ /^acl[cm]?$/) {
       # we need to handle acl vars differently
       if($line =~ /^(\d+) (\d+)$/) {
         my $buf;
         my $pos = $1;
         my $len = $2;
-        $acl[$pos]=[];
+        if ($acltype eq "acl") {
+          $acl[$pos]->[0] = [];
+        } elsif ($acltype eq "aclc") {
+          $aclc[$pos]->[0] = [];
+        } elsif ($acltype eq "aclm") {
+          $aclm[$pos]->[0] = [];
+        } else {
+          # invalid format
+          last;
+        }
         (read($RQf, $buf, $len + 1)==$len+1) or last;
         if($buf =~ /\n$/) {
           chomp $buf;
@@ -301,7 +312,16 @@
           # invalid format
           last;
         }
-        $acl[$pos]->[0] = $buf;
+        if ($acltype eq "acl") {
+          $acl[$pos]->[0] = $buf;
+        } elsif ($acltype eq "aclc") {
+          $aclc[$pos]->[0] = $buf;
+        } elsif ($acltype eq "aclm") {
+          $aclm[$pos]->[0] = $buf;
+        } else {
+          # invalid format
+          last;
+        }
       } else {
         # this is a weird format, and we're not sure how to handle it
         last;
@@ -315,6 +335,8 @@
     next;
   }
   $metadata{aclvars} = \@acl;
+  $metadata{aclcvars} = \@aclc;
+  $metadata{aclmvars} = \@aclm;
 
   # If it was an invalid queue file, log a warning and tell caller
   unless (defined $line) {
@@ -1059,11 +1081,24 @@
 
   # ACLs patch starts here
   # Add the separate ACL Vars
-  my @acl = @{$metadata->{aclvars}};
-  for($i=0; $i<=$#acl; $i++) {
+  my @acl  = @{$metadata->{aclvars}};
+  my @aclc = @{$metadata->{aclcvars}};
+  my @aclm = @{$metadata->{aclmvars}};
+  my $greatestacl = $#acl;
+  $greatestacl    = $#aclc if $#aclc > $greatestacl;
+  $greatestacl    = $#aclm if $#aclm > $greatestacl;
+  for($i=0; $i<=$greatestacl; $i++) {
     if($acl[$i]) {
       $Qfile .= "-acl " . $i . " " . length($acl[$i]->[0]) . "\n";
       $Qfile .= $acl[$i]->[0] . "\n";
+    }
+    if($aclc[$i]) {
+      $Qfile .= "-aclc " . $i . " " . length($aclc[$i]->[0]) . "\n";
+      $Qfile .= $aclc[$i]->[0] . "\n";
+    }
+    if($aclm[$i]) {
+      $Qfile .= "-aclm " . $i . " " . length($aclm[$i]->[0]) . "\n";
+      $Qfile .= $aclm[$i]->[0] . "\n";
     }
   }
 
