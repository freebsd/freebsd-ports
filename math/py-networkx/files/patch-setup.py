#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Setup script for networkx

You can install networkx with

python setup_egg.py install
"""
from glob import glob
import os
import sys
if os.path.exists('MANIFEST'): os.remove('MANIFEST')

from distutils.core import setup

if sys.argv[-1] == 'setup.py':
    print("To install, run 'python setup.py install'")
    print()

if sys.version_info[:2] < (2, 6):
    print("NetworkX requires Python version 2.6 or later (%d.%d detected)." %
          sys.version_info[:2])
    sys.exit(-1)

# Write the version information.
sys.path.insert(0, 'networkx')
import release
version = release.write_versionfile()
sys.path.pop(0)

packages=["networkx",
          "networkx.algorithms",
          "networkx.algorithms.centrality",
          "networkx.algorithms.chordal",
          "networkx.algorithms.components",
          "networkx.algorithms.flow",
          "networkx.algorithms.traversal",
          "networkx.algorithms.isomorphism",
          "networkx.algorithms.shortest_paths",
          "networkx.algorithms.link_analysis",
          "networkx.classes",
          "networkx.generators",
          "networkx.drawing",
          "networkx.linalg",
          "networkx.readwrite",
          "networkx.tests"]

# add the tests
package_data     = {
    'networkx': ['tests/*.py'],
    'networkx.algorithms': ['tests/*.py'],
    'networkx.algorithms.centrality': ['tests/*.py'],
    'networkx.algorithms.components': ['tests/*.py'],
    'networkx.algorithms.flow': ['tests/*.py'],
    'networkx.algorithms.traversal': ['tests/*.py'],
    'networkx.algorithms.isomorphism': ['tests/*.py','tests/*.*99'],
    'networkx.algorithms.link_analysis': ['tests/*.py'],
    'networkx.algorithms.shortest_paths': ['tests/*.py'],
    'networkx.algorithms.traversal': ['tests/*.py'],
    'networkx.classes': ['tests/*.py'],
    'networkx.generators': ['tests/*.py'],
    'networkx.drawing': ['tests/*.py'],
    'networkx.linalg': ['tests/*.py'],
    'networkx.readwrite': ['tests/*.py']
    }

if __name__ == "__main__":

    setup(
        name             = release.name.lower(),
        version          = version,
        maintainer       = release.maintainer,
        maintainer_email = release.maintainer_email,
        author           = release.authors['Hagberg'][0],
        author_email     = release.authors['Hagberg'][1],
        description      = release.description,
        keywords         = release.keywords,
        long_description = release.long_description,
        license          = release.license,
        platforms        = release.platforms,
        url              = release.url,      
        download_url     = release.download_url,
        classifiers      = release.classifiers,
        packages         = packages,
        package_data     = package_data
      )

