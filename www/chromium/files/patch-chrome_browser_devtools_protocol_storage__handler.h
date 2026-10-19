--- chrome/browser/devtools/protocol/storage_handler.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/devtools/protocol/storage_handler.h
@@ -5,22 +5,15 @@
 #ifndef CHROME_BROWSER_DEVTOOLS_PROTOCOL_STORAGE_HANDLER_H_
 #define CHROME_BROWSER_DEVTOOLS_PROTOCOL_STORAGE_HANDLER_H_
 
-#include <memory>
-#include <string>
-#include <vector>
-
 #include "base/memory/weak_ptr.h"
-#include "base/scoped_observation.h"
 #include "chrome/browser/devtools/protocol/protocol.h"
 #include "chrome/browser/devtools/protocol/storage.h"
-#include "chrome/browser/private_verification_tokens/private_verification_tokens_service.h"
 
 namespace content {
 class WebContents;
 }  // namespace content
 
-class StorageHandler : public protocol::Storage::Backend,
-                       public PrivateVerificationTokensService::Observer {
+class StorageHandler : public protocol::Storage::Backend {
  public:
   StorageHandler(content::WebContents* web_contents,
                  protocol::UberDispatcher* dispatcher);
@@ -31,41 +24,14 @@ class StorageHandler : public protocol::Storage::Backe
   ~StorageHandler() override;
 
  private:
-  protocol::Response Disable() override;
-
   void RunBounceTrackingMitigations(
       std::unique_ptr<RunBounceTrackingMitigationsCallback> callback) override;
 
-  void GetPrivateVerificationTokens(
-      std::unique_ptr<GetPrivateVerificationTokensCallback> callback) override;
-  protocol::Response GetPrivateVerificationTokensIssuerConfigs(
-      std::unique_ptr<protocol::Array<
-          protocol::Storage::PrivateVerificationTokensIssuerConfig>>*
-          out_configs) override;
-  void ClearPrivateVerificationTokens(
-      const std::string& in_issuerOrigin,
-      std::unique_ptr<ClearPrivateVerificationTokensCallback> callback)
-      override;
-  void DeletePrivateVerificationToken(
-      const std::string& in_tokenId,
-      std::unique_ptr<DeletePrivateVerificationTokenCallback> callback)
-      override;
-  protocol::Response SetPrivateVerificationTokensTracking(bool enable) override;
-
-  // PrivateVerificationTokensService::Observer:
-  void OnTokensStored() override;
-  void OnTokensDeleted() override;
-  void OnShutdown() override;
-
   static void GotDeletedSites(
       std::unique_ptr<RunBounceTrackingMitigationsCallback> callback,
       const std::vector<std::string>& sites);
 
   base::WeakPtr<content::WebContents> web_contents_;
-  std::unique_ptr<protocol::Storage::Frontend> frontend_;
-  base::ScopedObservation<PrivateVerificationTokensService,
-                          PrivateVerificationTokensService::Observer>
-      pvt_observation_{this};
 };
 
 #endif  // CHROME_BROWSER_DEVTOOLS_PROTOCOL_STORAGE_HANDLER_H_
