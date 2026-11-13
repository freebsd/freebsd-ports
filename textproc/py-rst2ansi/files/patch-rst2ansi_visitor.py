Description: Drop the docutils.utils.error_reporting imports (module removed
  in docutils 0.22).
Issue ID: https://github.com/Snaipe/python-rst2ansi/issues/16
Changeset: https://github.com/Snaipe/python-rst2ansi/commit/81758ed
TODO: Drop when a release after 0.1.5 appears.

--- rst2ansi/visitor.py.orig	2026-10-11 21:18:05 UTC
+++ rst2ansi/visitor.py
@@ -24,7 +24,6 @@ THE SOFTWARE.
 """
 
 from docutils import core, frontend, nodes, utils, writers, languages, io
-from docutils.utils.error_reporting import SafeString
 from docutils.transforms import writer_aux
 from docutils.parsers.rst import roles
 
