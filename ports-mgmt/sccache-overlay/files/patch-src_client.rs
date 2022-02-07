--- src/client.rs.orig	2021-01-12 22:25:51 UTC
+++ src/client.rs
@@ -17,20 +17,21 @@ use crate::protocol::{Request, Response};
 use crate::util;
 use byteorder::{BigEndian, ByteOrder};
 use retry::{delay::Fixed, retry};
+use std::env;
 use std::io::{self, BufReader, BufWriter, Read};
-use std::net::TcpStream;
+use std::os::unix::net::UnixStream;
 
 /// A connection to an sccache server.
 pub struct ServerConnection {
     /// A reader for the socket connected to the server.
-    reader: BufReader<TcpStream>,
+    reader: BufReader<UnixStream>,
     /// A writer for the socket connected to the server.
-    writer: BufWriter<TcpStream>,
+    writer: BufWriter<UnixStream>,
 }
 
 impl ServerConnection {
     /// Create a new connection using `stream`.
-    pub fn new(stream: TcpStream) -> io::Result<ServerConnection> {
+    pub fn new(stream: UnixStream) -> io::Result<ServerConnection> {
         let writer = stream.try_clone()?;
         Ok(ServerConnection {
             reader: BufReader::new(stream),
@@ -65,7 +66,8 @@ impl ServerConnection {
 /// Establish a TCP connection to an sccache server listening on `port`.
 pub fn connect_to_server(port: u16) -> io::Result<ServerConnection> {
     trace!("connect_to_server({})", port);
-    let stream = TcpStream::connect(("127.0.0.1", port))?;
+    let unix_socket_path = env::var_os("SCCACHE_UNIX_LISTEN").unwrap();
+    let stream = UnixStream::connect(unix_socket_path)?;
     ServerConnection::new(stream)
 }
 
