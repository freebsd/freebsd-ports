--- main.c.orig	2005-10-25 22:08:25 UTC
+++ main.c
@@ -36,6 +36,7 @@
 /* minimum terminal dimensions to run program */
 #define MIN_REQUIRED_WIDTH 80
 #define MIN_REQUIRED_HEIGHT 25
+#define MAX_HOSTNAME_LENGTH 64
 
 #define REMINDER_LINE "OmNiTTY-R v" OMNITTY_VERSION \
                       "  \007F1\007:menu  \006F2/3\007:sel  \003F4\007:tag" \
@@ -88,6 +89,12 @@ void curses_init() {
    define_key("\e[15~", KEY_F(5)); define_key("\e[17~", KEY_F(6));
    define_key("\e[18~", KEY_F(7)); define_key("\e[19~", KEY_F(8));
    define_key("\e[20~", KEY_F(9)); define_key("\e[21~", KEY_F(10));
+   /* If "Sun Function-Keys" is enabled in your Xterm: */
+   define_key("\e[224z", KEY_F(1)); define_key("\e[225z", KEY_F(2));
+   define_key("\e[226z", KEY_F(3)); define_key("\e[227z", KEY_F(4));
+   define_key("\e[228z", KEY_F(5)); define_key("\e[229z", KEY_F(6));
+   define_key("\e[230z", KEY_F(7)); define_key("\e[231z", KEY_F(8));
+   define_key("\e[232z", KEY_F(9)); define_key("\e[233z", KEY_F(10));
 
    getmaxyx(stdscr, h, w);
    if (h < MIN_REQUIRED_HEIGHT || w < MIN_REQUIRED_WIDTH) {
@@ -288,10 +295,10 @@ static void add_machines_from_file(const char *file) {
 }
 
 static void add_machine() {
-   static char buf[32];
+   static char buf[MAX_HOSTNAME_LENGTH];
 
    *buf = 0;
-   if (minibuf_prompt(minibuf, "Add: ", 0xE0, buf, 32)) {
+   if (minibuf_prompt(minibuf, "Add: ", 0xE0, buf, sizeof(buf))) {
       if (*buf == '@') add_machines_from_file(buf+1);
       else machmgr_add(buf);
    }
@@ -335,9 +342,10 @@ int main(int argc, char **argv) {
 
    while (!quit) {
       if (zombie_count) {
-         zombie_count--;
-         chldpid = wait(NULL);
-         machmgr_handle_death(chldpid);
+         if ((chldpid = waitpid(-1, NULL, WNOHANG)) > 0) {
+            zombie_count--;
+            machmgr_handle_death(chldpid);
+         }
       }
 
       machmgr_update();
