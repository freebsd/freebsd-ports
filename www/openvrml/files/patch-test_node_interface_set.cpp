--- tests/node_interface_set.cpp.orig	Sun Jul  8 23:24:35 2007
+++ tests/node_interface_set.cpp	Sun Jul  8 23:23:24 2007
@@ -1,3 +1,5 @@
+# define BOOST_TEST_DYN_LINK
+# define BOOST_TEST_MAIN
 # include <boost/test/unit_test.hpp>
 # include <openvrml/node.h>
 
