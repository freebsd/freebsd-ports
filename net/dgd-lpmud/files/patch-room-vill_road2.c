$FreeBSD$

--- 2.4.5/room/vill_road2.c.orig	1990-10-19 15:07:01.000000000 -0700
+++ 2.4.5/room/vill_road2.c	2011-08-02 10:25:00.000000000 -0700
@@ -4,10 +4,9 @@
 int count;
 string chat_str;	/* This variable is only initialized once. */
 string a_chat_str;
-string function, type, match;
+string funcname, type, match;
 
 reset(arg) {
-    start_harry();
     if (arg)
 	return;
     dest_dir = ({ "room/vill_road1","west",
@@ -22,6 +21,7 @@
         "south is the adventurers guild. The road runs towards the shore to\n"+
         "the east.\n";
     set_light(1);
+    start_harry();
 }
 
 start_harry() {
@@ -48,37 +48,37 @@
 	    a_chat_str[6] = "Harry says: Bastard\n";
 	    a_chat_str[7] = "Harry says: You big brute!\n";
 
-	    function = allocate(12);
+	    funcname = allocate(12);
 	    type = allocate(12);
 	    match = allocate(12);
 
-	    function[0] = "why_did";
+	    funcname[0] = "why_did";
 	    type[0] = "sells";
 	    type[1] = "attack";
 	    type[2] = "left";
 	    match[2] = "the game";
 	    type[3] = "takes";
 	    type[4] = "drops";
-	    function[5] = "how_does_it_feel";
+	    funcname[5] = "how_does_it_feel";
 	    type[5] = "is now level";
-	    function[6] = "smiles";
+	    funcname[6] = "smiles";
 	    type[6] = "smiles";
 	    match[6] = " happily.";
-	    function[7] = "say_hello";
+	    funcname[7] = "say_hello";
 	    type[7] = "arrives";
-	    function[8] = "test_say";
+	    funcname[8] = "test_say";
 	    type[8] = "says:";
 	    type[9] = "tells you:";
-	    function[10] = "follow";
+	    funcname[10] = "follow";
 	    type[10] = "leaves";
-	    function[11] = "gives";
+	    funcname[11] = "gives";
 	    type[11] = "gives";
 	}
 	harry = clone_object("obj/monster");
 	/* Reuse the same arrays. */
 	call_other(harry, "load_chat", 2, chat_str);
 	call_other(harry, "load_a_chat", 20, a_chat_str);
-	call_other(harry, "set_match", this_object(), function, type, match);
+	call_other(harry, "set_match", this_object(), funcname, type, match);
 	call_other(harry, "set_name", "harry");
 	call_other(harry, "set_alias", "fjant");
 	call_other(harry, "set_short", "Harry the affectionate");
