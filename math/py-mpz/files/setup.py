#!/usr/bin/env python
# To use:
#       python setup.py install
#

__version__ = "$FreeBSD$"

import os, string

try:
    import distutils
    from distutils import sysconfig
    from distutils.command.install import install
    from distutils.core import setup, Extension
except:
    raise SystemExit, "Distutils problem"

prefix = sysconfig.PREFIX
inc_dirs = [prefix + "/include"]
lib_dirs = [prefix + "/lib"]
libs = ["gmp"]

setup(name = "mpz",
      description = "GMP extension to Python",
      
      ext_modules = [Extension('mpz', ['mpzmodule.c'],
                               include_dirs = inc_dirs,
                               libraries = libs,
                               library_dirs = lib_dirs)]
      )
