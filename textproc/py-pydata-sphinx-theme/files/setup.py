from setuptools import setup

setup(
    name = 'pydata-sphinx-theme',
    version = '%%PORTVERSION%%',
    description = 'Bootstrap-based Sphinx theme from the PyData community',
    maintainer = 'Joris Van den Bossche',
    maintainer_email = 'jorisvandenbossche@gmail.com',
    url = None,
    packages = ['pydata_sphinx_theme'],
    package_dir = {'': 'src'},
    package_data = {'': ['*']},
    install_requires = [
        'sphinx>=3.5.4,<5',
        'beautifulsoup4',
        'docutils!=0.17.0',
        'packaging',
    ],
    extras_require = {
        'doc': [
            'numpydoc',
            'myst-parser',
            'pandas',
            'pytest',
            'pytest-regressions',
            'sphinxext-rediraffe',
            'sphinx-sitemap',
            # For demo examples
            'jupyter_sphinx',
            'plotly',
            'numpy',
            'xarray',
        ],
        'test': [
            'pytest',
            'pydata-sphinx-theme[doc]',
        ],
        'coverage': [
            'pytest-cov',
            'codecov',
            'pydata-sphinx-theme[test]',
        ],
        'dev': [
            'pyyaml',
            'pre-commit',
            'nox',
            'pydata-sphinx-theme[coverage]',
        ],
    },
    entry_points = {
        'sphinx.html_themes': ['pydata_sphinx_theme = pydata_sphinx_theme'],
    },
    classifiers = [
        'Development Status :: 4 - Beta',
        'Programming Language :: Python :: 3',
        'Framework :: Sphinx',
        'Framework :: Sphinx :: Theme',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
    ],
    license = 'BSD License',
    python_requires = '>= 3.7',
)
