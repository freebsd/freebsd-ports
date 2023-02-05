Reference:	https://github.com/ruby-concurrency/concurrent-ruby/pull/988
		https://github.com/ruby-concurrency/concurrent-ruby/issues/986
		https://github.com/puppetlabs/puppet/commit/9182bc3dd2576f409a6d01fb5c08d392670e90a2

--- lib/puppet/thread_local.rb.orig	2022-07-11 22:46:41 UTC
+++ lib/puppet/thread_local.rb
@@ -3,5 +3,5 @@ require 'concurrent'
 # We want to use the pure Ruby implementation even on JRuby. If we use the Java
 # implementation of ThreadLocal, we end up leaking references to JRuby instances
 # and preventing them from being garbage collected.
-class Puppet::ThreadLocal < Concurrent::RubyThreadLocalVar
+class Puppet::ThreadLocal < Concurrent::ThreadLocalVar
 end
