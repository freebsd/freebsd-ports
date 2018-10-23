--- src/main.rs.orig	2018-10-14 20:00:28 UTC
+++ src/main.rs
@@ -1,36 +1,41 @@
-extern crate rustc_serialize;
 extern crate amqp;
-extern crate rand;
 extern crate conduit_mime_types as mime;
+extern crate rand;
+extern crate rustc_serialize;
 extern crate url;
-#[macro_use] extern crate clap;
+#[macro_use]
+extern crate clap;
 
-#[macro_use] mod error;
+#[macro_use]
+mod error;
 mod client;
 mod output;
 mod publish;
 mod subscribe;
 
+use clap::{App, Arg, SubCommand};
+use error::RbtError;
+use rustc_serialize::json::Json;
 use std::env;
 use std::fs;
-use clap::{Arg, App, SubCommand};
+use std::panic;
 use url::Url;
-use rustc_serialize::json::Json;
-use error::RbtError;
 
-
 fn main() {
+    panic::set_hook(Box::new(|_panic| {
+        // chill
+    }));
+
     _main().unwrap_or_else(error::handle);
 }
 
-static HOST:&'static str = "127.0.0.1";
-static PORT:&'static str = "5672";
-static USER:&'static str = "guest";
-static PASS:&'static str = "guest";
-static VHST:&'static str = "";
+static HOST: &'static str = "127.0.0.1";
+static PORT: &'static str = "5672";
+static USER: &'static str = "guest";
+static PASS: &'static str = "guest";
+static VHST: &'static str = "";
 
-fn _main() -> Result<(),RbtError> {
-
+fn _main() -> Result<(), RbtError> {
     let matches = App::new("Rabbiteer")
         .version(crate_version!())
         .author("Martin Algesten <martin@algesten.se>")
@@ -124,7 +129,7 @@ fn _main() -> Result<(),RbtError> {
                          .short("e")
                          .long("exchange")
                          .takes_value(true)
-                         .required(true))
+                         .default_value(""))
                     .arg(Arg::with_name("routing_key")
                          .help("Routing key")
                          .short("r")
@@ -167,11 +172,11 @@ fn _main() -> Result<(),RbtError> {
 
     // start with defaults.
     let mut opts = amqp::Options {
-        host:     value_t!(matches, "host", String)?,
-        port:     value_t!(matches, "port", u16)?,
-        login:    value_t!(matches, "user", String)?,
+        host: value_t!(matches, "host", String)?,
+        port: value_t!(matches, "port", u16)?,
+        login: value_t!(matches, "user", String)?,
         password: value_t!(matches, "password", String)?,
-        vhost:    value_t!(matches, "vhost", String)?,
+        vhost: value_t!(matches, "vhost", String)?,
         ..Default::default()
     };
 
@@ -183,7 +188,7 @@ fn _main() -> Result<(),RbtError> {
         parse_url(&mut opts, urlstr)?;
     }
 
-    fn if_differs(opt:Option<&str>, def:&str, set:&mut FnMut(String) -> ()) {
+    fn if_differs(opt: Option<&str>, def: &str, set: &mut FnMut(String) -> ()) {
         if let Some(v) = opt {
             if v != def {
                 set(v.to_string());
@@ -191,44 +196,46 @@ fn _main() -> Result<(),RbtError> {
         }
     }
 
-    if_differs(matches.value_of("host"), HOST, &mut|v|{ opts.host = v });
-    if_differs(matches.value_of("port"), PORT, &mut|v|{ opts.port = v.parse::<u16>().unwrap() });
-    if_differs(matches.value_of("user"), USER, &mut|v|{ opts.login = v });
-    if_differs(matches.value_of("password"), PASS, &mut|v|{ opts.password = v });
-    if_differs(matches.value_of("vhost"), VHST, &mut|v|{ opts.vhost = v });
+    if_differs(matches.value_of("host"), HOST, &mut |v| {
+        opts.host = v
+    });
+    if_differs(matches.value_of("port"), PORT, &mut |v| {
+        opts.port = v.parse::<u16>().unwrap()
+    });
+    if_differs(matches.value_of("user"), USER, &mut |v| {
+        opts.login = v
+    });
+    if_differs(matches.value_of("password"), PASS, &mut |v| {
+        opts.password = v
+    });
+    if_differs(matches.value_of("vhost"), VHST, &mut |v| {
+        opts.vhost = v
+    });
 
     // depending on subcommand, we do one or the other
     match matches.subcommand_name() {
-
         // execute publish command
         Some("publish") => {
-
             // the args after the "publish command
             let subm = matches.subcommand_matches("publish").unwrap();
 
             publish::do_publish(opts, subm)
+        }
 
-        },
-
         // execute subscribe command
         Some("subscribe") => {
-
             // the args after the "subscribe" command
             let subm = matches.subcommand_matches("subscribe").unwrap();
 
             subscribe::do_subscribe(opts, subm)
+        }
 
-        },
-
         _ => rbterr!("Need subcommand. Try --help"),
     }
-
 }
 
-
-
 // update the opts object with the given url
-fn parse_url(opts:&mut amqp::Options, urlstr:String) -> Result<(),RbtError> {
+fn parse_url(opts: &mut amqp::Options, urlstr: String) -> Result<(), RbtError> {
     if let Ok(url) = Url::parse(urlstr.as_ref()) {
         if url.scheme() != "amqp" {
             rbterr!("Unknown scheme: {}", url);
@@ -256,12 +263,9 @@ fn parse_url(opts:&mut amqp::Options, urlstr:String) -
     }
 }
 
-
-
 // update the opts object with the conf
-fn parse_conf(opts:&mut amqp::Options) -> bool {
-
-    let mut update = |connopt:Option<&Json>| -> bool {
+fn parse_conf(opts: &mut amqp::Options) -> bool {
+    let mut update = |connopt: Option<&Json>| -> bool {
         if let Some(conn) = connopt {
             if conn.is_object() {
                 if let Json::String(ref v) = conn["host"] {
