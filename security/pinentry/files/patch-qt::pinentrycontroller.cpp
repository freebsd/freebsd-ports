--- qt/pinentrycontroller.cpp.orig	Thu Feb 13 00:20:44 2003
+++ qt/pinentrycontroller.cpp	Thu Feb 13 00:21:32 2003
@@ -256,9 +256,8 @@
   connect( _pinentry, SIGNAL( rejected() ),
 	   this, SLOT( slotRejected() ) );
   bool ret = _pinentry->exec();  
-  FILE* fp = assuan_get_data_fp( _ctx );
   if( ret ) {
-    fputs( static_cast<const char*>(_pinentry->text().utf8()), fp );
+    assuan_send_data ( _ctx, static_cast<const void*>(_pinentry->text().utf8()), _pinentry->text().utf8().length() );
     return 0;
   } else {
     assuan_set_error( _ctx, ASSUAN_Canceled, "Dialog cancelled by user" );
