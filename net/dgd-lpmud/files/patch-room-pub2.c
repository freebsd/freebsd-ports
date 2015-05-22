--- 2.4.5/room/pub2.c.orig	2011-08-02 10:22:29.000000000 -0700
+++ 2.4.5/room/pub2.c	2011-08-02 10:23:08.000000000 -0700
@@ -128,7 +128,7 @@
 /*
  * Make this global, and only initialized once.
  */
-string chat_str, function, type, match;
+string chat_str, funcname, type, match;
 
 start_player() {
     if(!player) {
@@ -146,18 +146,18 @@
 	call_other(player, "set_hp",100);
 	call_other(player, "set_wc",12);
 	move_object(player, "room/pub2");
-	if (!function) {
-	    function = allocate(2);
+	if (!funcname) {
+	    funcname = allocate(2);
 	    type = allocate(2);
 	    match = allocate(2);
-	    function[0] = "got_play";
+	    funcname[0] = "got_play";
 	    type[0] = "says:";
 	    match[0] = " play";
-	    function[1] = "make_move";
+	    funcname[1] = "make_move";
 	    type[1] = "PISS";
 	    match[1] = " OFF";
 	}
-	call_other(player, "set_match", this_object(), function, type, match);
+	call_other(player, "set_match", this_object(), funcname, type, match);
 	if (!chat_str) {
 	    chat_str = allocate(5);
 	    chat_str[0] = "Go player says: Hm. This is tricky!\n";
