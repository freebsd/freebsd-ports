-- Make is_valid_bibtex compatible with both bibtexparser 1.x and 2.x.
-- FreeBSD ships bibtexparser 2.x which removed the bparser module, so fall
-- back to the new parse_string API when the legacy module is unavailable.

--- src/pymatgen/util/provenance.py.orig	2026-09-26 09:41:10 UTC
+++ src/pymatgen/util/provenance.py
@@ -36,12 +36,19 @@ def is_valid_bibtex(reference: str) -> bool:
     Returns:
         bool: True if reference is valid BibTeX.
     """
-    from bibtexparser.bparser import BibTexParser
-
-    parser = BibTexParser()
     try:
+        from bibtexparser.bparser import BibTexParser
+
+        parser = BibTexParser()
         bib_database = parser.parse(reference)
         return bool(bib_database.entries)
+    except ImportError:
+        import bibtexparser as bp
+
+        try:
+            return bool(bp.parse_string(reference).entries)
+        except Exception:
+            return False
     except Exception:
         return False
 
