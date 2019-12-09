--- README.rst.orig	2018-10-30 23:51:01 UTC
+++ README.rst
@@ -62,7 +62,7 @@ Packaging notes
    (``python3 -m venv venv && source venv/bin/activate``)
 -  install the requirements: ``pip install -r dev-requirements.txt``
 -  build the source dist: ``python setup.py sdist``
--  make sure docker is installed and running and you’re on a 64bit linux
+-  make sure docker is installed and running and you're on a 64bit linux
    machine
 -  build the binary dists: ``./scripts/build_packages.sh``
 -  upload to pypi: ``twine upload dist/* wheelhouse/pyenet*``
