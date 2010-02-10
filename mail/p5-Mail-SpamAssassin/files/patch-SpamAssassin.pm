--- lib/Mail/SpamAssassin.pm.orig	2010/01/29 15:48:09	904525
+++ lib/Mail/SpamAssassin.pm	2010/01/29 15:48:29	904526
@@ -75,6 +75,7 @@
 use Mail::SpamAssassin::Message;
 use Mail::SpamAssassin::PluginHandler;
 use Mail::SpamAssassin::DnsResolver;
+use Mail::SpamAssassin::Util qw(untaint_var);
 use Mail::SpamAssassin::Util::ScopedTimer;
 
 use Errno qw(ENOENT EACCES);
@@ -490,20 +490,21 @@
   $self->init(1);
   my $timer = $self->time_method("parse");
 
-  my $msg = Mail::SpamAssassin::Message->new({
-    message=>$message, parsenow=>$parsenow,
-    normalize=>$self->{conf}->{normalize_charset},
-    suppl_attrib=>$suppl_attrib });
-
+  my $master_deadline;
   if (ref $suppl_attrib && exists $suppl_attrib->{master_deadline}) {
-    $msg->{master_deadline} = $suppl_attrib->{master_deadline};  # may be undef
+    $master_deadline = $suppl_attrib->{master_deadline};  # may be undef
   } elsif ($self->{conf}->{time_limit}) {  # defined and nonzero
-    $msg->{master_deadline} = $start_time + $self->{conf}->{time_limit};
+    $master_deadline = $start_time + $self->{conf}->{time_limit};
   }
-  if (defined $msg->{master_deadline}) {
-    dbg("config: time limit %.1f s", $msg->{master_deadline} - $start_time);
+  if (defined $master_deadline) {
+    dbg("config: time limit %.1f s", $master_deadline - $start_time);
   }
 
+  my $msg = Mail::SpamAssassin::Message->new({
+    message=>$message, parsenow=>$parsenow,
+    normalize=>$self->{conf}->{normalize_charset},
+    master_deadline=>$master_deadline, suppl_attrib=>$suppl_attrib });
+
   # bug 5069: The goal here is to get rendering plugins to do things
   # like OCR, convert doc and pdf to text, etc, though it could be anything

@@ -1935,7 +1936,7 @@
       close IN  or die "error closing $defprefs: $!";
 
       if (($< == 0) && ($> == 0) && defined($user)) { # chown it
-        my ($uid,$gid) = (getpwnam($user))[2,3];
+        my ($uid,$gid) = (getpwnam(untaint_var($user)))[2,3];
         unless (chown($uid, $gid, $fname)) {
           warn "config: couldn't chown $fname to $uid:$gid for $user: $!\n";
         }

