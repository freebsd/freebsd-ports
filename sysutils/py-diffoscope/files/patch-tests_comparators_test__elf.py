commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives

    The output is more precise and less dependent on binutils version.

    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- tests/comparators/test_elf.py.orig	2016-01-31 06:35:23 UTC
+++ tests/comparators/test_elf.py
@@ -92,7 +92,7 @@ def lib_differences(lib1, lib2):
 @pytest.mark.skipif(tool_missing('readelf') or tool_missing('objdump'), reason='missing readelf or objdump')
 def test_lib_differences(lib_differences):
     assert len(lib_differences) == 2
-    assert lib_differences[0].source1 == 'metadata'
+    assert lib_differences[0].source1 == 'file list'
     expected_metadata_diff = open(os.path.join(os.path.dirname(__file__), '../data/elf_lib_metadata_expected_diff')).read()
     assert lib_differences[0].unified_diff == expected_metadata_diff
     assert 'objdump' in lib_differences[1].source1
