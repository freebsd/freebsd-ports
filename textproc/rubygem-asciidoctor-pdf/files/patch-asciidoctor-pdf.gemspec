Obtained from:
https://github.com/asciidoctor/asciidoctor-pdf/commit/631606e91f487e797e73c15467979b0b63c5ff68
https://github.com/asciidoctor/asciidoctor-pdf/commit/cd71092a5c5c86b9770359a0f1bd7c60b9dce7ea


--- asciidoctor-pdf.gemspec.orig	2023-12-27 02:32:44 UTC
+++ asciidoctor-pdf.gemspec
@@ -26,8 +26,8 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<matrix>.freeze, ["~> 0.4"])
   s.add_runtime_dependency(%q<prawn-table>.freeze, ["~> 0.2.0"])
   s.add_runtime_dependency(%q<prawn-templates>.freeze, ["~> 0.1.0"])
-  s.add_runtime_dependency(%q<prawn-svg>.freeze, ["~> 0.32.0"])
-  s.add_runtime_dependency(%q<prawn-icon>.freeze, ["~> 3.0.0"])
+  s.add_runtime_dependency(%q<prawn-svg>.freeze, ["~> 0.33.0"])
+  s.add_runtime_dependency(%q<prawn-icon>.freeze, ["~> 3.1.0"])
   s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.1"])
   s.add_runtime_dependency(%q<treetop>.freeze, ["~> 1.6.0"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 13.0.0"])
--- lib/asciidoctor/pdf/ext/prawn/extensions.rb.orig	2023-12-27 02:32:43 UTC
+++ lib/asciidoctor/pdf/ext/prawn/extensions.rb
@@ -16,7 +16,7 @@ module Asciidoctor
       ColumnBox = ::Prawn::Document::ColumnBox
 
       FontAwesomeIconSets = %w(fab far fas)
-      IconSets = %w(fab far fas fi pf).to_set
+      IconSets = %w(fab far fas fi pf mdi).to_set
       IconSetPrefixes = IconSets.map {|it| it + '-' }
       InitialPageContent = %(q\n)
       (FontStyleToSet = {
