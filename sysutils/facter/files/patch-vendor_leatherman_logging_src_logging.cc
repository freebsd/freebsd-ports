(LTH-115) Fix Boost.Log sink initialization with Boost 1.62

In Boost 1.62, the way sink argument forwarding appears to have changed
in such a way that it failed to identify the implicit creation of a
color_writer. Switch to explicitly creating the color_writer sink.

https://github.com/puppetlabs/leatherman/commit/e8196d55ecac7f2bf3aa5cb0aefef0122e63db21

--- vendor/leatherman/logging/src/logging.cc.orig	2015-11-25 00:14:00 UTC
+++ vendor/leatherman/logging/src/logging.cc
@@ -72,7 +72,7 @@ namespace leatherman { namespace logging
         core->remove_all_sinks();
 
         using sink_t = sinks::synchronous_sink<color_writer>;
-        boost::shared_ptr<sink_t> sink(new sink_t(&dst));
+        boost::shared_ptr<sink_t> sink = boost::make_shared<sink_t>(boost::make_shared<color_writer>(&dst));
         core->add_sink(sink);
 
 #if (!defined(__sun) && !defined(_AIX)) || !defined(__GNUC__)
