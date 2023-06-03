--- ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/vector-common/src/datetime.rs.orig	2022-12-23 22:03:04 UTC
+++ ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/vector-common/src/datetime.rs
@@ -68,7 +68,7 @@ impl TimeZone {
 
 /// Convert a timestamp with a non-UTC time zone into UTC
 pub(super) fn datetime_to_utc<TZ: chrono::TimeZone>(ts: &DateTime<TZ>) -> DateTime<Utc> {
-    Utc.timestamp(ts.timestamp(), ts.timestamp_subsec_nanos())
+    Utc.timestamp_opt(ts.timestamp(), ts.timestamp_subsec_nanos()).unwrap()
 }
 
 impl From<TimeZone> for String {
