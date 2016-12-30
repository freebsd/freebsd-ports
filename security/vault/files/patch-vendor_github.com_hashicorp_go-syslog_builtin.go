--- vendor/github.com/hashicorp/go-syslog/builtin.go.orig	2016-12-30 09:29:42 UTC
+++ vendor/github.com/hashicorp/go-syslog/builtin.go
@@ -199,7 +199,7 @@ func (n *netConn) close() error {
 // local machine using a Unix domain socket.
 func unixSyslog() (conn serverConn, err error) {
 	logTypes := []string{"unixgram", "unix"}
-	logPaths := []string{"/dev/log", "/var/run/syslog"}
+	logPaths := []string{"/dev/log", "/var/run/syslog", "/var/run/log"}
 	for _, network := range logTypes {
 		for _, path := range logPaths {
 			conn, err := net.DialTimeout(network, path, localDeadline)
