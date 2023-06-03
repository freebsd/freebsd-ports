--- ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/value/src/value/arbitrary.rs.orig	2022-12-23 22:03:04 UTC
+++ ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/value/src/value/arbitrary.rs
@@ -17,7 +17,7 @@ fn datetime(g: &mut Gen) -> DateTime<Utc> {
     // are. We just sort of arbitrarily restrict things.
     let secs = i64::arbitrary(g) % 32_000;
     let nanosecs = u32::arbitrary(g) % 32_000;
-    DateTime::<Utc>::from_utc(NaiveDateTime::from_timestamp(secs, nanosecs), Utc)
+    DateTime::<Utc>::from_utc(NaiveDateTime::from_timestamp_opt(secs, nanosecs).unwrap(), Utc)
 }
 
 impl Arbitrary for Value {
