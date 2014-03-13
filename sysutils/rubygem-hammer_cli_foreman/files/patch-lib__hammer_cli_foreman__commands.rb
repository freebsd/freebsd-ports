--- lib/hammer_cli_foreman/commands.rb.orig	2014-03-12 11:03:33.000000000 +0100
+++ lib/hammer_cli_foreman/commands.rb	2014-03-12 11:03:49.000000000 +0100
@@ -60,9 +60,9 @@
     end
 
     def execute
-      if respond_to?(:page) && respond_to?(:per_page)
-        self.page ||= 1
-        self.per_page ||= HammerCLI::Settings.get(:ui, :per_page) || DEFAULT_PER_PAGE
+      if respond_to?(:option_page) && respond_to?(:option_per_page)
+        self.option_page ||= 1
+        self.option_per_page ||= HammerCLI::Settings.get(:ui, :per_page) || DEFAULT_PER_PAGE
         browse_collection
       else
         retrieve_and_print
@@ -79,10 +79,10 @@
       while list_next do
         d = retrieve_and_print
 
-        if (d.size >= self.per_page.to_i) && interactive?
+        if (d.size >= self.option_per_page.to_i) && interactive?
           answer = ask("List next page? (Y/n): ").downcase
           list_next = (answer == 'y' || answer == '')
-          self.page += 1
+          self.option_page += 1
         else
           list_next = false
         end
