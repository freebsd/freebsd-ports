--- Tests/Unit/TestVersit.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/TestVersit.m
@@ -34,6 +34,10 @@
 
 - (void) test_rendering
 {
+
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wobjc-string-compare"
+
   CardElement *element;
   CardVersitRenderer *renderer;
   NSString *result;
@@ -137,10 +141,17 @@
   testEquals(result, @"ELEM:NONEMPTY=coucou\r\n");
 
   /** tests about parameters handling could be nice */
+
+#pragma clang diagnostic pop
+
 }
 
 - (void) test_parsing
 {
+
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wobjc-string-compare"
+
   CardGroup *group;
   CardElement *element;
   NSString *versit;
@@ -201,6 +212,9 @@
   element = [group firstChildWithTag: @"element"];
   testEquals([element flattenedValueAtIndex: 0 forKey: @""], @"value");
   testEquals([element value: 0 ofAttribute: @"param1"], @"paramvalue1, with comma");
+
+#pragma clang diagnostic pop
+
 }
 
 @end
