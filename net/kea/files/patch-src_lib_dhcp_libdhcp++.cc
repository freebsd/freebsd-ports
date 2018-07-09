After https://github.com/boostorg/range/commit/69409ed63a9e1 build fails:

libdhcp++.cc:420:24: error: call to 'distance' is ambiguous
            num_defs = distance(range.first, range.second);
                       ^~~~~~~~
libdhcp++.cc:428:24: error: call to 'distance' is ambiguous
            num_defs = distance(range.first, range.second);
                       ^~~~~~~~
libdhcp++.cc:537:24: error: call to 'distance' is ambiguous
            num_defs = distance(range.first, range.second);
                       ^~~~~~~~
libdhcp++.cc:545:24: error: call to 'distance' is ambiguous
            num_defs = distance(range.first, range.second);
                       ^~~~~~~~
libdhcp++.cc:637:31: error: call to 'distance' is ambiguous
            size_t num_defs = distance(range.first, range.second);
                              ^~~~~~~~
libdhcp++.cc:743:35: error: call to 'distance' is ambiguous
                size_t num_defs = distance(range.first, range.second);
                                  ^~~~~~~~
/usr/include/c++/v1/iterator:511:1: note: candidate function [with _InputIter = boost::multi_index::detail::hashed_index_iterator<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::index_node_base<boost::shared_ptr<isc::dhcp::OptionDefinition>, std::__1::allocator<boost::shared_ptr<isc::dhcp::OptionDefinition> > >, boost::multi_index::detail::hashed_non_unique_tag>, boost::multi_index::detail::hashed_non_unique_tag>, boost::multi_index::detail::bucket_array<std::__1::allocator<boost::shared_ptr<isc::dhcp::OptionDefinition> > >, boost::multi_index::detail::hashed_index_global_iterator_tag>]
distance(_InputIter __first, _InputIter __last)
^
/usr/local/include/boost/iterator/distance.hpp:49:9: note: candidate function [with SinglePassIterator = boost::multi_index::detail::hashed_index_iterator<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::index_node_base<boost::shared_ptr<isc::dhcp::OptionDefinition>, std::__1::allocator<boost::shared_ptr<isc::dhcp::OptionDefinition> > >, boost::multi_index::detail::hashed_non_unique_tag>, boost::multi_index::detail::hashed_non_unique_tag>, boost::multi_index::detail::bucket_array<std::__1::allocator<boost::shared_ptr<isc::dhcp::OptionDefinition> > >, boost::multi_index::detail::hashed_index_global_iterator_tag>]
        distance(SinglePassIterator first, SinglePassIterator last)
        ^

--- src/lib/dhcp/libdhcp++.cc.orig	2017-10-05 13:00:05 UTC
+++ src/lib/dhcp/libdhcp++.cc
@@ -417,7 +417,7 @@ size_t LibDHCP::unpackOptions6(const OptionBuffer& buf
         size_t num_defs = 0;
         if (option_space == DHCP6_OPTION_SPACE) {
             range = idx.equal_range(opt_type);
-            num_defs = distance(range.first, range.second);
+            num_defs = std::distance(range.first, range.second);
         }
 
         // Standard option definitions do not include the definition for
@@ -425,7 +425,7 @@ size_t LibDHCP::unpackOptions6(const OptionBuffer& buf
         // find the definition among runtime option definitions.
         if (num_defs == 0) {
             range = runtime_idx.equal_range(opt_type);
-            num_defs = distance(range.first, range.second);
+            num_defs = std::distance(range.first, range.second);
         }
 
         OptionPtr opt;
@@ -534,7 +534,7 @@ size_t LibDHCP::unpackOptions4(const OptionBuffer& buf
         size_t num_defs = 0;
         if (option_space == DHCP4_OPTION_SPACE) {
             range = idx.equal_range(opt_type);
-            num_defs = distance(range.first, range.second);
+            num_defs = std::distance(range.first, range.second);
         }
 
         // Standard option definitions do not include the definition for
@@ -542,7 +542,7 @@ size_t LibDHCP::unpackOptions4(const OptionBuffer& buf
         // find the definition among runtime option definitions.
         if (num_defs == 0) {
             range = runtime_idx.equal_range(opt_type);
-            num_defs = distance(range.first, range.second);
+            num_defs = std::distance(range.first, range.second);
         }
 
         // Check if option unpacking must be deferred
@@ -634,7 +634,7 @@ size_t LibDHCP::unpackVendorOptions6(const uint32_t ve
                 idx->equal_range(opt_type);
             // Get the number of returned option definitions for the
             // option code.
-            size_t num_defs = distance(range.first, range.second);
+            size_t num_defs = std::distance(range.first, range.second);
 
             if (num_defs > 1) {
                 // Multiple options of the same code are not supported
@@ -740,7 +740,7 @@ size_t LibDHCP::unpackVendorOptions4(const uint32_t ve
                     idx->equal_range(opt_type);
                 // Get the number of returned option definitions for
                 // the option code.
-                size_t num_defs = distance(range.first, range.second);
+                size_t num_defs = std::distance(range.first, range.second);
 
                 if (num_defs > 1) {
                     // Multiple options of the same code are not
