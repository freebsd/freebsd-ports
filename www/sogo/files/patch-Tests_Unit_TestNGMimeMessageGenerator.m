--- Tests/Unit/TestNGMimeMessageGenerator.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/TestNGMimeMessageGenerator.m
@@ -117,7 +117,7 @@
       NSString *diff = [self stringFromDiffBetween: [NSString stringWithString: resultString]
                                                and: [NSString stringWithString: expected]];
       NSString *testErrorMsg = [NSString
-                             stringWithFormat: @">> For %@ header received:\n%@[END]\n>> instead of:\n%@[END]\n>> for:\n%@\n>> diff:\n%@\n>> lengthReceived: %u lengthExpected: %u",
+                             stringWithFormat: @">> For %@ header received:\n%@[END]\n>> instead of:\n%@[END]\n>> for:\n%@\n>> diff:\n%@\n>> lengthReceived: %lu lengthExpected: %lu",
                               header,
                               resultString,
                               expected,
