-- Force non-interactive matplotlib backend in tests.
-- Prevents crashes in headless FreeBSD test environments that otherwise select
-- a GUI backend.
-- Upstream: not yet submitted

--- test/conftest.py.orig	2022-11-09 12:37:21 UTC
+++ test/conftest.py
@@ -4,11 +4,14 @@
 
 import pathlib
 from collections.abc import Callable
 
+import matplotlib
 import numpy as np
 import pytest
 
 import phonopy
+
+matplotlib.use("Agg")
 from phonopy import Phonopy
 from phonopy.interface.phonopy_yaml import read_cell_yaml
 from phonopy.structure.atoms import PhonopyAtoms
