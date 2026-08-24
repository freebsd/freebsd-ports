--- Makefile.PL.orig	2026-08-07 16:04:09 UTC
+++ Makefile.PL
@@ -23,7 +23,7 @@ my %WriteMakefileArgs = (
     "Crypt::OpenSSL::X509" => 0,
     "Crypt::PK::RSA" => 0,
     "DateTime" => 0,
-    "DateTime::Format::XSD" => "0.5",
+    "DateTime::Format::XSD" => "0",
     "DateTime::HiRes" => 0,
     "Digest::MD5" => 0,
     "Exporter" => 0,
@@ -87,7 +87,7 @@ my %FallbackPrereqs = (
   "Crypt::OpenSSL::X509" => 0,
   "Crypt::PK::RSA" => 0,
   "DateTime" => 0,
-  "DateTime::Format::XSD" => "0.5",
+  "DateTime::Format::XSD" => "0",
   "DateTime::HiRes" => 0,
   "Digest::MD5" => 0,
   "Exporter" => 0,
