# -*- coding: utf-8 -*-
from setuptools import setup

import codecs

with codecs.open('README.md', encoding="utf-8") as fp:
    long_description = fp.read()
EXTRAS_REQUIRE = {
    'toc': [
        'python-slugify',
    ],
    'codehilite': [
        'pygments',
    ],
}
ENTRY_POINTS = {
    'console_scripts': [
        'marko = marko.cli:main',
    ],
}

setup_kwargs = {
    'name': 'marko',
    'version': '%%PORTVERSION%%',
    'description': 'A markdown parser with high extensibility.',
    'long_description': long_description,
    'license': 'MIT',
    'author': '',
    'author_email': 'Frost Ming <mianghong@gmail.com>',
    'maintainer': None,
    'maintainer_email': None,
    'url': 'https://github.com/frostming/marko',
    'packages': [
        'marko',
        'marko.ext',
        'marko.ext.gfm',
    ],
    'package_data': {'': ['*']},
    'long_description_content_type': 'text/markdown',
    'classifiers': [
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'Operating System :: OS Independent',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
    ],
    'extras_require': EXTRAS_REQUIRE,
    'python_requires': '>=3.7',
    'entry_points': ENTRY_POINTS,
}

setup(**setup_kwargs)
