--- src/output.rs.orig	2018-10-14 20:00:28 UTC
+++ src/output.rs
@@ -1,10 +1,9 @@
-use rustc_serialize::json::{self, Json, Object};
-use rustc_serialize::base64::{self, ToBase64};
-use amqp::protocol::basic::{Deliver, BasicProperties};
+use amqp::protocol::basic::{BasicProperties, Deliver};
 use amqp::{Table, TableEntry};
 use error::RbtError;
+use rustc_serialize::base64::{self, ToBase64};
+use rustc_serialize::json::{self, Json, Object};
 
-
 #[derive(RustcEncodable)]
 struct MsgDeliver {
     consumer_tag: String,
@@ -27,24 +26,27 @@ struct Msg {
     data: Json,
 }
 
-pub fn build_output(info:bool, deliver:&Deliver,
-                    props:&BasicProperties, body:Vec<u8>) -> Result<Vec<u8>,RbtError> {
+pub fn build_output(
+    info: bool,
+    deliver: &Deliver,
+    props: &BasicProperties,
+    body: Vec<u8>,
+) -> Result<Vec<u8>, RbtError> {
     if info {
-
         // delivery info
         let mdel = MsgDeliver {
-            consumer_tag:deliver.consumer_tag.clone(),
-            delivery_tag:deliver.delivery_tag.clone(),
-            redelivered:deliver.redelivered.clone(),
-            exchange:deliver.exchange.clone(),
-            routing_key:deliver.routing_key.clone(),
+            consumer_tag: deliver.consumer_tag.clone(),
+            delivery_tag: deliver.delivery_tag.clone(),
+            redelivered: deliver.redelivered.clone(),
+            exchange: deliver.exchange.clone(),
+            routing_key: deliver.routing_key.clone(),
         };
 
         let content_type = props.content_type.clone().unwrap_or(String::from(""));
 
         // properties
         let mut mprops = MsgProps {
-            content_type:content_type.clone(),
+            content_type: content_type.clone(),
             headers: Object::new(),
         };
 
@@ -57,9 +59,9 @@ pub fn build_output(info:bool, deliver:&Deliver,
 
         // and put it together
         let msg = Msg {
-            deliver:mdel,
-            props:mprops,
-            data:data,
+            deliver: mdel,
+            props: mprops,
+            data: data,
         };
 
         // encode
@@ -67,9 +69,7 @@ pub fn build_output(info:bool, deliver:&Deliver,
 
         // convert to bytes
         Ok(js.to_string().as_bytes().to_owned())
-
     } else {
-
         let content_type = props.content_type.clone().unwrap_or(String::from(""));
 
         match content_type.as_ref() {
@@ -82,32 +82,26 @@ pub fn build_output(info:bool, deliver:&Deliver,
 
                 // convert to bytes
                 Ok(js.to_string().as_bytes().to_owned())
-            },
+            }
 
             // just return untranslated bytes
-            _ => Ok(body)
+            _ => Ok(body),
         }
-
     }
 }
 
-
-fn figure_out_body(content_type:String, body:Vec<u8>) -> Result<Json,RbtError> {
-
+fn figure_out_body(content_type: String, body: Vec<u8>) -> Result<Json, RbtError> {
     // depending on content type, do something
     match content_type.as_ref() {
         "application/json" => Ok(Json::from_str(&String::from_utf8(body)?)?),
         _ => Ok(match content_type.find("text/") {
             Some(_) => Json::String(String::from_utf8(body)?),
-            _ => Json::String(body.to_base64(base64::STANDARD))
-        })
+            _ => Json::String(body.to_base64(base64::STANDARD)),
+        }),
     }
-
 }
 
-
-
-fn table_to_json(table:&Table) -> Object {
+fn table_to_json(table: &Table) -> Object {
     let mut ret = Object::new();
     for (skey, entry) in table {
         ret.insert(skey.clone().to_string(), entry_to_json(&entry));
@@ -115,33 +109,35 @@ fn table_to_json(table:&Table) -> Object {
     ret
 }
 
-fn entry_to_json(entry:&TableEntry) -> Json {
+fn entry_to_json(entry: &TableEntry) -> Json {
     match *entry {
-        TableEntry::Bool(v)            => Json::Boolean(v),
-        TableEntry::ShortShortInt(v)   => Json::I64(v as i64),
-        TableEntry::ShortShortUint(v)  => Json::U64(v as u64),
-        TableEntry::ShortInt(v)        => Json::I64(v as i64),
-        TableEntry::ShortUint(v)       => Json::U64(v as u64),
-        TableEntry::LongInt(v)         => Json::I64(v as i64),
-        TableEntry::LongUint(v)        => Json::U64(v as u64),
-        TableEntry::LongLongInt(v)     => Json::I64(v),
-        TableEntry::LongLongUint(v)    => Json::U64(v),
-        TableEntry::Float(v)           => Json::F64(v as f64),
-        TableEntry::Double(v)          => Json::F64(v),
-        TableEntry::LongString(ref v)  => Json::String(v.clone()),
-        TableEntry::Void               => Json::Null,
-        TableEntry::FieldTable(ref v)  => Json::Object(table_to_json(&v)),
-        TableEntry::Timestamp(v)       => Json::U64(v as u64), // maybe string date?
+        TableEntry::Bool(v) => Json::Boolean(v),
+        TableEntry::ShortShortInt(v) => Json::I64(v as i64),
+        TableEntry::ShortShortUint(v) => Json::U64(v as u64),
+        TableEntry::ShortInt(v) => Json::I64(v as i64),
+        TableEntry::ShortUint(v) => Json::U64(v as u64),
+        TableEntry::LongInt(v) => Json::I64(v as i64),
+        TableEntry::LongUint(v) => Json::U64(v as u64),
+        TableEntry::LongLongInt(v) => Json::I64(v),
+        TableEntry::LongLongUint(v) => Json::U64(v),
+        TableEntry::Float(v) => Json::F64(v as f64),
+        TableEntry::Double(v) => Json::F64(v),
+        TableEntry::LongString(ref v) => Json::String(v.clone()),
+        TableEntry::Void => Json::Null,
+        TableEntry::FieldTable(ref v) => Json::Object(table_to_json(&v)),
+        TableEntry::Timestamp(v) => Json::U64(v as u64), // maybe string date?
         TableEntry::FieldArray(ref vs) => {
-            let mut ret:Vec<Json> = Vec::new();
-            for v in vs { ret.push(entry_to_json(v)) }
+            let mut ret: Vec<Json> = Vec::new();
+            for v in vs {
+                ret.push(entry_to_json(v))
+            }
             Json::Array(ret)
-        },
+        }
         TableEntry::DecimalValue(decimals, v) => {
-            let ten:f64 = (10 as u64).pow(decimals as u32) as f64;
-            let dec:f64 = (v as f64) / ten;
+            let ten: f64 = (10 as u64).pow(decimals as u32) as f64;
+            let dec: f64 = (v as f64) / ten;
             Json::F64(dec)
-        },
+        }
         //_                             => Err(format!("Cant translate {:?}", entry)),
         // TableEntry::ShortString(ref v) => Ok(Json::String(v.clone())),
     }
