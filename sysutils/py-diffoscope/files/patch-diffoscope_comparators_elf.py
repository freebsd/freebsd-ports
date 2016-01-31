commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives

    The output is more precise and less dependent on binutils version.

    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- diffoscope/comparators/elf.py.orig	2016-01-31 06:32:02 UTC
+++ diffoscope/comparators/elf.py
@@ -24,8 +24,9 @@ import subprocess
 from diffoscope import tool_required, OutputParsingError
 from diffoscope import logger
 from diffoscope.comparators.binary import File
+from diffoscope.comparators.libarchive import list_libarchive
 from diffoscope.comparators.deb import DebFile, get_build_id_map
-from diffoscope.comparators.utils import get_ar_content, Command, Container
+from diffoscope.comparators.utils import Command, Container
 from diffoscope.difference import Difference
 
 
@@ -415,10 +416,8 @@ class StaticLibFile(File):
 
     def compare_details(self, other, source=None):
         differences = []
-        # look up differences in metadata
-        content1 = get_ar_content(self.path)
-        content2 = get_ar_content(other.path)
-        differences.append(Difference.from_text(
-                               content1, content2, self.path, other.path, source="metadata"))
+        differences.append(Difference.from_text_readers(list_libarchive(self.path),
+                                                        list_libarchive(other.path),
+                                                        self.path, other.path, source="file list"))
         differences.extend(_compare_elf_data(self.path, other.path))
         return differences
