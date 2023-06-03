--- ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/datadog/grok/src/matchers/date.rs.orig	2022-12-23 22:03:04 UTC
+++ ../vector-859fe61141808d245d3cc8077027ad79d842416c/lib/datadog/grok/src/matchers/date.rs
@@ -103,7 +103,7 @@ pub struct RegexResult {
 
 pub fn parse_timezone(tz: &str) -> Result<FixedOffset, String> {
     let tz = match tz {
-        "GMT" | "UTC" | "UT" | "Z" => FixedOffset::east(0),
+        "GMT" | "UTC" | "UT" | "Z" => FixedOffset::east_opt(0).unwrap(),
         _ if tz.starts_with('+') || tz.starts_with('-') => parse_offset(tz)?,
         _ if tz.contains('+') => parse_offset(&tz[tz.find('+').unwrap()..])?,
         _ if tz.contains('-') => parse_offset(&tz[tz.find('-').unwrap()..])?,
@@ -121,7 +121,7 @@ fn parse_offset(tz: &str) -> Result<FixedOffset, Strin
     if tz.len() <= 3 {
         // +5, -12
         let hours_diff = tz.parse::<i32>().map_err(|e| e.to_string())?;
-        return Ok(FixedOffset::east(hours_diff * 3600));
+        return Ok(FixedOffset::east_opt(hours_diff * 3600).unwrap());
     }
     let offset_format = if tz.contains(':') { "%:z" } else { "%z" };
     // apparently the easiest way to parse tz offset is parsing the complete datetime
@@ -315,7 +315,7 @@ pub fn apply_date_filter(value: &Value, filter: &DateF
                         }
                     } else if let Ok(nt) = NaiveTime::parse_from_str(&value, &filter.strp_format) {
                         // try parsing as a naive time
-                        Ok(NaiveDateTime::new(NaiveDate::from_ymd(1970, 1, 1), nt)
+                        Ok(NaiveDateTime::new(NaiveDate::from_ymd_opt(1970, 1, 1).unwrap(), nt)
                             .timestamp_millis()
                             .into())
                     } else {
@@ -332,7 +332,7 @@ pub fn apply_date_filter(value: &Value, filter: &DateF
                         Ok(UTC
                             .from_local_datetime(&NaiveDateTime::new(
                                 nd,
-                                NaiveTime::from_hms(0, 0, 0),
+                                NaiveTime::from_hms_opt(0, 0, 0).unwrap(),
                             ))
                             .single()
                             .ok_or_else(|| {
