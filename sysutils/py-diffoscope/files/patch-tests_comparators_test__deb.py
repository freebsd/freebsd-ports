commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives

    The output is more precise and less dependent on binutils version.

    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- tests/comparators/test_deb.py.orig	2016-01-31 06:34:26 UTC
+++ tests/comparators/test_deb.py
@@ -48,12 +48,10 @@ def test_no_differences(deb1):
 def differences(deb1, deb2):
     return deb1.compare(deb2).details
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_metadata(differences):
     expected_diff = open(os.path.join(os.path.dirname(__file__), '../data/deb_metadata_expected_diff')).read()
     assert differences[0].unified_diff == expected_diff
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_compressed_files(differences):
     assert differences[1].source1 == 'control.tar.gz'
     assert differences[2].source1 == 'data.tar.gz'
@@ -64,7 +62,6 @@ def test_identification_of_md5sums_outsi
     f = specialize(FilesystemFile(path))
     assert type(f) is FilesystemFile
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_identification_of_md5sums_in_deb(deb1, deb2, monkeypatch):
     orig_func = Md5sumsFile.recognizes
     @staticmethod
@@ -78,16 +75,13 @@ def test_identification_of_md5sums_in_de
     deb1.compare(deb2)
     assert test_identification_of_md5sums_in_deb.found
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_md5sums(differences):
     assert differences[1].details[0].details[1].comment == 'Files in package differs'
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_identical_files_in_md5sums(deb1, deb2):
     for name in ['./usr/share/doc/test/README.Debian', './usr/share/doc/test/copyright']:
         assert deb1.md5sums[name] == deb2.md5sums[name]
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_identification_of_data_tar(deb1, deb2, monkeypatch):
     orig_func = DebDataTarFile.recognizes
     @staticmethod
@@ -101,7 +95,6 @@ def test_identification_of_data_tar(deb1
     deb1.compare(deb2)
     assert test_identification_of_data_tar.found
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_skip_comparison_of_known_identical_files(deb1, deb2, monkeypatch):
     compared = set()
     orig_func = diffoscope.comparators.compare_files
@@ -112,7 +105,6 @@ def test_skip_comparison_of_known_identi
     deb1.compare(deb2)
     assert './usr/share/doc/test/README.Debian' not in compared
 
-@pytest.mark.skipif(tool_missing('ar'), reason='missing ar')
 def test_compare_non_existing(monkeypatch, deb1):
     monkeypatch.setattr(Config.general, 'new_file', True)
     difference = deb1.compare(NonExistingFile('/nonexisting', deb1))
