--- UI/PreferencesUI/UIxPreferences.m.orig	2015-09-16 18:41:36 UTC
+++ UI/PreferencesUI/UIxPreferences.m
@@ -1366,15 +1366,15 @@ static NSArray *reminderValues = nil;
           if ([account updateFilters])
             // If Sieve is not enabled, the SOGoSieveManager will immediatly return a positive answer
             // See [SOGoSieveManager updateFiltersForAccount:withUsername:andPassword:]
-            results = [self responseWithStatus: 200
+            results = (id <WOActionResults>)[self responseWithStatus: 200
                          andJSONRepresentation: [NSDictionary dictionaryWithObjectsAndKeys: [NSNumber numberWithBool:hasChanged], @"hasChanged", nil]];
 
           else
-            results = [self responseWithStatus: 502
+            results = (id <WOActionResults>)[self responseWithStatus: 502
                          andJSONRepresentation: [NSDictionary dictionaryWithObjectsAndKeys: @"Connection error", @"textStatus", nil]];
         }
       else
-        results = [self responseWithStatus: 503
+        results = (id <WOActionResults>)[self responseWithStatus: 503
                      andJSONRepresentation: [NSDictionary dictionaryWithObjectsAndKeys: @"Service temporarily unavailable", @"textStatus", nil]];
     }
   else
