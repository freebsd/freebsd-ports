--- lib/OpenSSL.pm.orig
+++ lib/OpenSSL.pm
@@ -22,6 +22,7 @@
 
 use POSIX;
 use IPC::Open3;
+use IO::Select;
 use Time::Local;
 
 sub new {
@@ -41,7 +42,7 @@
    close(TEST);
 
    # set version (format: e.g. 0.9.7 or 0.9.7a)
-   if($v =~ /\b(0\.9\.[678][a-z]?)\b/) {
+   if($v =~ /\b(0\.9\.[6-9][a-z]?)\b/ || $v =~ /\b(1\.0\.[01][a-z]?)\b/) {
       $self->{'version'} = $1;
    }
 
@@ -817,7 +818,7 @@
    my $self = shift;
    my $opts = { @_ };
    
-   my ($tmp, $ext, $ret, $file, $pid, $cmd);
+   my ($tmp, $ext, $ret, $file, $pid, $cmd, $cmdout, $cmderr);
    $file = HELPERS::mktmp($self->{'tmp'}."/data");
 
    $cmd = "$self->{'bin'} $opts->{'cmd'}";
@@ -830,16 +831,7 @@
       $cmd .= " -outform $opts->{'outform'}";
    }
 
-   my($rdfh, $wtfh);
-   $ext = "$cmd\n\n";
-   $pid = open3($wtfh, $rdfh, $rdfh, $cmd);
-   print $wtfh "$opts->{'data'}\n";
-   while(<$rdfh>){
-      $ext .= $_;
-      # print STDERR "DEBUG: cmd ret: $_";
-   };
-   waitpid($pid, 0);
-   $ret = $?>>8;
+   ($ret, $tmp, $ext) = _run_with_fixed_input($cmd, $opts->{'data'});
 
    if($self->{'broken'}) {
        if(($ret != 0 && $opts->{'cmd'} ne 'crl') ||
@@ -859,14 +851,15 @@
       }
    }
 
-   open(IN, $file) || do {
-      my $t = sprintf(_("Can't open file %s: %s"), $file, $!);
-      GUI::HELPERS::print_warning($t);
-      return;
-   };
-   $tmp .= $_ while(<IN>);
-   close(IN);
-
+   if (-s $file) { # If the file is empty, the payload is in $tmp (via STDOUT of the called process).
+      open(IN, $file) || do {
+         my $t = sprintf(_("Can't open file %s: %s"), $file, $!);
+         GUI::HELPERS::print_warning($t);
+         return;
+      };
+      $tmp .= $_ while(<IN>);
+      close(IN);
+   }
    unlink($file);
 
    return($ret, $tmp, $ext);
@@ -1076,4 +1069,72 @@
    }
 }
    
+
+=over
+
+=item _run_with_fixed_input($cmd, $input)
+
+This function runs C<$cmd> and writes the C<$input> to STDIN of the
+new process (all at once).
+
+While the command runs, all of its output to STDOUT and STDERR is
+collected.
+
+After the command terminates (closes both STDOUT and STDIN) the
+function returns the command's return value as well as everything it
+wrote to its STDOUT and STDERR in a list.
+
+=back
+
+=cut
+
+sub _run_with_fixed_input {
+   my $cmd = shift;
+   my $input = shift;
+
+   my ($wtfh, $rdfh, $erfh, $pid, $sel, $ret, $stdout, $stderr);
+   $erfh = Symbol::gensym; # Must not be false, otherwise it is lumped together with rdfh
+
+   # Run the command
+   $pid = open3($wtfh, $rdfh, $erfh, $cmd);
+   print $wtfh $input, "\n";
+
+   $stdout = '';
+   $stderr = '';
+   $sel = new IO::Select($rdfh, $erfh);
+   while (my @fhs = $sel->can_read()) {
+      foreach my $fh (@fhs) {
+         if ($fh == $rdfh) { # STDOUT
+            my $bytes_read = sysread($fh, my $buf='', 1024);
+            if ($bytes_read == -1) {
+               warn("Error reading from child's STDOUT: $!\n");
+               $sel->remove($fh);
+             } elsif ($bytes_read == 0) {
+               # print("Child's STDOUT closed.\n");
+               $sel->remove($fh);
+             } else {
+               $stdout .= $buf;
+             }
+         }
+         elsif ($fh == $erfh) { # STDERR
+            my $bytes_read = sysread($fh, my $buf='', 1024);
+            if ($bytes_read == -1) {
+               warn("Error reading from child's STDERR: $!\n");
+               $sel->remove($fh);
+            } elsif ($bytes_read == 0) {
+               # print("Child's STDERR closed.\n");
+               $sel->remove($fh);
+            } else {
+              $stderr .= $buf;
+            }
+         }
+      }
+   }
+
+   waitpid($pid, 0);
+   $ret = $?>>8;
+
+   return ($ret, $stdout, $stderr)
+   }
+
