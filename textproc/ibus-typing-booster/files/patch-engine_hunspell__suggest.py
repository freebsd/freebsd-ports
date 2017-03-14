--- engine/hunspell_suggest.py.orig	2017-03-13 08:42:29 UTC
+++ engine/hunspell_suggest.py
@@ -76,8 +76,9 @@ class Dictionary:
         '''
         if DEBUG_LEVEL > 0:
             sys.stderr.write("load_dictionary() ...\n")
-        (dic_path, self.words) = itb_util.get_hunspell_dictionary_wordlist(
-            self.name)
+        (dic_path,
+         self.encoding,
+         self.words) = itb_util.get_hunspell_dictionary_wordlist(self.name)
         if self.words:
             # List of languages where accent insensitive matching makes sense:
             accent_languages = (
@@ -183,6 +184,9 @@ class Hunspell:
         >>> h.suggest('Glühwürmchen')[0]
         ('Glühwürmchen', 0)
 
+        >>> h.suggest('Alpengluhen')[0]
+        ('Alpenglühen', 0)
+
         >>> h.suggest('filosofictejsi')
         [('filosofičtější', 0), ('filosofičtěji', -1)]
 
@@ -291,7 +295,9 @@ class Hunspell:
                         # the result back to the internal
                         # normalization form (NFD) (hunspell does the
                         # right thing for Korean if the input is NFC).
-                        if dictionary.pyhunspell_object.spell(input_phrase_nfc):
+                        if dictionary.pyhunspell_object.spell(
+                                input_phrase_nfc.encode(
+                                    dictionary.encoding, 'replace')):
                             # This is a valid word in this dictionary.
                             # It might have been missed by the matching
                             # above because the dictionary might not
@@ -380,3 +386,4 @@ def main():
 
 if __name__ == "__main__":
     main()
+
