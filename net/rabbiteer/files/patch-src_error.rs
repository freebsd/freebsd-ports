--- src/error.rs.orig	2018-10-14 20:00:28 UTC
+++ src/error.rs
@@ -1,10 +1,10 @@
+use amqp::AMQPError;
+use clap;
+use rustc_serialize::json;
+use std::convert::From;
 use std::fmt;
 use std::io;
-use std::convert::From;
-use amqp::AMQPError;
 use std::string::FromUtf8Error;
-use rustc_serialize::json;
-use clap;
 
 #[macro_export]
 macro_rules! errln(
@@ -21,9 +21,8 @@ macro_rules! rbterr(
     }}
 );
 
-
 pub enum RbtError {
-    Message(String),  // Plain error message
+    Message(String), // Plain error message
     AMQP(AMQPError),
     IO(io::Error),
     UTF8(FromUtf8Error),
@@ -31,27 +30,24 @@ pub enum RbtError {
     Clap(clap::Error),
 }
 
-
 impl fmt::Display for RbtError {
     fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
         match *self {
             RbtError::Message(ref s) => write!(f, "Error: {}", s),
-            RbtError::AMQP(ref e)    => write!(f, "{}", e),
-            RbtError::IO(ref e)      => write!(f, "{}", e),
-            RbtError::UTF8(ref e)    => write!(f, "{}", e),
-            RbtError::JSON(ref e)    => write!(f, "{}", e),
-            RbtError::Clap(ref e)    => write!(f, "{}", e),
+            RbtError::AMQP(ref e) => write!(f, "{}", e),
+            RbtError::IO(ref e) => write!(f, "{}", e),
+            RbtError::UTF8(ref e) => write!(f, "{}", e),
+            RbtError::JSON(ref e) => write!(f, "{}", e),
+            RbtError::Clap(ref e) => write!(f, "{}", e),
         }
     }
 }
 
-
-pub fn handle(e:RbtError) {
+pub fn handle(e: RbtError) {
     errln!("{}", e);
     ::std::process::exit(1);
 }
 
-
 macro_rules! from(
     ($t:ty, $p:tt) => {
         impl From<$t> for RbtError {
@@ -70,7 +66,7 @@ from!(clap::Error, Clap);
 from!(String, Message);
 
 impl From<&'static str> for RbtError {
-    fn from(s:&str) -> RbtError {
+    fn from(s: &str) -> RbtError {
         RbtError::Message(String::from(s))
     }
 }
