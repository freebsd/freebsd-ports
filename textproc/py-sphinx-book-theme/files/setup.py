from setuptools import setup

setup(
    name = 'sphinx-book-theme',
    version = '%%PORTVERSION%%',
    description = 'A clean book theme for scientific explanations and documentation with Sphinx',
    maintainer = 'Chris Holdgraf',
    maintainer_email = 'choldgraf@gmail.com',
    url = None,
    packages = ['sphinx_book_theme'],
    package_dir = {'': 'src'},
    package_data = {'': ['*']},
    install_requires = [
        'sphinx>=3,<5',
        'pydata-sphinx-theme~=0.8.0',
        'pyyaml',
    ],
    extras_require = {
        'code_style': [
            'pre-commit~=2.7.0'
        ],
        'doc': [
            'ablog~=0.10.13',
            'ipywidgets',
            'folium',
            'numpy',
            'matplotlib',
            'numpydoc',
            'myst-nb~=0.13',
            'nbclient',
            'pandas',
            'plotly',
            'sphinx~=4.0',  # Force Sphinx to be the latest version
            'sphinx-design',
            'sphinx-copybutton',
            'sphinx-tabs',
            'sphinx-togglebutton>=0.2.1',
            'sphinx-thebe>=0.1.1',
            'sphinxcontrib-bibtex~=2.2',
            'sphinxcontrib-youtube',
            'sphinxext-opengraph',
        ],
        'test': [
            'beautifulsoup4>=4.6.1,<5',
            'coverage',
            'myst_nb~=0.13',
            'pytest~=6.0.1',
            'pytest-cov',
            'pytest-regressions~=2.0.1',
            'sphinx_thebe'
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
    python_requires = '>= 3.7',
)
