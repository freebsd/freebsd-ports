--- lib/chef/provider/service/freebsd.rb.orig	2014-12-08 06:38:20 UTC
+++ lib/chef/provider/service/freebsd.rb
@@ -43,6 +43,9 @@ class Chef
             return
           end
           Chef::Log.debug("#{@current_resource} found at #{@init_command}")
+          if @new_resource.supports[:status] && !@new_resource.status_command
+            @new_resource.status_command "#{@init_command} onestatus"
+          end
           determine_current_status!
           # Default to disabled if the service doesn't currently exist
           # at all
@@ -50,7 +53,7 @@ class Chef
           if ::File.exists?("/etc/rc.conf") && var_name
             read_rc_conf.each do |line|
               case line
-              when /#{Regexp.escape(var_name)}="(\w+)"/
+              when /^\s*#{Regexp.escape(var_name)}="(\w+)"/
                 @enabled_state_found = true
                 if $1 =~ /[Yy][Ee][Ss]/
                   @current_resource.enabled true
@@ -156,7 +159,7 @@ class Chef
         def set_service_enable(value)
           lines = read_rc_conf
           # Remove line that set the old value
-          lines.delete_if { |line| line =~ /#{Regexp.escape(service_enable_variable_name)}/ }
+          lines.delete_if { |line| line =~ /^\s*#{Regexp.escape(service_enable_variable_name)}="(\w+)"/ }
           # And append the line that sets the new value at the end
           lines << "#{service_enable_variable_name}=\"#{value}\""
           write_rc_conf(lines)
