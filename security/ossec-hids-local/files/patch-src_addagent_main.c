--- src/addagent/main.c.orig	2020-02-14 19:46:22 UTC
+++ src/addagent/main.c
@@ -17,6 +17,7 @@ static void print_banner(void);
 static void manage_shutdown(int sig) __attribute__((noreturn));
 #endif
 
+int willchroot;
 
 #if defined(__MINGW32__)
 static int setenv(const char *name, const char *val, __attribute__((unused)) int overwrite)
@@ -104,7 +105,6 @@ int main(int argc, char **argv)
     int ret;
 #endif
 
-    extern int willchroot;
     willchroot = 1;
 
     /* Set the name */
