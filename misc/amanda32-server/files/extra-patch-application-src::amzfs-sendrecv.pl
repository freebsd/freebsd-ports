--- application-src/amzfs-sendrecv.pl.orig	2009-01-22 02:35:38.000000000 +0100
+++ application-src/amzfs-sendrecv.pl	2009-01-31 10:37:59.495534563 +0100
@@ -235,13 +235,48 @@
         } elsif (defined $errmsg) {
             $self->print_to_server_and_die($action, $errmsg, $Amanda::Script_App::ERROR);
         } else {
-	        $self->print_to_server_and_die($action, "cannot estimate snapshot '$self->{snapshot}\@$self->{snapshot}': unknown reason", $Amanda::Script_App::ERROR);
+	    $self->print_to_server_and_die($action, "cannot estimate snapshot '$self->{snapshot}\@$self->{snapshot}': unknown reason", $Amanda::Script_App::ERROR);
 	}
     }
+    if ($level == 0) {
+	my $compratio = $self->get_compratio();
+	$msg *= int $compratio;
+    }
 
     return $msg;
 }
 
+sub get_compratio
+{
+    my $self = shift;
+    my $action = shift;
+
+    my $cmd;
+    $cmd =  "$self->{pfexec_cmd} $self->{zfs_path} get -Hp -o value compressratio $self->{filesystem}\@$self->{snapshot}";
+    debug "running (get-compression): $cmd";
+    my($wtr, $rdr, $err, $pid);
+    $err = Symbol::gensym;
+    $pid = open3($wtr, $rdr, $err, $cmd);
+    close $wtr;
+    my ($msg) = <$rdr>;
+    my ($errmsg) = <$err>;
+    waitpid $pid, 0;
+    close $rdr;
+    close $err;
+    if ($? !=  0) {
+        if (defined $msg && defined $errmsg) {
+            $self->print_to_server_and_die($action, "$msg, $errmsg", $Amanda::Script_App::ERROR);
+        } elsif (defined $msg) {
+            $self->print_to_server_and_die($action, $msg, $Amanda::Script_App::ERROR);
+        } elsif (defined $errmsg) {
+            $self->print_to_server_and_die($action, $errmsg, $Amanda::Script_App::ERROR);
+        } else {
+	    $self->print_to_server_and_die($action, "cannot read compression ratio '$self->{snapshot}\@$self->{snapshot}': unknown reason", $Amanda::Script_App::ERROR);
+	}
+    }
+    return $msg
+}
+
 sub command_index_from_output {
 }
 
