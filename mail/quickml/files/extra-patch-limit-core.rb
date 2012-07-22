--- lib/quickml/core.rb.org	2004-06-09 05:15:11.000000000 +0900
+++ lib/quickml/core.rb	2012-06-21 15:55:28.000000000 +0900
@@ -17,6 +17,8 @@
   class TooLargeMail < QuickMLException; end
   class TooManyMembers < QuickMLException; end
   class InvalidMLName < QuickMLException; end
+  class InvalidCreator < QuickMLException; end
+  class InvalidMembers < QuickMLException; end
 
   # It preserves case information. but it accepts an
   # address case-insensitively for member management.
@@ -96,6 +98,10 @@
       @logger = @config.logger
       @catalog = @config.catalog
 
+      if newly_created? and @config.creator_check
+        raise InvalidCreator unless valid_members?(creator, @config.creator_addresses)
+      end
+
       init_ml_config
       init_members
       init_count
@@ -114,6 +120,13 @@
     attr_reader :charset
     attr_reader :max_members
 
+    def valid_members? (address, pat)
+      pat.each do |entry|
+	return true if /#{entry}/i =~ address
+      end
+      false
+    end
+    
     def self.valid_name? (name)
       /^([0-9a-zA-Z_.-]+)(@[0-9a-zA-Z_.-]+)?$/ =~ name
     end
@@ -607,6 +620,7 @@
         begin
           add_member(address)
         rescue TooManyMembers
+        rescue InvalidMembers
         end
       }
       submit(mail)
@@ -636,6 +650,9 @@
     end
 
     def add_member (address)
+      if @config.member_check
+        raise InvalidMembers unless valid_members?(address, @config.member_addresses)
+      end
       if exclude?(address)
 	@logger.vlog "Excluded: #{address}"
 	return
@@ -827,6 +844,29 @@
       @logger.log "[#{ml.name}]: Too Many Members: #{address}"
     end
 
+    def report_invalid_members (ml, invalid_members)
+      header = []
+      subject = Mail.encode_field(_("[QuickML] Error: %s", @mail["Subject"]))
+      header.push(["To",	@mail.from],
+		  ["From",	ml.address],
+		  ["Subject",	subject],
+                  ["Content-type", content_type])
+
+      body =  _("The following addresses cannot be added because <%s> mailing list can join known members only.\n\n",
+		ml.address)
+      invalid_members.each {|address|
+        body << sprintf("<%s>\n", address)
+      }
+
+      body << generate_footer
+      Mail.send_mail(@config.smtp_host, @config.smtp_port, @logger,
+		     :mail_from => '', 
+		     :recipient => @mail.from,
+		     :header => header,
+		     :body => body)
+      @logger.log "[#{ml.name}]: Invalid Members by #{@mail.from}"
+    end
+
     def report_invalid_mladdress (mladdress)
       header = []
       subject = Mail.encode_field(_("[QuickML] Error: %s", @mail["Subject"]))
@@ -846,6 +886,23 @@
       @logger.log "Invalid ML Address: #{mladdress}"
     end
 
+    def report_invalid_creator (mladdress)
+      header = []
+      subject = Mail.encode_field(_("[QuickML] Error: %s", @mail["Subject"]))
+      header.push(["To",	@mail.from],
+		  ["From",	@config.postmaster],
+		  ["Subject",	subject],
+                  ["Content-type", content_type])
+      body =  _("Invalid Creator: <%s> by <%s>.\n", mladdress, @mail.from)
+      body << generate_footer
+      Mail.send_mail(@config.smtp_host, @config.smtp_port, @logger,
+		     :mail_from => '', 
+		     :recipient => @mail.from,
+		     :header => header,
+		     :body => body)
+      @logger.log "Invalid Creator: #{mladdress} by #{@mail.from}"
+    end
+
     def mail_log
       @logger.vlog "MAIL FROM:<#{@mail.mail_from}>"
       @mail.recipients.each {|recipient|
@@ -868,6 +925,8 @@
 	ml.add_member(address)
       rescue TooManyMembers
         @unadded_addresses.push(address)
+      rescue InvalidMembers
+        @invalid_members.push(address)
       end
     end
 
@@ -879,6 +938,7 @@
 
     def submit_article (ml)
       @unadded_addresses = []
+      @invalid_members = []
       if ml_address_in_to?(ml)
         add_member(ml, @mail.from)
         @mail.collect_cc.each {|address| 
@@ -888,6 +948,9 @@
       unless @unadded_addresses.empty?
         report_too_many_members(ml, @unadded_addresses)
       end
+      unless @invalid_members.empty?
+        report_invalid_members(ml, @invalid_members)
+      end
       ml.submit(@mail)
     end
 
@@ -991,6 +1054,8 @@
 	  }
 	rescue InvalidMLName
 	  report_invalid_mladdress(mladdress)
+        rescue InvalidCreator
+	  report_invalid_creator(mladdress)
 	end
       end
     end
