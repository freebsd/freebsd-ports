https://github.com/cmdrkotori/mpc-qt/issues/46

helpers.cpp:704:37: error: unknown type name 'Int'; did you mean 'int'?
    int btn = std::log2(mb.operator Int()) + 2.5; // 1->0+2, 2->1+2, 4->2+2 etc.
                                    ^~~
                                    int
helpers.cpp:704:28: error: no member named 'operator int' in 'QFlags<Qt::MouseButton>'
    int btn = std::log2(mb.operator Int()) + 2.5; // 1->0+2, 2->1+2, 4->2+2 etc.
                        ~~ ^

--- helpers.cpp.orig	2016-09-21 11:55:18 UTC
+++ helpers.cpp
@@ -701,7 +701,7 @@ MouseState MouseState::fromMouseEvent(QM
     Qt::MouseButtons mb = event->button();
     if (mb == Qt::NoButton)
         return MouseState();
-    int btn = std::log2(mb.operator Int()) + 2.5; // 1->0+2, 2->1+2, 4->2+2 etc.
+    int btn = std::log2(int(mb)) + 2.5; // 1->0+2, 2->1+2, 4->2+2 etc.
     return MouseState(btn, (event->modifiers() >> 25)&15, press);
 }
 
