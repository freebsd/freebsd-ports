--- stem_word.c.orig
+++ stem_word.c
@@ -48,7 +48,7 @@
     bool        (*condition)( char const *word );
 };
 
-static char *end; // iterator at end of word being stemmed
+static char *my_end; // iterator at end of word being stemmed
 // Acess to this global variable is protected by the cache_lock mutex in
 // stem_word().
 
@@ -112,10 +112,10 @@
 //
 //*****************************************************************************
 {
-    if ( end - word < 3 )
+    if ( my_end - word < 3 )
         return false;
 
-    register char const *c = end;
+    register char const *c = my_end;
     return !(is_vowel( *--c ) || *c == 'w' || *c == 'x' || *c == 'y' ) &&
             (is_vowel( *--c ) || *c == 'y') && !is_vowel( *--c );
 }
@@ -206,7 +206,7 @@
 #   endif
 
     for ( ; rule->id; ++rule ) {
-        register char *const suffix = end - rule->old_suffix_len;
+        register char *const suffix = my_end - rule->old_suffix_len;
         if ( suffix < word )
             continue;
 
@@ -226,7 +226,7 @@
 #           ifdef DEBUG_stem_word
             cerr << "---> replaced word=" << word << "\n";
 #           endif
-            end = suffix + rule->new_suffix_len;
+            my_end = suffix + rule->new_suffix_len;
             break;
         }
         *suffix = ch;                           // no match: put back
@@ -397,7 +397,7 @@
 
     char word_buf[ Word_Hard_Max_Size ];
     ::strcpy( word_buf, word );
-    end = word_buf + len;
+    my_end = word_buf + len;
 
     replace_suffix( word_buf, rules_1a );
     int const rule = replace_suffix( word_buf, rules_1b );
