--- ../MailScanner-4.26.8.orig/lib/MailScanner/Message.pm	Mon Feb 23 17:37:26 2004
+++ lib/MailScanner/Message.pm	Mon Feb 23 17:38:33 2004
@@ -2,7 +2,7 @@
 #   MailScanner - SMTP E-Mail Virus Scanner
 #   Copyright (C) 2002  Julian Field
 #
-#   $Id: Message.pm,v 1.126.2.74 2004/01/27 15:20:58 jkf Exp $
+#   $Id: Message.pm,v 1.126.2.76 2004/02/11 12:10:08 jkf Exp $
 #
 #   This program is free software; you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
@@ -50,7 +50,7 @@
 use vars qw($VERSION);
 
 ### The package version, both in 1.23 style *and* usable by MakeMaker:
-$VERSION = substr q$Revision: 1.126.2.74 $, 10;
+$VERSION = substr q$Revision: 1.126.2.76 $, 10;
 
 # Attributes are
 #
@@ -548,8 +548,13 @@
     if ($HamSpam eq 'nonspam') {
       MailScanner::Log::WarnLog("Does not make sense to bounce non-spam");
     } else {
-      MailScanner::Log::WarnLog('The "bounce" Spam Action no longer exists');
-      # Do not uncomment this $this->HandleSpamBounce();
+      #MailScanner::Log::WarnLog('The "bounce" Spam Action no longer exists');
+      if ($this->{ishigh}) {
+        MailScanner::Log::InfoLog("Will not bounce high-scoring spam")
+      } else {
+        $this->HandleSpamBounce()
+          if MailScanner::Config::Value('enablespambounce', $this);
+      }
     }
   }
 
@@ -684,7 +689,7 @@
   $messagefh->open($filename)
     or MailScanner::Log::WarnLog("Cannot open message file %s, %s",
                                  $filename, $!);
-  $emailmsg = "";
+  $emailmsg = "X-MailScanner-Bounce: yes\n";
   while(<$messagefh>) {
     chomp;
     s#"#\\"#g;
@@ -1007,11 +1012,80 @@
     }
   }
 
+  $this->ExplodePart($explodeinto);
+
   # Set the owner and group on all the extracted files
   chown $workarea->{uid}, $workarea->{gid}, glob "$explodeinto/*"
     if $workarea->{changeowner};
 }
 
