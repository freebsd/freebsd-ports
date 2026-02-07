FreeBSD 14 and earlier do not support timezone with POSIX semantics.
We work around this shortcoming by skipping the timezone check,
setting the TZ variable unconditionally.
This patch can be removed once FreeBSD 14 goes out of support.

--- linphone-app/src/app/App.cpp.orig	2026-02-03 10:42:50 UTC
+++ linphone-app/src/app/App.cpp
@@ -295,13 +295,10 @@ App::App(int &argc, char *argv[])
 #else
 	char *tz = getenv("TZ");
 	if (!tz) {   // If not set, set the environment variable for uses of mktime from the SDK.
-		tzset(); // init timezone variable
-		if (timezone != -QTimeZone::systemTimeZone().offsetFromUtc(QDateTime::currentDateTime())) {
 			QString timeZone = QTimeZone::systemTimeZoneId();
 			setenv("TZ", timeZone.toStdString().c_str(), 1);
 			tzset();
 			qInfo() << "Set TimeZone to " << timeZone;
-		}
 	} else qInfo() << "Use environment TimeZone:" << tz;
 #endif
 
