--- pv/data/signaldata.cpp.orig	2014-05-06 21:43:51 UTC
+++ pv/data/signaldata.cpp
@@ -29,6 +29,10 @@ SignalData::SignalData() :
 {
 }
 
+SignalData::~SignalData()
+{
+}
+
 double SignalData::samplerate() const
 {
 	return _samplerate;
