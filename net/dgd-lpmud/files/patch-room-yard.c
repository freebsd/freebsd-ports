--- 2.4.5/room/yard.c.orig	2011-08-02 12:15:07.000000000 -0700
+++ 2.4.5/room/yard.c	2011-08-02 12:15:19.000000000 -0700
@@ -7,7 +7,7 @@
 /*
  * Make these arrays global, so they only have to be initialized once.
  */
-string chat_str, a_chat_str, function, type, match;
+string chat_str, a_chat_str, funcname, type, match;
 
 extra_reset() {
     no_castle_flag = 1;
@@ -30,14 +30,14 @@
 		   "A really filthy looking poor beggar.\n");
 	call_other(beggar, "set_hp", 30);
 	move_object(beggar, this_object());
-	if (!function) {
-	    function = allocate(1);
+	if (!funcname) {
+	    funcname = allocate(1);
 	    type = allocate(1);
 	    match = allocate(1);
-	    function[0] = "give_beggar";
+	    funcname[0] = "give_beggar";
 	    type[0] = "gives";
 	}
-	call_other(beggar, "set_match", this_object(), function, type, match);
+	call_other(beggar, "set_match", this_object(), funcname, type, match);
 	if (!chat_str) {
 	    chat_str = allocate(3);
 	    chat_str[0] =
