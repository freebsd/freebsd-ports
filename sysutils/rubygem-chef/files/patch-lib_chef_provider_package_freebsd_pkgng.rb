--- lib/chef/provider/package/freebsd/pkgng.rb.orig	2014-12-15 06:02:56 UTC
+++ lib/chef/provider/package/freebsd/pkgng.rb
@@ -45,14 +45,20 @@ class Chef
 
           def current_installed_version
             pkg_info = shell_out!("pkg info \"#{@new_resource.package_name}\"", :env => nil, :returns => [0,70])
-            pkg_info.stdout[/^#{Regexp.escape(@new_resource.package_name)}-(.+)/, 1]
+            pkg_info.stdout[/^Version +: (.+)$/, 1]
           end
 
           def candidate_version
             @new_resource.source ? file_candidate_version : repo_candidate_version
           end
 
-
+          def upgrade_package(name, version)
+            if @current_resource.version
+              shell_out!("pkg install -y#{expand_options(@new_resource.options)} #{name}", :env => { 'LC_ALL' => nil }).status
+            else
+              install_package(name, version)
+            end
+          end
 
           private
 
