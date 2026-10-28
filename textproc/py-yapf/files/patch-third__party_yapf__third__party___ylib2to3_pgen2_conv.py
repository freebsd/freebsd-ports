Description: Import grammar and token relatively in the vendored pgen2 conv
  module; the Python 2 era absolute 'from pgen2 import ...' never worked.
Issue ID: https://github.com/google/yapf/issues/1334
Changeset: none
TODO: Drop once a release includes a fix.

--- third_party/yapf_third_party/_ylib2to3/pgen2/conv.py.orig	2024-11-13 23:42:19 UTC
+++ third_party/yapf_third_party/_ylib2to3/pgen2/conv.py
@@ -29,8 +29,8 @@ without having to invoke the Python pgen
 import re
 
 # Local imports
-from pgen2 import grammar
-from pgen2 import token
+from . import grammar
+from . import token
 
 
 class Converter(grammar.Grammar):
