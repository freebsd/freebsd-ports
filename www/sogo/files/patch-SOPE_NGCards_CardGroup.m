--- SOPE/NGCards/CardGroup.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/CardGroup.m
@@ -409,7 +409,7 @@ static NGCardsSaxHandler *sax = nil;
   max = [children count];
   if (max > 0)
     {
-      [str appendFormat: @"\n  %d children: {\n", [children count]];
+      [str appendFormat: @"\n  %d children: {\n", (int)[children count]];
       for (count = 0; count < max; count++)
         [str appendFormat: @"  %@\n",
              [[children objectAtIndex: count] description]];
