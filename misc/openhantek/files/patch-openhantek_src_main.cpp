--- openhantek/src/main.cpp.orig	2020-07-01 17:59:30 UTC
+++ openhantek/src/main.cpp
@@ -163,8 +163,10 @@ int main( int argc, char *argv[] ) {
             SelectSupportedDevice().showLibUSBFailedDialogModel( error );
             return -1;
         }
+#if !defined(__FreeBSD__) // see https://github.com/OpenHantek/OpenHantek6022/issues/101
         if ( useLocale ) // localize USB error messages, supported: "en", "nl", "fr", "ru"
             libusb_setlocale( QLocale::system().name().toLocal8Bit().constData() );
+#endif
 
         // SelectSupportedDevive returns a real device unless demoMode is true
         scopeDevice = SelectSupportedDevice().showSelectDeviceModal( context );
