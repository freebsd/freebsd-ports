--- lib/puppet.rb.orig	2017-10-04 19:54:04.901540166 -0700
+++ lib/puppet.rb	2017-10-04 19:54:43.391840139 -0700
@@ -29,7 +29,7 @@
   require 'locale'
 
   # e.g. ~/code/puppet/locales. Also when running as a gem.
-  local_locale_path = File.absolute_path('../locales', File.dirname(__FILE__))
+  local_locale_path = File.absolute_path('/var/puppet/share/locales', File.dirname(__FILE__))
   # e.g. /opt/puppetlabs/puppet/share/locale
   posix_system_locale_path = File.absolute_path('../../../share/locale', File.dirname(__FILE__))
   # e.g. C:\Program Files\Puppet Labs\Puppet\puppet\share\locale
