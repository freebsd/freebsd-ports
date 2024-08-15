from setuptools import setup

setup(
    name = 'sphinx-book-theme',
    version = '%%PORTVERSION%%',
    description = 'A clean book theme for scientific explanations and documentation with Sphinx',
    maintainer = 'Executable Books Team',
    maintainer_email = 'executablebooks@gmail.com',
    url = None,
    packages = [
        'sphinx_book_theme',
        'sphinx_book_theme.header_buttons',
    ],
    package_dir = {'': 'src'},
    package_data = {'': ['*']},
    install_requires = [
        'sphinx>=5',
        'pydata-sphinx-theme>=0.15.2',
    ],
    extras_require = {
        'code_style': [
            'pre-commit'
        ],
        'doc': [
            'ablog',
            'ipywidgets',
            'folium',
            'numpy',
            'matplotlib',
            'numpydoc',
            'myst-nb',
            'nbclient',
            'pandas',
            'plotly',
            'sphinx-design',
            'sphinx-examples',
            'sphinx-copybutton',
            'sphinx-tabs'
            'sphinx-togglebutton',
            'sphinx-thebe',
            'sphinxcontrib-bibtex',
            'sphinxcontrib-youtube',
            'sphinxext-opengraph',
        ],
        'test': [
            'beautifulsoup4',
            'coverage',
            'defusedxml',
            'myst-nb',
            'pytest',
            'pytest-cov',
            'pytest-regressions',
            'sphinx_thebe',
        ],
    },
    entry_points = {
        'sphinx.html_themes': ['sphinx_book_theme = sphinx_book_theme'],
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
    python_requires = '>= 3.9',
)
