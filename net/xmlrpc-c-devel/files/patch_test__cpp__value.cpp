--- test/cpp/value.cpp.orig	2012-12-17 11:36:32.000000000 -0200
+++ test/cpp/value.cpp	2012-12-17 11:36:53.000000000 -0200
@@ -235,7 +235,7 @@
         TEST(iso8601Value == testTime8601);
 
         try {
-            value_datetime datetime4(value_int(4));
+            value_datetime second_datetime4(value_int(4));
             TEST_FAILED("invalid cast int-datetime suceeded");
         } catch (error const&) {}
     }
