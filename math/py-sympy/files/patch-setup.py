-- mpmath is at 1.4 which causes breakage in misc/py-torchvision and potentially other ports

--- setup.py.orig	2026-03-14 18:43:16 UTC
+++ setup.py
@@ -321,7 +321,7 @@ if __name__ == '__main__':
           },
           # Set upper bound when making the release branch.
           install_requires=[
-              'mpmath >= 1.1.0, < 1.4',
+              'mpmath >= 1.1.0',
           ],
           py_modules=['isympy'],
           packages=['sympy'] + modules + tests,
