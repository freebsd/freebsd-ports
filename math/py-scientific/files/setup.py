#
# setup script for ScientificPython
#

from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc
import os, sys

incdirs = [os.path.join(get_python_inc(plat_specific = 1), "Numeric")]
incdirs.append(os.path.join(sys.prefix, "include"))
incdirs.append(os.path.join("Scientific", "Include"))

libdirs = [os.path.join(sys.prefix, "lib")]

setup(name = "ScientificPython",
      version = "2.0.1",
      description = "Various useful scientific modules for Python.",
      packages = ["Scientific",
                  "Scientific.Functions",
                  "Scientific.Geometry",
                  "Scientific.IO",
                  "Scientific.Physics",
                  "Scientific.Statistics",
                  "Scientific.TkWidgets",
                  "Scientific.Visualization"],
      ext_modules = [Extension("Scientific_netcdf",
                               ["Src/Scientific_netcdf.c"],
                               include_dirs = incdirs,
                               library_dirs = libdirs,
                               libraries = ["netcdf"]
                               )
                     ],
      )
