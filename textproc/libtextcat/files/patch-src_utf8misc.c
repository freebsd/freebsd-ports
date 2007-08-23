--- /dev/null	Thu Aug 23 22:58:13 2007
+++ src/utf8misc.c	Thu Aug 23 22:47:07 2007
@@ -0,0 +1,132 @@
+/***************************************************************************
+ *   Copyright (C) 2006 by Jocelyn Merand                                  *
+ *   joc.mer@gmail.com                                                     *
+ *                                                                         *
+ * THE BSD LICENSE
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *
+ * - Redistributions of source code must retain the above copyright
+ * notice, this list of conditions and the following disclaimer.
+ *
+ * - Redistributions in binary form must reproduce the above copyright
+ * notice, this list of conditions and the following disclaimer in the
+ * documentation and/or other materials provided with the
+ * distribution.
+ *
+ * - Neither the name of the WiseGuys Internet B.V. nor the names of
+ * its contributors may be used to endorse or promote products derived
+ * from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
+ * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
+ * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
+ * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
+ * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
+ * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
+ * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+ * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
+ * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ ***************************************************************************/
+
+#ifndef _UTF8_MISC_H_
+#include "utf8misc.h"
+#endif
+
+
+int nextcharstart(const char *str, int position){
+    int pointer = position;
+
+    if(str[pointer] & ESCAPE_MASK){ /*if the first bit of the current char is 1*/
+
+        /*then str[pointer] is an escape character*/
+
+    char escape_char = ((str[pointer] & WEIGHT_MASK) << 1); /*and we use it to count (by bit translation) following characters (only the weightest part)*/
+
+    while(escape_char & ESCAPE_MASK && str[pointer]){/*every step, we move the byte of 1 bit left, when first bit is 0, it's finished*/
+        escape_char = escape_char <<1;
+        ++pointer;
+    }
+    }
+    if(str[pointer]){   /*finaly, if we are not on the \0 character, we jump to the next character*/
+        ++pointer;
+    }
+    return pointer;
+}
+
+
+int charcopy(const char *str, char *dest){
+
+    int pointer = 0;
+    if(str[pointer] & ESCAPE_MASK){ /*if the first bit of the current char is 1*/
+
+        /*then str[pointer] is an escape character*/
+
+        char escape_char = ((str[pointer] & WEIGHT_MASK) << 1); /*and we use it to count following characters (only the weightest part)*/
+
+        while(escape_char & ESCAPE_MASK && str[pointer]){   /*every step, we move the byte of 1 bit left, when first bit is 0, it's finished*/
+            dest[pointer] = str[pointer];
+            escape_char = escape_char <<1;
+            ++pointer;
+        }
+    }
+    if(str[pointer]){
+        dest[pointer] = str[pointer];
+        ++pointer;
+    }
+
+    return pointer;
+}
+
+
+int issame( char *lex, char *key, int len )
+{
+    /*printf("[%s] prefix of [%s] with length %i", lex, key, len);*/
+    int char_counter = 0;
+    int pointer = 0;
+    while(char_counter < len) {
+
+        if(key[pointer] & ESCAPE_MASK){ /*if the first bit of the current char is 1*/
+
+            /*then key[pointer] is an escap character*/
+
+            char escape_char = ((key[pointer] & WEIGHT_MASK) << 1);     /*and we use it to count (only the weightest part)*/
+
+            while(escape_char & ESCAPE_MASK && key[pointer] == lex[pointer] ){
+                escape_char = escape_char <<1;
+                ++pointer;
+            }
+        }
+        ++char_counter; /*and we are on a new utf8 character*/
+        if ( key[pointer] != lex[pointer] ) {
+            return 0;
+            /*printf(" NO\n", lex, key, len);*/
+        }
+        ++pointer;
+    }
+    if ( lex[pointer] != '\0' ) {
+        return 0;
+        /*printf(" NO\n");*/
+    }
+
+    /*printf(" YES\n");*/
+
+    return 1;
+}
+
+
+extern int utfstrlen(const char* str){
+    int char_counter = 0;
+    int pointer = 0;
+    while(str[pointer]) {
+        pointer = nextcharstart(str, pointer);
+
+        ++char_counter; /*and we are on a new utf8 character*/
+    }
+    return char_counter;
+}
+
