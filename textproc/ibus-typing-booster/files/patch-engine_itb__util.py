--- engine/itb_util.py.orig	2017-03-13 08:42:29 UTC
+++ engine/itb_util.py
@@ -348,11 +348,12 @@ def get_hunspell_dictionary_wordlist(lan
 
     :param language: The language of the dictionary to open
     :type language: String
-    :rtype: tuple of the form (dic_path, wordlist) where
-            dic_path is the full path of the dictionary file found
+    :rtype: tuple of the form (dic_path, dictionary_encoding, wordlist) where
+            dic_path is the full path of the dictionary file found,
+            dictionary_encoding is the encoding of that dictionary file,
             and wordlist is a list of words found in that file.
             If no dictionary can be found for the requested language,
-            the return value is ('', []).
+            the return value is ('', '', []).
     '''
     dirnames = [
         '/usr/share/hunspell',
@@ -374,7 +375,7 @@ def get_hunspell_dictionary_wordlist(lan
             'get_hunspell_dictionary_wordlist(): '
             + 'No file %s.dic found in %s\n'
             %(language, dirnames))
-        return ('', [])
+        return ('', '', [])
     sys.stderr.write(
         'get_hunspell_dictionary_wordlist(): '
         + '%s file found.\n'
@@ -439,21 +440,21 @@ def get_hunspell_dictionary_wordlist(lan
                 %(dic_path, dictionary_encoding)
                 + 'giving up.\n')
             traceback.print_exc()
-            return ('', [])
+            return ('', '', [])
         except:
             sys.stderr.write(
                 'get_hunspell_dictionary_wordlist(): '
                 + 'Unexpected error loading .dic File: %s\n' %dic_path)
             traceback.print_exc()
-            return ('', [])
+            return ('', '', [])
     except:
         sys.stderr.write(
             'get_hunspell_dictionary_wordlist(): '
             + 'Unexpected error loading .dic File: %s\n' %dic_path)
         traceback.print_exc()
-        return ('', [])
+        return ('', '', [])
     if not dic_buffer:
-        return ('', [])
+        return ('', '', [])
     sys.stderr.write(
         'get_hunspell_dictionary_wordlist(): '
         + 'Successfully loaded %s using %s encoding.\n'
@@ -488,7 +489,7 @@ def get_hunspell_dictionary_wordlist(lan
             re.sub(r'[/\t].*', '', x.replace('\n', '')))
         for x in dic_buffer
     ]
-    return (dic_path, word_list)
+    return (dic_path, dictionary_encoding, word_list)
 
 if __name__ == "__main__":
     import doctest
@@ -497,3 +498,4 @@ if __name__ == "__main__":
         sys.exit(1)
     else:
         sys.exit(0)
+
