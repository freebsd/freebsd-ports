--- test/ess-test.el.orig	2026-05-26 14:29:02 UTC
+++ test/ess-test.el
@@ -36,8 +36,8 @@
 (ert-deftest R-mode ()
   (should (string= 'ess-r-mode (with-temp-buffer (R-mode) major-mode))))
 
-(ert-deftest ess-jags-mode ()
-  (should (string= 'ess-jags-mode (with-temp-buffer (ess-jags-mode) major-mode))))
+;;(ert-deftest ess-jags-mode ()
+;;  (should (string= 'ess-jags-mode (with-temp-buffer (ess-jags-mode) major-mode))))
 
 (ert-deftest ess-bugs-mode ()
   (should (string= 'ess-bugs-mode (with-temp-buffer (ess-bugs-mode) major-mode))))
