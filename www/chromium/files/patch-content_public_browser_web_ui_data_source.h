--- content/public/browser/web_ui_data_source.h.orig	2019-01-09 12:09:09.754984000 +0100
+++ content/public/browser/web_ui_data_source.h	2019-01-09 12:14:15.249680000 +0100
@@ -13,7 +13,6 @@
 
 #include "base/callback.h"
 #include "base/strings/string16.h"
-#include "base/strings/string_piece.h"
 #include "content/common/content_export.h"
 
 namespace base {
@@ -45,33 +44,33 @@
       std::unique_ptr<base::DictionaryValue> update);
 
   // Adds a string keyed to its name to our dictionary.
-  virtual void AddString(base::StringPiece name,
+  virtual void AddString(const std::string& name,
                          const base::string16& value) = 0;
 
   // Adds a string keyed to its name to our dictionary.
-  virtual void AddString(base::StringPiece name, const std::string& value) = 0;
+  virtual void AddString(const std::string& name, const std::string& value) = 0;
 
   // Adds a localized string with resource |ids| keyed to its name to our
   // dictionary.
-  virtual void AddLocalizedString(base::StringPiece name, int ids) = 0;
+  virtual void AddLocalizedString(const std::string& name, int ids) = 0;
 
   // Add strings from |localized_strings| to our dictionary.
   virtual void AddLocalizedStrings(
       const base::DictionaryValue& localized_strings) = 0;
 
   // Adds a boolean keyed to its name to our dictionary.
-  virtual void AddBoolean(base::StringPiece name, bool value) = 0;
+  virtual void AddBoolean(const std::string& name, bool value) = 0;
 
   // Adds a signed 32-bit integer keyed to its name to our dictionary. Larger
   // integers may not be exactly representable in JavaScript. See
   // MAX_SAFE_INTEGER in /v8/src/globals.h.
-  virtual void AddInteger(base::StringPiece name, int32_t value) = 0;
+  virtual void AddInteger(const std::string& name, int32_t value) = 0;
 
   // Sets the path which will return the JSON strings.
-  virtual void SetJsonPath(base::StringPiece path) = 0;
+  virtual void SetJsonPath(const std::string& path) = 0;
 
   // Adds a mapping between a path name and a resource to return.
-  virtual void AddResourcePath(base::StringPiece path, int resource_id) = 0;
+  virtual void AddResourcePath(const std::string& path, int resource_id) = 0;
 
   // Sets the resource to returned when no other paths match.
   virtual void SetDefaultResource(int resource_id) = 0;
