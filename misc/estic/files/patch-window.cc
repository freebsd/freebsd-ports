--- spunk/window.cc.orig	1997-01-26 17:17:38 UTC
+++ spunk/window.cc
@@ -1432,7 +1432,7 @@ void Window::Write (int X, int Y, const 
 // Write a string to the inner window. Note: Attr is an index, not a real
 // attribute !
 {
-    const BufSize = 256;
+    const int BufSize = 256;
     u16 Buf [256];
 
     // Check if the given string is empty
@@ -1554,7 +1554,7 @@ void Window::CWrite (int X, int Y, const
 // Write a string to the inner window. Note: Attr is an index, not a real
 // attribute !
 {
-    const BufSize = 256;
+    const int BufSize = 256;
     u16 Buf [BufSize];
 
     // If the Y coord is outside the inner window, there is nothing to do
