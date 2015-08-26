--- Main.hs.orig	2013-02-12 19:23:46 UTC
+++ Main.hs
@@ -28,8 +28,7 @@ import System.Directory (doesFileExist)
 import Control.Concurrent (threadDelay)
 import Control.Monad (when)
 import Control.Applicative ((<|>))
-import System.Locale (defaultTimeLocale)
-import Data.Time (getCurrentTime, formatTime, diffUTCTime)
+import Data.Time (getCurrentTime, formatTime, diffUTCTime, defaultTimeLocale)
 import Data.Maybe (listToMaybe)
 --import Prelude hiding (catch)
 
