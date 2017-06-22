--- lib/RT/Config.pm.orig	2016-07-18 20:20:17 UTC
+++ lib/RT/Config.pm
@@ -147,6 +147,14 @@ can be set for each config optin:
 our %META;
 %META = (
     # General user overridable options
+    RestrictReferrerLogin => {
+        PostLoadCheck => sub {
+            my $self = shift;
+            if (defined($self->Get('RestrictReferrerLogin'))) {
+                RT::Logger->error("The config option 'RestrictReferrerLogin' is incorrect, and should be 'RestrictLoginReferrer' instead.");
+            }
+        },
+    },
     DefaultQueue => {
         Section         => 'General',
         Overridable     => 1,
