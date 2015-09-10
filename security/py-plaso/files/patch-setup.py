--- setup.py.orig	2015-06-15 05:38:55 UTC
+++ setup.py
@@ -104,7 +104,6 @@ setup(
     },
     data_files=[
         ('share/plaso', glob.glob(os.path.join('data', '*'))),
-        ('share/doc/plaso', glob.glob(os.path.join('docs', '*'))),
     ],
     # TODO: this is disabled for now since setup.py will actually try
     # to install the depencies directly from pypi.
