--- input.c.orig	2019-02-22 18:41:46 UTC
+++ input.c
@@ -64,7 +64,6 @@ static int d;              // char read from stdin
 int return_value;          // return value of getch()
 int cmd_multiplier = 0;    // Multiplier
 int cmd_pending = 0;       // Command pending
-int shall_quit;            // Break loop if ESC key is pressed
 
 /**
  * \brief Reads stdin for a valid command
