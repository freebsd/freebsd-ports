--- glib/GTypes.chs.orig	Tue Feb 24 15:11:38 2004
+++ glib/GTypes.chs	Tue Feb 24 15:33:34 2004
@@ -35,7 +35,7 @@

 import Prelude hiding (Char, Int, Float, Double)

-import C2HSDeprecated
+import C2HSDeprecated hiding (Int)

 {#context lib="libglib" prefix="g"#}

