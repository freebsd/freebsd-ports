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
        'sphinx>=5',
        'beautifulsoup4',
        'docutils!=0.17.0',
        'packaging',
        'Babel',
        'pygments>=2.7',
        'accessible-pygments',
        'typing-extensions'
    ],
    extras_require = {
        'doc': [
            'numpydoc',
            'linkify-it-py',  # for link shortening
            'rich',
            'sphinxext-rediraffe',
            'sphinx-sitemap',
            'sphinx-autoapi>=3.0.0',
            # For examples section
            'myst-parser',
            'ablog>=0.11.8',
            'jupyter_sphinx',
            'pandas',
            'plotly',
            'matplotlib',
            'numpy',
            'xarray',
            'sphinx-copybutton',
            'sphinx-design',
            'sphinx-togglebutton',
            'jupyterlite-sphinx',
            'sphinxcontrib-youtube>=1.4.1',
            'sphinx-favicon>=1.0.1',
            # Install nbsphinx in case we want to test it locally even though we can't load
            # it at the same time as MyST-NB.
            'ipykernel',
            'nbsphinx',
            'ipyleaflet',
            'colorama',
            'ipywidgets',
            'graphviz',
        ],
        'test': [
            'pytest',
            'pytest-cov',
            'pytest-regressions',
            'sphinx[test]',
        ],
        'dev': [
            'pyyaml',
            'pre-commit',
            'pydata-sphinx-theme[doc,test]',
            'tox',
            'pandoc',
            'sphinx-theme-builder[cli]',
        ],
        'a11y': [
            'pytest-playwright',
        ],
        'i18n': [
            'Babel',
            'jinja2',
        ],
    },
    entry_points = {
        'sphinx.html_themes': ['pydata_sphinx_theme = pydata_sphinx_theme'],
    },
    classifiers = [
        'Development Status :: 5 - Production/Stable',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: 3.12',
        'Framework :: Sphinx',
        'Framework :: Sphinx :: Theme',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
    ],
    license = 'BSD License',
    python_requires = '>= 3.7',
)
