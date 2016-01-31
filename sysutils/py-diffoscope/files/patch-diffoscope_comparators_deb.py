commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives

    The output is more precise and less dependent on binutils version.

    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- diffoscope/comparators/deb.py.orig	2016-01-31 06:31:13 UTC
+++ diffoscope/comparators/deb.py
@@ -29,7 +29,7 @@ import diffoscope.comparators
 from diffoscope.comparators.binary import File
 from diffoscope.comparators.libarchive import LibarchiveContainer, list_libarchive
 from diffoscope.comparators.utils import \
-    Archive, ArchiveMember, get_ar_content
+    Archive, ArchiveMember
 from diffoscope.comparators.tar import TarContainer
 
 
@@ -86,10 +86,9 @@ class DebFile(File):
         return self._control
 
     def compare_details(self, other, source=None):
-        my_content = get_ar_content(self.path)
-        other_content = get_ar_content(other.path)
-        return [Difference.from_text(my_content, other_content, self.path, other.path, source="metadata")]
-
+        return [Difference.from_text_readers(list_libarchive(self.path),
+                                             list_libarchive(other.path),
+                                             self.path, other.path, source="file list")]
 
 class Md5sumsFile(File):
     @staticmethod
