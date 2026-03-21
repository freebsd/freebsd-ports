--- test/test_festival.py.orig	2024-01-01 00:00:00 UTC
+++ test/test_festival.py
@@ -40,8 +40,8 @@ def _test(text, separator=Separator(
     reason='festival-2.1 gives different results than further versions '
     'for syllable boundaries')
 def test_hello():
-    assert _test(['hello world']) == ['hh-ax|l-ow w-er-l-d']
-    assert _test(['hello', 'world']) == ['hh-ax|l-ow', 'w-er-l-d']
+    assert _test(['hello world']) == ['hh-ax-l|ow w-er-l-d']
+    assert _test(['hello', 'world']) == ['hh-ax-l|ow', 'w-er-l-d']
 
 
 def test_bad():
@@ -100,6 +100,7 @@ def test_path_bad():
 @pytest.mark.skipif(
     'PHONEMIZER_FESTIVAL_EXECUTABLE' in os.environ,
     reason='cannot modify environment')
+@pytest.mark.skip(reason='python3 exists on FreeBSD so not a good test binary')
 def test_path_venv():
     try:
         os.environ['PHONEMIZER_FESTIVAL_EXECUTABLE'] = shutil.which('python3')

