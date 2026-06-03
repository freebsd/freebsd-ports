-- prevent model download in favor of port dependency

--- misaki/en.py.orig2025-01-14 00:00:00 UTC
+++ misaki/en.py
@@ -497,8 +497,10 @@ class G2P:
         self.version = version
         self.british = british
         name = f"en_core_web_{'trf' if trf else 'sm'}"
-        if not spacy.util.is_package(name):
-            spacy.cli.download(name)
+        # Model is pre-installed by FreeBSD port, don't download at runtime
+        # if not spacy.util.is_package(name):
+        #     spacy.cli.download(name)
+        # Fail early if model is not installed
         components = ['transformer' if trf else 'tok2vec', 'tagger']
         self.nlp = spacy.load(name, enable=components)
         self.lexicon = Lexicon(british)
