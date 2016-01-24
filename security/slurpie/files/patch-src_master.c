--- src/master.c.orig	1999-01-30 21:08:08 UTC
+++ src/master.c
@@ -132,7 +132,7 @@ char *get_time_str( u_int seconds )
    return timestr;
 }
 
-int main( int argc, u_char **argv )
+int main( int argc, char **argv )
 {
    static unsigned id, init_time;
 
