"""Smoke test for the PyWry port."""

import pywry


def test_version():
    assert pywry.__version__ == "2.0.6"


def test_can_import_core_modules():
    from pywry import config, exceptions, models, types
    assert config is not None
    assert exceptions is not None
    assert models is not None
    assert types is not None
