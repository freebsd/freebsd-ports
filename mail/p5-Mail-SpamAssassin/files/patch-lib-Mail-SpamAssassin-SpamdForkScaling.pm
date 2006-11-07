--- lib/Mail/SpamAssassin/SpamdForkScaling.pm.orig	Wed Oct  4 22:01:16 2006
+++ lib/Mail/SpamAssassin/SpamdForkScaling.pm	Tue Nov  7 11:15:29 2006
@@ -426,7 +426,13 @@
     dbg("prefork: ordered $kid to accept");
 
     # now wait for it to say it's done that
-    return $self->wait_for_child_to_accept($sock);
+    my $ret = $self->wait_for_child_to_accept($kid, $sock);
+    if ($ret) {
+      return $ret;
+    } else {
+      # retry with another child
+      return $self->order_idle_child_to_accept();
+    }
 
   }
   else {
@@ -436,10 +442,11 @@
 }
 
 sub wait_for_child_to_accept {
-  my ($self, $sock) = @_;
+  my ($self, $kid, $sock) = @_;
 
   while (1) {
     my $state = $self->read_one_message_from_child_socket($sock);
+
     if ($state == PFSTATE_BUSY) {
       return 1;     # 1 == success
     }
@@ -447,7 +454,12 @@
       return undef;
     }
     else {
-      die "prefork: ordered child to accept, but child reported state '$state'";
+      warn "prefork: ordered child $kid to accept, but they reported state '$state', killing rogue";
+      $self->child_error_kill($kid, $sock);
+      $self->adapt_num_children();
+      sleep 1;
+
+      return undef;
     }
   }
 }
@@ -479,6 +491,8 @@
 
 sub update_child_status_busy {
   my ($self) = @_;
+
+# if (rand 4 < 1) { $self->report_backchannel_socket("I".pack("N",$self->{pid})."\n");return; warn "TEST for bug 4594"; die; }
   # "B  b1 b2 b3 b4 \n "
   $self->report_backchannel_socket("B".pack("N",$self->{pid})."\n");
 }
