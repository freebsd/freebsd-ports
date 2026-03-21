--- test/test_espeak.py.orig2	2024-01-01 00:00:00 UTC
+++ test/test_espeak.py
@@ -148,6 +148,7 @@ def test_path_good():
 @pytest.mark.skipif(
     'PHONEMIZER_ESPEAK_LIBRARY' in os.environ,
     reason='cannot modify environment')
+@pytest.mark.skip(reason='python3 exists on FreeBSD so not a good test binary')
 def test_path_venv():
     try:
         os.environ['PHONEMIZER_ESPEAK_LIBRARY'] = (
