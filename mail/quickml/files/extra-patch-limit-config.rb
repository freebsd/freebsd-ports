--- lib/quickml/config.rb.org	2004-06-07 17:50:59.000000000 +0900
+++ lib/quickml/config.rb	2012-06-21 15:55:28.000000000 +0900
@@ -56,6 +56,19 @@
       @group = (config[:group] or "root")
       @use_qmail_verp = (config[:use_qmail_verp] or false)
 
+      @creator_check = (config[:creator_check] or false)
+      @creator_addresses = if config[:creator_addresses]
+			     config[:creator_addresses]
+			   else
+			     [ @domain ]
+			   end
+      @member_check = (config[:member_check] or false)
+      @member_addresses = if config[:member_addresses]
+			    config[:member_addresses]
+			  else
+			    [ @domain ]
+			  end
+
       charset = @catalog.charset if @catalog
       @content_type = "text/plain"
 