+# Try to parse all the text bits of each message, looking to see if they
+# can be parsed into files which might be infected.
+# How I treat these in the MIME structure is anyone's guess!
+sub ExplodePart {
+  my($this, $explodeinto) = @_;
+
+  my($dir, $part);
+
+  $dir = new DirHandle;
+
+  $dir->open($explodeinto);
+  while($part = $dir->read) {
+    #print STDERR "Reading $part\n";
+    next unless $part =~ /^msg.*txt/;
+    
+    # Try and find hidden messages in the text files
+    my $file = new FileHandle;
+    #print STDERR "About to read $explodeinto/$part\n";
+    $file->open("$explodeinto/$part") or next;
+
+    # Try reading the first few lines to see if they look like mail headers
+    my($linenum, $foundheader, $prevline, $line, $position, $prevpos);
+    $foundheader = 0;
+    $prevpos = 0;
+    for ($linenum=0; $linenum<100 && !$file->eof(); $linenum++) {
+      $position = $file->getpos();
+      $line = <$file>;
+      # Must have 2 lines of header
+      if ($prevline =~ /^[^:]+: / && $line =~ /(^\s+)|(^[^:]+ )|(^\s+.*=)/) {
+        #print STDERR "Found start of a header at \"$prevline\"\n and \"$line\"\n";
+        $foundheader = 1;
+        last;
+      }
+      $prevline = $line;
+      $prevpos  = $position;
+    }
+
+    unless ($foundheader) {
+      $file->close();
+      $dir->close();
+      return;
+    }
+
+    # Rewind to the start of the header
+    $file->setpos($prevpos);
+
+    # Setup everything for the MIME parser
+    my $parser = MIME::Parser->new;
+    my $filer  = MIME::Parser::FileInto::MailScanner->new($explodeinto);
+
+    # Over-ride the default default character set handler so it does it
+    # much better than the MIME-tools default handling.
+    MIME::WordDecoder->default->handler('*' => \&WordDecoderKeep7Bit);
+
+    #print STDERR "Exploding message " . $this->{id} . " into " .
+    #             $explodeinto . "\n";
+    $parser->filer($filer);
+    $parser->extract_uuencode(1); # uue is off by default
+    $parser->output_to_core('NONE'); # everything into files
+
+    # Do the actual parsing
+    my $entity = eval { $parser->parse($file) };
+
+    $file->close;
+  }
+}
+
 
 # Print the infection reports for this message
 sub PrintInfections {
@@ -1167,10 +1241,13 @@
 # them some time later, but I wanted to keep them separate if possible
 # in case anyone wanted a feature in the future which would be easier
 # with separate reports.
+# If safefile2file does not map for a filename, ban the whole message
+# to be on the safe side.
 sub CombineReports {
   my $this = shift;
 
   my($file, $text, $Name);
+  my(%reports, %types);
   #print STDERR "Combining reports for " . $this->{id} . "\n";
 
   # If they want to include the scanner name in the reports, then also
@@ -1191,29 +1268,48 @@
   while (($file, $text) = each %{$this->{virusreports}}) {
     #print STDERR "Adding file $file report $text\n";
     $this->{allreports}{$file} .= $text;
+    $reports{$file} .= $text;
   }
   while (($file, $text) = each %{$this->{virustypes}}) {
     #print STDERR "Adding file $file type $text\n";
     $this->{alltypes}{$file} .= $text;
+    $types{$file} .= $text;
   }
   while (($file, $text) = each %{$this->{namereports}}) {
     #print STDERR "Adding file \"$file\" report \"$text\"\n";
     $text =~ s/\n(.)/\n$Name:  $1/g; # Make sure name is at the front of this
     #print STDERR "report is now \"$text\"\n";
     $this->{allreports}{$file} .= $Name . $text;
+    $reports{$file} .= $Name . $text;
   }
   while (($file, $text) = each %{$this->{nametypes}}) {
     #print STDERR "Adding file $file type $text\n";
     $this->{alltypes}{$file} .= $text;
+    $types{$file} .= $text;
   }
   while (($file, $text) = each %{$this->{otherreports}}) {
     #print STDERR "Adding file $file report $text\n";
     $this->{allreports}{$file} .= $Name . $text;
+    $reports{$file} .= $Name . $text;
   }
   while (($file, $text) = each %{$this->{othertypes}}) {
     #print STDERR "Adding file $file type $text\n";
     $this->{alltypes}{$file} .= $text;
+    $types{$file} .= $text;
+  }
+
+  # Now look for the reports we can't match anywhere and make them
+  # map to the entire message.
+  my($key, $value);
+  while(($key, $value) = each %reports) {
+    if (!exists($this->{safefile2file}{$key})) {
+      delete $this->{allreports}{$key};
+      delete $this->{alltypes}{$key};
+      $this->{allreports}{""} .= $value;
+      $this->{alltypes}{""} .= $types{$key};
+    }
   }
+
   #print STDERR "Finished combining reports\n";
 }
 
@@ -3309,6 +3405,50 @@
     $index = $#{$self->{ME_Parts}} + 2 + $index if ($index < 0);
     splice(@{$self->{ME_Parts}}, $index, 0, $part);
     $part;
+}
+
+
+#
+# Over-ride a function in Mail::Header that parses the block of headers
+# at the top of each MIME section. My improvement allows the first line
+# of the header block to be missing, which breaks the original parser
+# though the filename is still there.
+#
+
+package Mail::Header;
+
+sub extract
+{
+ my $me = shift;
+ my $arr = shift;
+ my $line;
+
+ $me->empty;
+
+ # JKF Make this more robust by allowing first line of header to be missing
+ shift @{$arr} while scalar(@{$arr}) &&
+                     $arr->[0] =~ /\A[ \t]+/o &&
+                     $arr->[1] =~ /\A$FIELD_NAME/o;
+ # JKF End mod here
+
+ while(scalar(@{$arr}) && $arr->[0] =~ /\A($FIELD_NAME|From )/o)
+  {
+   my $tag = $1;
+
+   $line = shift @{$arr};
+   $line .= shift @{$arr}
+       while(scalar(@{$arr}) && $arr->[0] =~ /\A[ \t]+/o);
+
+   ($tag,$line) = _fmt_line($me,$tag,$line);
+
+   _insert($me,$tag,$line,-1)
+      if defined $line;
+  }
+
+ shift @{$arr}
+  if(scalar(@{$arr}) && $arr->[0] =~ /\A\s*\Z/o);
+
+ $me;
 }
 
 
