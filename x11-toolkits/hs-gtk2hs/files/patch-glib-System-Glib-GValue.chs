--- glib/System/Glib/GValue.chs.orig	2005-04-18 22:04:08.000000000 -0400
+++ glib/System/Glib/GValue.chs	2006-03-05 14:53:20.000000000 -0400
@@ -68,7 +68,7 @@ valueGetType (GValue gvPtr) = {# get GVa
 --
 allocaGValue :: (GValue -> IO b) -> IO b
 allocaGValue body =
-  allocaBytes {# sizeof GValue #} $ \gvPtr -> do
+  allocaBytes ({# sizeof GType #}+ 2* {# sizeof guint64 #}) $ \gvPtr -> do
   -- The g_type field of the value must be zero or g_value_init will fail.
   {# set GValue->g_type #} gvPtr (0 :: GType)
   result <- body (GValue gvPtr)
