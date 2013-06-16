diff --git src/master.c src/master.c
index 4b24f9b..683d9a6 100644
--- src/master.c
+++ src/master.c
@@ -132,7 +132,7 @@ char *get_time_str( u_int seconds )
    return timestr;
 }
 
-int main( int argc, u_char **argv )
+int main( int argc, char **argv )
 {
    static unsigned id, init_time;
 
