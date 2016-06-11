--- modules/gui/qt4/dialogs/messages.hpp.orig	2014-08-14 07:20:04 UTC
+++ modules/gui/qt4/dialogs/messages.hpp
@@ -55,7 +55,7 @@ private:
     void sinkMessage( const MsgEvent * );
     bool matchFilter( const QString& );
 
-    atomic_uint verbosity;
+    atomic_int verbosity;
     static void MsgCallback( void *, int, const vlc_log_t *, const char *,
                              va_list );
 
