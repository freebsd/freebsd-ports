--- setup.py.orig	2021-01-26 09:46:22 UTC
+++ setup.py
@@ -30,7 +30,7 @@ iohprofiler = Extension('IOHexperimenter._IOHprofiler'
     extra_compile_args=extra_compile_args
 )
 
-__version__ = "auto"
+__version__ = "%%PORTVERSION%%"
 gh_ref = os.environ.get("GITHUB_REF")
 if gh_ref:
     *_, tag = gh_ref.split("/")
