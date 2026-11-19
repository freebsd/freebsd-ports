--- java/org/cef/CefClient.java.orig	2026-09-08 14:07:06 UTC
+++ java/org/cef/CefClient.java
@@ -453,13 +453,22 @@ public class CefClient extends CefClientHandler
         return alreadyHandled;
     }
 
+    private final ThreadLocal<Boolean> inGotFocus_ = ThreadLocal.withInitial(() -> false);
+
     @Override
     public void onGotFocus(CefBrowser browser) {
         if (browser == null) return;
+       // Avoid infinite recursion
+        if (inGotFocus_.get()) return;
 
-        focusedBrowser_ = browser;
-        browser.setFocus(true);
-        if (focusHandler_ != null) focusHandler_.onGotFocus(browser);
+        inGotFocus_.set(true);
+        try {
+            focusedBrowser_ = browser;
+            browser.setFocus(true);
+            if (focusHandler_ != null) focusHandler_.onGotFocus(browser);
+        } finally {
+            inGotFocus_.set(false);
+        }
     }
 
     // CefJSDialogHandler
