--- molsketch/programversion.cpp.orig	2018-10-24 03:35:50 UTC
+++ molsketch/programversion.cpp
@@ -88,10 +88,10 @@ QString ProgramVersion::toString() const
   return QString("%1.%2.%3.%4").arg(d->major).arg(d->minor).arg(d->patch).arg(d->build);
 }
 
-unsigned int ProgramVersion::minor() const {
+unsigned int ProgramVersion::minorx() const {
   return d->minor;
 }
 
-unsigned int ProgramVersion::major() const {
+unsigned int ProgramVersion::majorx() const {
   return d->major;
 }
