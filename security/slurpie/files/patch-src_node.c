--- src/node.c.orig	1999-01-30 21:10:17 UTC
+++ src/node.c
@@ -102,7 +102,7 @@ void clean_up( int exit_status )
 
 
 /////////////////////////////
-int main( int argc, u_char **argv )
+int main( int argc, char **argv )
 {
    u_int exit_state = 0;
    global.self.addr.sin_port = 0;
