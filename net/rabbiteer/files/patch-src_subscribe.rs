--- src/subscribe.rs.orig	2018-10-14 20:00:28 UTC
+++ src/subscribe.rs
@@ -1,23 +1,21 @@
-use std::io::{self, Write};
-use rand::{thread_rng, Rng, distributions::Alphanumeric};
-use amqp::protocol::basic::{Deliver, BasicProperties};
-use amqp::{self, TableEntry, Channel};
+use amqp::protocol::basic::{BasicProperties, Deliver};
+use amqp::{self, Channel, TableEntry};
 use clap::ArgMatches;
-use std::fs;
-use std::path::Path;
-use mime;
 use client;
-use output;
 use error::RbtError;
+use mime;
+use output;
+use rand::{distributions::Alphanumeric, thread_rng, Rng};
+use std::fs;
+use std::io::{self, Write};
 use std::panic;
+use std::path::Path;
 
-
-pub fn do_subscribe(opts:amqp::Options, matches:&ArgMatches) -> Result<(),RbtError> {
-
+pub fn do_subscribe(opts: amqp::Options, matches: &ArgMatches) -> Result<(), RbtError> {
     let output = value_t!(matches, "output", String)?;
-    let queue : Option<String> = matches.value_of("queue").map(str::to_owned);
-    let force_declare : bool = matches.is_present("declare");
-    let info   = matches.is_present("info");
+    let queue: Option<String> = matches.value_of("queue").map(str::to_owned);
+    let force_declare: bool = matches.is_present("declare");
+    let info = matches.is_present("info");
     let single = matches.is_present("single");
 
     // type lookup map
@@ -33,14 +31,15 @@ pub fn do_subscribe(opts:amqp::Options, matches:&ArgMa
         }
     }
 
-    let receive = move |channel: &mut Channel, deliver:Deliver, props:BasicProperties, body:Vec<u8>| ->
-        Result<(),RbtError> {
-
+    let receive = move |channel: &mut Channel,
+                        deliver: Deliver,
+                        props: BasicProperties,
+                        body: Vec<u8>|
+          -> Result<(), RbtError> {
         let msg = output::build_output(info, &deliver, &props, body)?;
 
         match output.as_ref() {
             "-" => {
-
                 // just write to stdout
                 let stdout = io::stdout();
 
@@ -50,10 +49,8 @@ pub fn do_subscribe(opts:amqp::Options, matches:&ArgMa
                 handle.write(&msg)?;
                 handle.write(b"\n")?;
                 handle.flush()?;
-
-            },
-            _   => {
-
+            }
+            _ => {
                 // extract file name from headers, or fall back on random
                 let file_name = file_name_of(&props, &types);
 
@@ -70,60 +67,60 @@ pub fn do_subscribe(opts:amqp::Options, matches:&ArgMa
 
                 let mut f = fs::File::create(path)?;
                 f.write_all(&msg)?;
-
             }
-
         }
 
         // maybe end here?
         if single {
             // closing the channel
             channel.close(200, "Bye")?;
-            panic::set_hook(Box::new(|_| {
-            }));
+            panic::set_hook(Box::new(|_| {}));
             // Until amqp library finds a way to exit consumer, terminate consumer_thread here.
             panic!();
         }
 
         Ok(())
-
     };
 
     let receiver = client::Receiver {
         exchange: value_t!(matches, "exchange", String)?,
         routing_key: matches.value_of("routing_key").map(str::to_owned),
-        auto_ack: ! matches.is_present("noack"),
+        auto_ack: !matches.is_present("noack"),
         callback: Box::new(receive),
     };
 
     client::open_receive(opts, queue, force_declare, receiver)
 }
 
-fn file_name_of(props:&BasicProperties, types:&mime::Types) -> String {
+fn file_name_of(props: &BasicProperties, types: &mime::Types) -> String {
+    let content_type = props
+        .content_type
+        .clone()
+        .unwrap_or("application/octet-stream".to_owned());
 
-    let content_type =
-        props.content_type.clone().unwrap_or("application/octet-stream".to_owned());
-
     // figure out a good extension for this content type
-    let ext = types.get_extension(&content_type)
+    let ext = types
+        .get_extension(&content_type)
         .and_then(|x| Some(x[0].clone()))
         .or_else(|| Some("bin".to_owned()))
         .unwrap();
 
     // prefer a fileName from headers, but fall back on
     // a random name.
-    props.headers.clone()
+    props
+        .headers
+        .clone()
         .and_then(|x| match x.get("fileName") {
             Some(&TableEntry::LongString(ref f)) => Some((*f).clone()),
-            _ => None
+            _ => None,
         })
         .or_else(|| Some(gen_rand_name(ext)))
         .unwrap()
 }
 
-fn gen_rand_name(ext:String) -> String {
+fn gen_rand_name(ext: String) -> String {
     // generate 16 ascii chars
-    let mut rand:String = thread_rng().sample_iter(&Alphanumeric).take(16).collect();
+    let mut rand: String = thread_rng().sample_iter(&Alphanumeric).take(16).collect();
     rand.push_str(".");
     rand.push_str(&ext);
     rand
