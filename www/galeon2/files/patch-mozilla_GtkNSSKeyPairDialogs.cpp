--- mozilla/GtkNSSKeyPairDialogs.cpp.orig	Sun Jun 27 20:41:07 2004
+++ mozilla/GtkNSSKeyPairDialogs.cpp	Sun Jun 27 20:47:09 2004
@@ -84,7 +84,7 @@
 	NS_DECL_ISUPPORTS
 	NS_DECL_NSIDOMWINDOWINTERNAL
 	NS_DECL_NSIDOMWINDOW
-#if MOZILLA_SNAPSHOT > 17
+#if MOZILLA_SNAPSHOT > 15
 	NS_DECL_NSIDOMWINDOW2
 #endif
 
@@ -94,7 +94,7 @@
 	gboolean close_called;
 };
 
-#if MOZILLA_SNAPSHOT > 17
+#if MOZILLA_SNAPSHOT > 15
 NS_IMPL_ISUPPORTS3(KeyPairHelperWindow, nsIDOMWindowInternal, nsIDOMWindow, nsIDOMWindow2)
 #else
 NS_IMPL_ISUPPORTS2(KeyPairHelperWindow, nsIDOMWindowInternal, nsIDOMWindow)
@@ -242,7 +242,7 @@
     MOZ_NOT_IMPLEMENTED
 }
 
-#if MOZILLA_SNAPSHOT > 17
+#if MOZILLA_SNAPSHOT > 15
 NS_IMETHODIMP KeyPairHelperWindow::GetWindowRoot(nsIDOMEventTarget * *aEvent)
 {
     MOZ_NOT_IMPLEMENTED
