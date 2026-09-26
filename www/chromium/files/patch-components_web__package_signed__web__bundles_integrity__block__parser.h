--- components/web_package/signed_web_bundles/integrity_block_parser.h.orig	2026-09-25 15:26:43 UTC
+++ components/web_package/signed_web_bundles/integrity_block_parser.h
@@ -5,13 +5,8 @@
 #ifndef COMPONENTS_WEB_PACKAGE_SIGNED_WEB_BUNDLES_INTEGRITY_BLOCK_PARSER_H_
 #define COMPONENTS_WEB_PACKAGE_SIGNED_WEB_BUNDLES_INTEGRITY_BLOCK_PARSER_H_
 
-#include <optional>
-#include <string>
-
-#include "base/compiler_specific.h"
-#include "base/memory/raw_ref.h"
-#include "base/memory/weak_ptr.h"
 #include "components/web_package/mojom/web_bundle_parser.mojom-forward.h"
+#include "components/web_package/signed_web_bundles/integrity_block_attributes.h"
 #include "components/web_package/signed_web_bundles/types.h"
 #include "components/web_package/web_bundle_parser.h"
 
@@ -20,7 +15,7 @@ namespace web_package {
 class IntegrityBlockParser : public WebBundleParser::WebBundleSectionParser {
  public:
   explicit IntegrityBlockParser(
-      mojom::BundleDataSource& data_source LIFETIME_BOUND,
+      mojom::BundleDataSource& data_source,
       WebBundleParser::ParseIntegrityBlockCallback callback);
 
   IntegrityBlockParser(const IntegrityBlockParser&) = delete;
@@ -35,7 +30,10 @@ class IntegrityBlockParser : public WebBundleParser::W
  private:
   void OnIntegrityBlockRead(const std::optional<BinaryData>& data);
 
-  void RunErrorCallback(std::string message,
+  base::expected<mojom::BundleIntegrityBlockSignatureStackEntryPtr, std::string>
+  ParseSignatureInfo(const cbor::Value& attributes_map);
+
+  void RunErrorCallback(const std::string& message,
                         mojom::BundleParseErrorType error_type =
                             mojom::BundleParseErrorType::kFormatError);
 
