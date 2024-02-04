--- chrome/browser/ui/tabs/organization/trigger_observer.h.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/ui/tabs/organization/trigger_observer.h
@@ -6,6 +6,7 @@
 #define CHROME_BROWSER_UI_TABS_ORGANIZATION_TRIGGER_OBSERVER_H_
 
 #include <memory>
+#include <unordered_map>
 
 #include "base/functional/callback.h"
 #include "chrome/browser/ui/browser_list_observer.h"
