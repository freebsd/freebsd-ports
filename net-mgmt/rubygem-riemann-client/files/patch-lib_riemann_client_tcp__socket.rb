--- lib/riemann/client/tcp_socket.rb.orig	2019-11-25 11:01:31 UTC
+++ lib/riemann/client/tcp_socket.rb
@@ -107,13 +107,14 @@ module Riemann
       # Using the options from the initializer, a new ::Socket is created that
       # is:
       #
-      #   TCP, IPv4 only, autoclosing on exit, nagle's algorithm is disabled and has
+      #   TCP, autoclosing on exit, nagle's algorithm is disabled and has
       #   TCP Keepalive options set if keepalive is supported.
       #
-      # Returns a new ::Socket instance
-      def blank_socket
-        sock = ::Socket.new(::Socket::AF_INET, ::Socket::SOCK_STREAM, 0)
+      # Returns a new ::Socket instance for
 
+      def socket_factory(type)
+         sock = ::Socket.new(type, ::Socket::SOCK_STREAM, 0)
+
         # close file descriptors if we exec
         if Fcntl.constants.include?(:F_SETFD) && Fcntl.constants.include?(:FD_CLOEXEC)
           sock.fcntl(Fcntl::F_SETFD, Fcntl::FD_CLOEXEC)
@@ -167,13 +168,14 @@ module Riemann
         # Calculate our timeout deadline
         deadline = Time.now.to_f + connect_timeout
 
-        # Lookup destination address, we only want    IPv4             , TCP
-        addrs      = ::Socket.getaddrinfo(host, port, ::Socket::AF_INET, ::Socket::SOCK_STREAM )
+        # Lookup destination address, we only want TCP.
+        addrs      = ::Socket.getaddrinfo(host, port, nil, ::Socket::SOCK_STREAM )
         errors     = []
         conn_error = lambda { raise errors.first }
         sock       = nil
 
-        addrs.find( conn_error ) do |addr|
+        # Sort it so we get AF_INET, IPv4
+        addrs.sort.find( conn_error ) do |addr|
           sock = connect_or_error( addr, deadline, errors )
         end
         return sock
@@ -210,7 +212,7 @@ module Riemann
       # connection was possible.
       def connect_nonblock( addr, timeout )
         sockaddr = ::Socket.pack_sockaddr_in(addr[1], addr[3])
-        sock     = blank_socket()
+        sock     = self.socket_factory( addr[4] )
         sock.connect_nonblock( sockaddr )
         return sock
       rescue Errno::EINPROGRESS
