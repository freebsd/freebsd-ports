--- Session/Store/File.pm.orig	Mon Jul 24 05:44:52 2000
+++ Session/Store/File.pm	Thu Dec  6 17:49:31 2001
@@ -33,13 +33,14 @@
     my $session = shift;
  
     my $directory = $session->{args}->{Directory} || $Apache::Session::Store::File::Directory;
+    my $file = $directory.'/'.$session->{data}->{_session_id};
 
-    if (-e $directory.'/'.$session->{data}->{_session_id}) {
-        die "Object already exists in the data store";
+    if (-e $file) {
+        die "Object already exists in the data store: $file";
     }
     
-    sysopen ($self->{fh}, $directory.'/'.$session->{data}->{_session_id}, O_RDWR|O_CREAT) ||
-        die "Could not open file: $!";
+    sysopen ($self->{fh}, $file, O_RDWR|O_CREAT) ||
+        die "Could not open $file: $!";
 
     $self->{opened} = 1;
     
@@ -51,10 +52,11 @@
     my $session = shift;
     
     my $directory = $session->{args}->{Directory} || $Apache::Session::Store::File::Directory;
+    my $file = $directory.'/'.$session->{data}->{_session_id};
 
     if (!$self->{opened}) {
-        sysopen ($self->{fh}, $directory.'/'.$session->{data}->{_session_id}, O_RDWR|O_CREAT) ||
-            die "Could not open file: $!";
+        sysopen ($self->{fh}, $file, O_RDWR|O_CREAT) ||
+            die "Could not open $file: $!";
         
         $self->{opened} = 1;
     }
@@ -69,11 +71,12 @@
     my $session = shift;
     
     my $directory = $session->{args}->{Directory} || $Apache::Session::Store::File::Directory;
+    my $file = $directory.'/'.$session->{data}->{_session_id};
     
-    if (-e $directory.'/'.$session->{data}->{_session_id}) {
+    if (-e $file) {
         if (!$self->{opened}) {
-            sysopen ($self->{fh}, $directory.'/'.$session->{data}->{_session_id}, O_RDWR|O_CREAT) ||
-                die "Could not open file: $!";
+            sysopen ($self->{fh}, $file, O_RDWR|O_CREAT) ||
+                die "Could not open $file: $!";
 
             $self->{opened} = 1;
         }
@@ -96,15 +99,16 @@
     my $session = shift;
         
     my $directory = $session->{args}->{Directory} || $Apache::Session::Store::File::Directory;
+    my $file = $directory.'/'.$session->{data}->{_session_id};
 
     if ($self->{opened}) {
         CORE::close $self->{fh};
         $self->{opened} = 0;
     }
 
-    if (-e $directory.'/'.$session->{data}->{_session_id}) {
-        unlink ($directory.'/'.$session->{data}->{_session_id}) ||
-            die "Could not remove file: $!";
+    if (-e $file) {
+        unlink ($file) ||
+            die "Could not remove $file: $!";
     }
     else {
         die "Object does not exist in the data store";
