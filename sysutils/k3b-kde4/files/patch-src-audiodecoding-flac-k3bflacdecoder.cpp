--- src/audiodecoding/flac/k3bflacdecoder.cpp.orig	Tue Feb 24 16:07:27 2004
+++ src/audiodecoding/flac/k3bflacdecoder.cpp	Tue Mar 22 22:08:07 2005
@@ -308,7 +308,7 @@
 {
   if( d->comments != 0 ) {
     if( info == i18n("Vendor") )
-      return QString::fromUtf8(d->comments->get_vendor_string().get_field());
+      return QString::fromUtf8((char*)d->comments->get_vendor_string());
     else if( info == i18n("Channels") )
       return QString::number(d->channels);
     else if( info == i18n("Sampling Rate") )
