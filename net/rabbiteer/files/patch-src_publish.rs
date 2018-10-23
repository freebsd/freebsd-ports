--- src/publish.rs.orig	2018-10-14 20:00:28 UTC
+++ src/publish.rs
@@ -1,41 +1,38 @@
-use std::io::{self, Write};
 use amqp;
-use amqp::protocol::basic::{Deliver, BasicProperties};
+use amqp::protocol::basic::{BasicProperties, Deliver};
+use amqp::Channel;
 use clap::ArgMatches;
-use std::fs;
-use std::path::Path;
-use mime;
 use client;
 use error::RbtError;
+use mime;
 use output;
-use amqp::{Channel};
+use std::fs;
+use std::io::{self, Write};
 use std::panic;
+use std::path::Path;
 
-
 // helper function to turn a filename
 // into a mime-type
-fn type_from_file(file:&String) -> Result<String,RbtError> {
+fn type_from_file(file: &String) -> Result<String, RbtError> {
     let t = mime::Types::new().or(Err("Failed to read mime types"))?;
     let path = Path::new(&file);
     let mime = t.mime_for_path(&path);
     Ok(mime.to_owned())
 }
 
-
-pub fn do_publish(opts:amqp::Options, matches:&ArgMatches) -> Result<(),RbtError> {
-
+pub fn do_publish(opts: amqp::Options, matches: &ArgMatches) -> Result<(), RbtError> {
     // either stdin or a file
     let file = value_t!(matches, "file", String)?;
-    let rpc  = matches.is_present("rpc");
+    let rpc = matches.is_present("rpc");
     let reader: Box<io::Read> = match file.as_ref() {
         "-" => Box::new(io::stdin()),
-        _   => Box::new(fs::File::open(&file)?),
+        _ => Box::new(fs::File::open(&file)?),
     };
 
     // either - or the name of the file
-    let file_name:&str = match file.as_ref() {
+    let file_name: &str = match file.as_ref() {
         "-" => "-",
-        _   => {
+        _ => {
             // XXX fix unwrapping
             let ostr = Path::new(&file).file_name().unwrap();
             ostr.to_str().unwrap()
@@ -48,51 +45,49 @@ pub fn do_publish(opts:amqp::Options, matches:&ArgMatc
         let c = matches.value_of("content_type").unwrap_or("-").to_string();
         match c.as_ref() {
             "-" => type_from_file(&file)?,
-            _   => c,
+            _ => c,
         }
     };
 
-
     // the sendable wraps up the parsed parts
     let sendable = client::Sendable {
-        exchange:     value_t!(matches, "exchange", String)?,
-        routing_key:  value_t!(matches, "routing_key", String)?,
+        exchange: value_t!(matches, "exchange", String)?,
+        routing_key: value_t!(matches, "routing_key", String)?,
         content_type: content_type,
-        headers:      values_t!(matches, "header", String).unwrap_or(vec![]),
-        file_name:    file_name.to_owned(),
-        reader:       reader,
-        priority:     value_t!(matches, "priority", u8).unwrap_or(0),
-        rpctimeout:   value_t!(matches, "rpctimeout", u64).unwrap_or(0)
+        headers: values_t!(matches, "header", String).unwrap_or(vec![]),
+        file_name: file_name.to_owned(),
+        reader: reader,
+        priority: value_t!(matches, "priority", u8).unwrap_or(0),
+        rpctimeout: value_t!(matches, "rpctimeout", u64).unwrap_or(0),
     };
 
     // if we are doing an rpc with replyTo/correlationId, we set up a receiver
     let rpc_receive = match rpc {
         false => None,
-        true  => {
-            let receive =
-                move |channel: &mut Channel, deliver:Deliver, props:BasicProperties, body:Vec<u8>| ->
-                Result<(),RbtError> {
-                    let msg = output::build_output(false, &deliver, &props, body)?;
+        true => {
+            let receive = move |channel: &mut Channel,
+                                deliver: Deliver,
+                                props: BasicProperties,
+                                body: Vec<u8>|
+                  -> Result<(), RbtError> {
+                let msg = output::build_output(false, &deliver, &props, body)?;
 
-                    // just write to stdout
-                    let stdout = io::stdout();
+                // just write to stdout
+                let stdout = io::stdout();
 
-                    // lock until end of scope
-                    let mut handle = stdout.lock();
+                // lock until end of scope
+                let mut handle = stdout.lock();
 
-                    handle.write(&msg)?;
-                    handle.write(b"\n")?;
-                    handle.flush()?;
-           
-                    // closing the channel
-                    channel.close(200, "Bye")?;
-                    panic::set_hook(Box::new(|_| {
-                    }));
-                    // Until amqp library finds a way to exit consumer, terminate consumer_thread here.
-                    panic!(); 
-                    
-    
-                };
+                handle.write(&msg)?;
+                handle.write(b"\n")?;
+                handle.flush()?;
+
+                // closing the channel
+                channel.close(200, "Bye")?;
+                panic::set_hook(Box::new(|_| {}));
+                // Until amqp library finds a way to exit consumer, terminate consumer_thread here.
+                panic!();
+            };
 
             let receiver = client::Receiver {
                 exchange: "".to_owned(),
