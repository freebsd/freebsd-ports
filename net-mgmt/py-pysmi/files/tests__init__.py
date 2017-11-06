from unittest import SkipTest, TestSuite


def load_tests(*args, **kwargs):
    import suite
    return suite.suite


try:
    from pysnmp.smi.builder import MibBuilder
except ImportError:

    # python -m unittest pysmi.tests
    def load_tests(*args, **kwars):
        print("Skipping test suite: pysnmp is not installed")
        return TestSuite()

    # nosetests pysmi
    def setup():
        raise SkipTest("pysnmp is not installed")
