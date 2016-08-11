--- init.rb.orig	2016-05-13 13:44:03 UTC
+++ init.rb
@@ -1,8 +1,8 @@
 # Redmine Redcarpet formatter
 
 require 'redmine'
-require 'redmine/wiki_formatting/markdown/formatter'
-require 'redmine/wiki_formatting/markdown/helper'
+require 'redmine/wiki_formatting/redcarpet_markdown/formatter'
+require 'redmine/wiki_formatting/redcarpet_markdown/helper'
 
 
 Redmine::Plugin.register :redmine_redcarpet_formatter do
@@ -11,6 +11,6 @@ Redmine::Plugin.register :redmine_redcar
   description 'Markdown wiki formatting by Redcarpet for Redmine'
   version '2.0.1'
 
-  wiki_format_provider 'markdown', Redmine::WikiFormatting::Markdown::Formatter, Redmine::WikiFormatting::Markdown::Helper
+  wiki_format_provider 'redcarpet_markdown', Redmine::WikiFormatting::RedcarpetMarkdown::Formatter, Redmine::WikiFormatting::RedcarpetMarkdown::Helper
 
 end
