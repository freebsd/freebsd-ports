--- pv/data/signaldata.h.orig	2014-05-06 21:43:51 UTC
+++ pv/data/signaldata.h
@@ -30,6 +30,7 @@ class SignalData
 {
 public:
 	SignalData();
+	virtual ~SignalData();
 
 public:
 	double samplerate() const;
