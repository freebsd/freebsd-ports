--- ../MailScanner-4.26.8.orig/lib/MailScanner/Exim.pm	Fri Feb 13 10:16:22 2004
+++ lib/MailScanner/Exim.pm	Fri Feb 13 10:17:04 2004
@@ -250,7 +250,7 @@
   my($RQf) = $message->{store}{inhhandle};
 
   my %metadata;
-  my($InHeader, $InSubject, $InDel, @headers, $msginfo, $from, @to, $subject);
+  my($InHeader, $InSubject, $InDel, @headers, $msginfo, $from, @to, $subject, @acl);
   my($ip, $sender);
   my($line);
 
@@ -282,12 +282,34 @@
   # and tracking them in %{$metadata{dashvars}}
   while (chomp($line = <$RQf>)) {
     $line =~ s/^-(\w+) ?// or last;
-    $metadata{dashvars}{$1} = 0;
-    $line eq "" and $metadata{"dv_$1"} = 1, next;
-    $metadata{"dv_$1"} = $line;
-    $metadata{dashvars}{$1} = 1;
+    if($1 eq "acl") {
+      # we need to handle acl vars differently
+      if($line =~ /^(\d+) (\d+)$/) {
+	my $buf;
+	my $pos=$1;
+	my $len=$2;
+	$acl[$pos]=[];
+	(read($RQf, $buf, $len + 1)==$len+1) or last;
+	if($buf=~/\n$/) {
+	  chomp $buf;
+	} else {
+	  # invalid format
+	  last;
+	}
+	$acl[$pos]->[0]=$buf;
+      } else {
+	# this is a weird format, and we're not sure how to handle it
+	last;
+      }
+    } else {
+      $metadata{dashvars}{$1} = 0;
+      $line eq "" and $metadata{"dv_$1"} = 1, next;
+      $metadata{"dv_$1"} = $line;
+      $metadata{dashvars}{$1} = 1;
+    }
     next;
   }
+  $metadata{aclvars}=\@acl;
 
   # If it was an invalid queue file, log a warning and tell caller
   unless (defined $line) {
@@ -965,6 +987,7 @@
 
 sub CreateQf {
   my($message) = @_;
+  my $i;
 
   my $Qfile = "";
   my $metadata = $message->{metadata};
@@ -992,6 +1015,15 @@
     $Qfile .= "\n";
   }
 
+  # Add the separate ACL Vars
+  my @acl=@{$metadata->{aclvars}};
+  for($i=0; $i<=$#acl; $i++) {
+    if($acl[$i]) {
+      $Qfile .= "-acl " . $i . " " . length($acl[$i]->[0]) . "\n";
+      $Qfile .= $acl[$i]->[0] . "\n";
+    }
+  }
+
   # Add non-recipients
   $Qfile .= BTreeString($metadata->{nonrcpts});
 
