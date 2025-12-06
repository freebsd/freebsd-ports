--- components/autofill/core/browser/data_manager/payments/payments_data_manager.h.orig	2025-12-06 13:30:52 UTC
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.h
@@ -378,7 +378,7 @@ class PaymentsDataManager : public AutofillWebDataServ
 
   // TODO(crbug.com/430575808): Remove build flags.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Returns the value of the kAutofillHasSeenBnpl pref.
   virtual bool IsAutofillHasSeenBnplPrefEnabled() const;
 
@@ -726,7 +726,7 @@ class PaymentsDataManager : public AutofillWebDataServ
   void ClearAllCreditCardBenefits();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Monitors the `kAutofillBnplEnabled` preference for changes and controls the
   // clearing/loading of payment instruments accordingly. Will also log the
   // `Autofill.SettingsPage.BnplToggled` metric.
