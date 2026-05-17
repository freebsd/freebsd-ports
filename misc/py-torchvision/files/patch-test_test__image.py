--- test/test_image.py.orig	2026-05-17 05:19:19 UTC
+++ test/test_image.py
@@ -871,7 +871,7 @@ def test_decode_gif(tmpdir, name, scripted):
     else:
         url = f"https://sourceforge.net/p/giflib/code/ci/master/tree/pic/{name}.gif?format=raw"
     with open(path, "wb") as f:
-        f.write(requests.get(url).content)
+        f.write(requests.get(url, headers={"User-Agent": "torchvision-test"}).content)
 
     encoded_bytes = read_file(path)
     f = torch.jit.script(decode_gif) if scripted else decode_gif
