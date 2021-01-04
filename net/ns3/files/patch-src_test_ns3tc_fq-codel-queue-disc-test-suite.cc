--- src/test/ns3tc/fq-codel-queue-disc-test-suite.cc.orig	2021-01-04 15:32:24 UTC
+++ src/test/ns3tc/fq-codel-queue-disc-test-suite.cc
@@ -35,6 +35,8 @@
 #include "ns3/string.h"
 #include "ns3/pointer.h"
 
+#include <sys/types.h>
+
 using namespace ns3;
 
 // Variable to assign hash to a new packet's flow
@@ -1125,4 +1127,4 @@ FqCoDelQueueDiscTestSuite::FqCoDelQueueDiscTestSuite (
   AddTestCase (new FqCoDelQueueDiscL4sMode, TestCase::QUICK);
 }
 
-static FqCoDelQueueDiscTestSuite fqCoDelQueueDiscTestSuite;
\ No newline at end of file
+static FqCoDelQueueDiscTestSuite fqCoDelQueueDiscTestSuite;
