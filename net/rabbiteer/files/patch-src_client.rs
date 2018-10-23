--- src/client.rs.orig	2018-10-14 20:00:28 UTC
+++ src/client.rs
@@ -1,14 +1,14 @@
-use std::io;
-use error::RbtError;
-use amqp::{self, Session, Options, Channel};
-use amqp::protocol::basic::{Deliver, BasicProperties};
+use amqp::protocol::basic::{BasicProperties, Deliver};
 use amqp::Basic;
+use amqp::{self, Channel, Options, Session};
 use amqp::{Table, TableEntry};
+use error::RbtError;
+use std::io;
 
+use std::error::Error;
+use std::sync::mpsc;
 use std::thread;
 use std::time::Duration;
-use std::sync::mpsc;
-use std::error::Error;
 
 pub struct Sendable {
     pub exchange: String,
@@ -18,21 +18,20 @@ pub struct Sendable {
     pub file_name: String,
     pub reader: Box<io::Read>,
     pub priority: u8,
-    pub rpctimeout: u64
+    pub rpctimeout: u64,
 }
 
-pub type ReceiveCb = FnMut(&mut Channel, Deliver, BasicProperties, Vec<u8>) -> Result<(), RbtError> + Send;
+pub type ReceiveCb =
+    FnMut(&mut Channel, Deliver, BasicProperties, Vec<u8>) -> Result<(), RbtError> + Send;
 
 pub struct Receiver {
-    pub exchange:String,
+    pub exchange: String,
     pub routing_key: Option<String>,
     pub auto_ack: bool,
-    pub callback:Box<ReceiveCb>,
+    pub callback: Box<ReceiveCb>,
 }
 
-
-pub fn open_send(o:Options, s:Sendable, r:Option<Receiver>) -> Result<(),RbtError> {
-
+pub fn open_send(o: Options, s: Sendable, r: Option<Receiver>) -> Result<(), RbtError> {
     // open the channel
     let (mut session, mut channel) = _open(o)?;
 
@@ -49,7 +48,10 @@ pub fn open_send(o:Options, s:Sendable, r:Option<Recei
 
     // put filename in headers if we read from file
     if s.file_name != "-" && !headers.contains_key("fileName") {
-        headers.insert("fileName".to_owned(), TableEntry::LongString(String::from(s.file_name)));
+        headers.insert(
+            "fileName".to_owned(),
+            TableEntry::LongString(String::from(s.file_name)),
+        );
     }
 
     // send properties
@@ -73,8 +75,8 @@ pub fn open_send(o:Options, s:Sendable, r:Option<Recei
             props.correlation_id = Some("rabbiteer here".to_owned());
 
             true
-        },
-        None => false
+        }
+        None => false,
     };
 
     // read input input buffer
@@ -87,12 +89,14 @@ pub fn open_send(o:Options, s:Sendable, r:Option<Recei
 
     if isrpc {
         let (tx, rx) = mpsc::channel();
-        thread::Builder::new().name("consumer_thread".to_string()).spawn(move || {
-            channel.start_consuming();
-            tx.send(channel).unwrap();
-        }).unwrap();
+        thread::Builder::new()
+            .name("consumer_thread".to_string())
+            .spawn(move || {
+                channel.start_consuming();
+                tx.send(channel).unwrap();
+            })
+            .unwrap();
 
-
         let timeout = s.rpctimeout;
         if timeout == 0 {
             // Block forever until recieve
@@ -103,7 +107,7 @@ pub fn open_send(o:Options, s:Sendable, r:Option<Recei
             match res {
                 Ok(mut ch) => {
                     ch.close(200, "Bye")?;
-                }                  
+                }
                 Err(err) => {
                     if err.description() == "timed out waiting on channel".to_string() {
                         println!("Error timeout");
@@ -121,10 +125,9 @@ pub fn open_send(o:Options, s:Sendable, r:Option<Recei
     Ok(())
 }
 
-
 // narrow the string to a TableEntry type by trying to parse to known
 // JSON types: bool, double and fall back on string.
-fn narrow(str:&str) -> TableEntry {
+fn narrow(str: &str) -> TableEntry {
     let boolv = str.parse::<bool>();
     if !boolv.is_err() {
         TableEntry::Bool(boolv.unwrap())
@@ -138,19 +141,22 @@ fn narrow(str:&str) -> TableEntry {
     }
 }
 
-
-fn _open(o:Options) -> Result<(Session, Channel),RbtError> {
-//    errln!("Connecting to amqp://{}:{}@{}:{}/{}",
-//           o.login, o.password, o.host, o.port, o.vhost);
+fn _open(o: Options) -> Result<(Session, Channel), RbtError> {
+    //    errln!("Connecting to amqp://{}:{}@{}:{}/{}",
+    //           o.login, o.password, o.host, o.port, o.vhost);
     let mut session = Session::new(o)?;
     let channel = session.open_channel(1)?;
     Ok((session, channel))
 }
 
 impl amqp::Consumer for Receiver {
-    fn handle_delivery(&mut self, channel:&mut Channel, deliver:Deliver,
-                       headers:BasicProperties, body:Vec<u8>){
-
+    fn handle_delivery(
+        &mut self,
+        channel: &mut Channel,
+        deliver: Deliver,
+        headers: BasicProperties,
+        body: Vec<u8>,
+    ) {
         let delivery_tag = deliver.delivery_tag.clone();
 
         if self.auto_ack {
@@ -160,12 +166,15 @@ impl amqp::Consumer for Receiver {
 
         // and deliver to callback
         ((self.callback)(channel, deliver, headers, body)).unwrap_or_else(::error::handle);
-
     }
 }
 
-pub fn open_receive(o:Options, q:Option<String>, force_declare: bool, r:Receiver) -> Result<(),RbtError> {
-
+pub fn open_receive(
+    o: Options,
+    q: Option<String>,
+    force_declare: bool,
+    r: Receiver,
+) -> Result<(), RbtError> {
     // open session/channel
     let (_, mut channel) = _open(o)?;
 
@@ -178,22 +187,33 @@ pub fn open_receive(o:Options, q:Option<String>, force
     Ok(())
 }
 
-
-fn do_open_receive(channel:&mut Channel, q:Option<String>, force_declare: bool, r:Receiver) -> Result<String,RbtError> {
-
+fn do_open_receive(
+    channel: &mut Channel,
+    q: Option<String>,
+    force_declare: bool,
+    r: Receiver,
+) -> Result<String, RbtError> {
     let mut auto_delete = false;
     let mut bind_routing_key = r.routing_key.clone();
-    
+
     let queue_name = match q {
         Some(q) => {
             // Force the declaration of this queue
             if force_declare {
                 // queue, passive, durable, exclusive, auto_delete, nowait, arguments
-                let queue_declare =  channel.queue_declare(q, false, false, auto_delete, auto_delete, false, Table::new())?;
+                let queue_declare = channel.queue_declare(
+                    q,
+                    false,
+                    false,
+                    auto_delete,
+                    auto_delete,
+                    false,
+                    Table::new(),
+                )?;
 
                 // name is auto generated
                 queue_declare.queue
-            }else{
+            } else {
                 q
             }
         }
@@ -205,25 +225,33 @@ fn do_open_receive(channel:&mut Channel, q:Option<Stri
             }
 
             // queue, passive, durable, exclusive, auto_delete, nowait, arguments
-            let queue_declare =
-                channel.queue_declare(
-                                    q.clone().unwrap_or("".to_owned()) ,
-                                    false, false,
-                                    auto_delete, auto_delete, false, Table::new())?;
+            let queue_declare = channel.queue_declare(
+                q.clone().unwrap_or("".to_owned()),
+                false,
+                false,
+                auto_delete,
+                auto_delete,
+                false,
+                Table::new(),
+            )?;
 
             // name is auto generated
             queue_declare.queue
-
         }
     };
 
     // Only bind if we have a routing key - May be an existing queue
     if let Some(routing_key) = bind_routing_key {
         // bind queue to the exchange, which already must be declared.
-        
+
         if r.exchange != "" {
-            channel.queue_bind(queue_name.clone(), r.exchange.clone(), routing_key.clone(),
-                            false, Table::new())?;
+            channel.queue_bind(
+                queue_name.clone(),
+                r.exchange.clone(),
+                routing_key.clone(),
+                false,
+                Table::new(),
+            )?;
         }
     }
 
@@ -232,8 +260,16 @@ fn do_open_receive(channel:&mut Channel, q:Option<Stri
 
     // start consuming the queue.
     // callback, queue, consumer_tag, no_local, no_ack, exclusive, nowait, arguments
-    channel.basic_consume(r, queue_name.clone(), consumer_tag, false,
-                          false, false, false, Table::new())?;
+    channel.basic_consume(
+        r,
+        queue_name.clone(),
+        consumer_tag,
+        false,
+        false,
+        false,
+        false,
+        Table::new(),
+    )?;
 
     Ok(queue_name)
 }
