--- ../MailScanner-install-4.35.11.orig/lib/MailScanner/Message.pm	Wed Nov 10 08:31:01 2004
+++ lib/MailScanner/Message.pm	Wed Nov 10 08:33:19 2004
@@ -4043,6 +4043,8 @@
     $squashedtext =~ s#%([0-9a-f][0-9a-f])#chr(hex('0x' . $1))#gei; # Unescape
     $squashedtext =~ s/\s+//g; # Remove any whitespace
     $squashedtext =~ s/\\/\//g;
+    $squashedtext =~ s/(\<\/?[^>]*\>)*//ig; # Remove tags
+    #$squashedtext =~ s/^(\<\/?(br|p|ul)\>)*//ig; # Remove leading br, p, ul tags
     #print STDERR "Text = \"$text\"\n";
     #print STDERR "1SquashedText = \"$squashedtext\"\n";
     #print STDERR "1LinkURL      = \"$DisarmLinkURL\"\n";
@@ -4055,9 +4057,11 @@
       $linkurl =~ s/\%a0//g;
       $linkurl =~ s#%([0-9a-f][0-9a-f])#chr(hex('0x' . $1))#gei; # Unescape
       $linkurl =~ s/\s+//; # Remove any whitespace
+      #$linkurl =~ s/(\<\/?[^>]*\>)*//ig; # Remove tags
+      #$linkurl =~ s/^(\<\/?(br|p|ul)\>)*//ig; # Remove leading br, p, ul tags
       $linkurl =~ s/^(https?|ftp):\/\///;
       $linkurl =~ s/\/.*$//; # Only compare up to the first '/' (hostname only)
-      $linkurl =~ s/\<\/?(br|p)\>$//i; # Remove trailing <br> and <p> tags
+      $linkurl =~ s/(\<\/?(br|p|ul)\>)*$//ig; # Remove trailing br, p, ul tags
       $linkurl =~ s/\/$//; # LinkURL is trimmed -- note
       #print STDERR "2SquashedText = \"$squashedtext\"\n";
       #print STDERR "2LinkURL      = \"$linkurl\"\n";
