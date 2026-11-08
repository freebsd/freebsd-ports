--- setup.py.orig	2018-04-02 00:00:00 UTC
+++ setup.py
@@ -39,6 +39,8 @@
 import sys
 import warnings

+from setuptools import setup
+
 pkg_name = 'pynleq2'
 ext_modules = []

@@ -46,56 +48,9 @@
 def _path_under_setup(*args):
     return os.path.join(os.path.dirname(__file__), *args)

-if len(sys.argv) > 1 and '--help' not in sys.argv[1:] and sys.argv[1] not in (
-        '--help-commands', 'egg_info', 'clean', '--version'):
-    from numpy.distutils.core import Extension, setup
-    # nleq2 version: 2.3.0.2
-    md5output = """\
-    1cd2f30a38e255d394685075e921de4a  linalg_nleq2.f
-    8a94b6c440d068f075abecbde495a8e1  nleq2.f
-    77189300200be5748152fa28dc236963  wnorm.f
-    5d912441fb6f55d10c8b98bbb9168195  zibconst.f
-    e2ac1a20fc6294cb3e0d7f65bbac53e6  zibmon.f
-    6520c958f2bd339b435a68541d5b910b  zibsec.f
-    """
-    from textwrap import dedent
-    md5sums, sources = zip(*map(str.split, dedent(md5output)[:-1].split('\n')))
-
-    def md5_of_file(path, nblocks=128):
-        from hashlib import md5
-        md = md5()
-        with open(path, 'rb') as f:
-            for chunk in iter(lambda: f.read(nblocks*md.block_size), b''):
-                md.update(chunk)
-        return md
-
-    def download(url, outpath):
-        try:
-            from urllib2 import urlopen
-        except ImportError:
-            from urllib.request import urlopen
-        f = urlopen(url)
-        with open(outpath, "wb") as fh:
-            fh.write(f.read())
-
-    NLEQ2_URL = os.environ.get('PYNLEQ2_NLEQ2_ROOT_URL', None)
-
-    for src, md5sum in zip(sources, md5sums):
-        srcpath = _path_under_setup('nleq2', src)
-        if not os.path.exists(srcpath):
-            if NLEQ2_URL:
-                download(NLEQ2_URL+src, srcpath)
-            else:
-                fmtstr = "Could not find: %s ($PYNLEQ2_NLEQ2_ROOT_URL not set)"
-                raise ValueError(fmtstr % src)
-        if md5_of_file(srcpath).hexdigest() != md5sum:
-            warnings.warn("Unexpected MD5 sum for %s" % srcpath)
-
-    ext_modules = [
-        Extension('pynleq2.nleq2', [_path_under_setup('nleq2', f)
-                                    for f in ('nleq2.pyf',) + sources])
-    ]
+# The extension module pynleq2/nleq2*.so is pre-built by the port in
+# pre-build using f2py, so no extension is built by setup.py.

 PYNLEQ2_RELEASE_VERSION = os.environ.get('PYNLEQ2_RELEASE_VERSION', '')

 # http://conda.pydata.org/docs/build.html#environment-variables-set-during-the-build-process
@@ -144,6 +99,7 @@
     license='BSD',
     requires=['numpy'],
     packages=[pkg_name] + tests,
+    package_data={pkg_name: ['nleq2*.so']},
     ext_modules=ext_modules,
     zip_safe=False,  # https://github.com/pytest-dev/pytest/issues/1445
 )
