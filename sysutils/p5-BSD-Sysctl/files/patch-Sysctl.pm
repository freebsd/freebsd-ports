--- Sysctl.pm.orig	2014-01-21 16:08:32.000000000 -0700
+++ Sysctl.pm	2018-03-08 12:06:28.456797000 -0700
@@ -42,6 +42,8 @@
 use constant FMT_STRUCT_CDEV => 25;
 use constant FMT_64          => 26;
 use constant FMT_U64         => 27;
+use constant FMT_UINT8       => 28;
+use constant FMT_INT8        => 29;
 
 push @EXPORT_OK, 'sysctl';
 sub sysctl {
@@ -105,7 +107,9 @@
 
 sub reset {
     my $self = shift;
-    delete $self->{_ctx};
+    delete $self->{_next};
+    delete $self->{_name};
+    delete $self->{_len0};
     return $self;
 }
 
