--- gtk/GtkToggleButton.chs.orig	Tue Feb 24 16:14:57 2004
+++ gtk/GtkToggleButton.chs	Tue Feb 24 16:15:57 2004
@@ -40,6 +40,7 @@

 import C2HS

+import Bits
 import Monad            (liftM)

 {#import GtkObject#}    (ObjectClass(..), Object(..))
