--- lib/XML/Simple.pm.orig	Mon Apr  5 09:12:47 2004
+++ lib/XML/Simple.pm	Thu Jun 17 13:41:37 2004
@@ -331,7 +331,7 @@
   if($filename) {
     # $tree = $xp->parsefile($filename);  # Changed due to prob w/mod_perl
     local(*XML_FILE);
-    open(XML_FILE, '<', $filename) || croak qq($filename - $!);
+    open(XML_FILE, '<'. $filename) || croak qq($filename - $!);
     $tree = $xp->parse(*XML_FILE);
     close(XML_FILE);
   }
@@ -541,9 +541,9 @@
     }
     else {
       local(*OUT);
-      open(OUT, '>', "$self->{opt}->{outputfile}") ||
+      open(OUT, '>'. "$self->{opt}->{outputfile}") ||
         croak "open($self->{opt}->{outputfile}): $!";
-      binmode(OUT, ':utf8') if($] >= 5.008);
+#      binmode(OUT, ':utf8') if($] >= 5.008);
       print OUT $xml || croak "print: $!";
       close(OUT);
     }
@@ -1535,7 +1535,7 @@
 sub numeric_escape {
   my($self, $data, $level) = @_;
 
-  use utf8; # required for 5.6
+#  use utf8; # required for 5.6
 
   if($self->{opt}->{numericescape} eq '2') {
     $data =~ s/([^\x00-\x7F])/'&#' . ord($1) . ';'/gse;
@@ -1569,7 +1569,7 @@
   my @keys = $self->{opt}->{nosort} ? keys %$hashref : sort keys %$hashref;
   foreach $key (@keys) {
     $value = $hashref->{$key};
-    return($hashref) unless(UNIVERSAL::isa($value, 'HASH'));
+    return($hashref) unless(UNIVERSAL::isa($value||'', 'HASH'));
 
     if(ref($self->{opt}->{keyattr}) eq 'HASH') {
       return($hashref) unless(defined($self->{opt}->{keyattr}->{$parent}));
