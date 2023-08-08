--- base/sbcp.c
+++ base/sbcp.c
@@ -1,4 +1,4 @@
-/* Copyright (C) 2001-2021 Artifex Software, Inc.
+/* Copyright (C) 2001-2023 Artifex Software, Inc.
    All Rights Reserved.
 
    This software is provided AS-IS with no warranty, either express or
@@ -50,6 +50,14 @@ s_xBCPE_process(stream_state * st, stream_cursor_read * pr,
         byte ch = *++p;
 
         if (ch <= 31 && escaped[ch]) {
+            /* Make sure we have space to store two characters in the write buffer,
+             * if we don't then exit without consuming the input character, we'll process
+             * that on the next time round.
+             */
+            if (pw->limit - q < 2) {
+                p--;
+                break;
+            }
             if (p == rlimit) {
                 p--;
                 break;
