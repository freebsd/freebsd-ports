--- CGI/Base.pm.orig	Sat Apr  5 03:27:34 1997
+++ CGI/Base.pm	Fri Apr 19 18:46:05 2002
@@ -831,7 +831,7 @@
 
     my $bytes = $self->pass_back($svr_fh);
 
-    close($svr_fh);
+    CORE::close($svr_fh);
     if ($Debug) {
 	$self->log("Pass-thru complete. Bytes: $sent thru, $bytes back.");
 	$self->log("Warning: possibly truncated by SIGPIPE") if $SigPipe;
@@ -1040,7 +1040,7 @@
 	$fh = ++$_newfh_seq;
 	$fh = "CGI::Base::_$fh";
     }
-    close($fh) if defined fileno($fh);	# may be being reused
+    CORE::close($fh) if defined fileno($fh);	# may be being reused
     $fh = $$fh if ref $fh;		# reusing previous ref
     bless \*{$fh}, 'FileHandle';
 }
