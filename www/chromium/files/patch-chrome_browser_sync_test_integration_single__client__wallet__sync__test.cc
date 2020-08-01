--- chrome/browser/sync/test/integration/single_client_wallet_sync_test.cc.orig	2020-07-13 09:22:37 UTC
+++ chrome/browser/sync/test/integration/single_client_wallet_sync_test.cc
@@ -814,7 +814,7 @@ IN_PROC_BROWSER_TEST_F(SingleClientWalletSyncTest, Cha
 IN_PROC_BROWSER_TEST_F(SingleClientWalletSyncTest,
                        SameUpdatesAreIgnoredWhenLocalCardsUnmasked) {
 // We need to allow storing full server cards for this test to work properly.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   base::CommandLine::ForCurrentProcess()->AppendSwitch(
       autofill::switches::kEnableOfferStoreUnmaskedWalletCards);
 #endif
