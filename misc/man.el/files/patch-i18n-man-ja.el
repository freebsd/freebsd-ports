--- i18n-man-ja.el~	Tue Dec  8 01:48:18 1998
+++ i18n-man-ja.el	Tue Dec  8 01:48:48 1998
@@ -62,7 +62,6 @@
   "Hook for the Japanese manpage depend default coding system setting.
 Also save original values of variable to the local variable temporary."
   (setenv "LC_CTYPE" "ja_JP.EUC")
-  (setenv "MANPATH" (format "/usr/share/man/ja:" (getenv "MANPATH")))
   (if (featurep 'mule)
       (case emacs-major-version
 	(20 ;; XEmacs or Emacs-20.x (Mule-2.4, 3.0 or later)
