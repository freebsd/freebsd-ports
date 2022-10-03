# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='starlette',
    version='%%PORTVERSION%%',
    description='The little ASGI library that shines.',
    long_description='<p align="center">\n  <a href="https://www.starlette.io/"><img width="420px" src="https://raw.githubusercontent.com/encode/starlette/master/docs/img/starlette.png" alt=\'starlette\'></a>\n</p>\n<p align="center">\n    <em>✨ The little ASGI framework that shines. ✨</em>\n</p>\n<p align="center">\n<a href="https://github.com/encode/starlette/actions">\n    <img src="https://github.com/encode/starlette/workflows/Test%20Suite/badge.svg" alt="Build Status">\n</a>\n<a href="https://pypi.org/project/starlette/">\n    <img src="https://badge.fury.io/py/starlette.svg" alt="Package version">\n</a>\n</p>\n\n---\n\n**Documentation**: [https://www.starlette.io/](https://www.starlette.io/)\n\n---\n\n# Starlette\n\nStarlette is a lightweight [ASGI][asgi] framework/toolkit,\nwhich is ideal for building async web services in Python.\n\nIt is production-ready, and gives you the following:\n\n* A lightweight, low-complexity HTTP web framework.\n* WebSocket support.\n* In-process background tasks.\n* Startup and shutdown events.\n* Test client built on `httpx`.\n* CORS, GZip, Static Files, Streaming responses.\n* Session and Cookie support.\n* 100% test coverage.\n* 100% type annotated codebase.\n* Few hard dependencies.\n* Compatible with `asyncio` and `trio` backends.\n* Great overall performance [against independent benchmarks][techempower].\n\n## Requirements\n\nPython 3.7+ (For Python 3.6 support, install version 0.19.1)\n\n## Installation\n\n```shell\n$ pip3 install starlette\n```\n\nYou\'ll also want to install an ASGI server, such as [uvicorn](http://www.uvicorn.org/), [daphne](https://github.com/django/daphne/), or [hypercorn](https://pgjones.gitlab.io/hypercorn/).\n\n```shell\n$ pip3 install uvicorn\n```\n\n## Example\n\n**example.py**:\n\n```python\nfrom starlette.applications import Starlette\nfrom starlette.responses import JSONResponse\nfrom starlette.routing import Route\n\n\nasync def homepage(request):\n    return JSONResponse({\'hello\': \'world\'})\n\nroutes = [\n    Route("/", endpoint=homepage)\n]\n\napp = Starlette(debug=True, routes=routes)\n```\n\nThen run the application using Uvicorn:\n\n```shell\n$ uvicorn example:app\n```\n\nFor a more complete example, see [encode/starlette-example](https://github.com/encode/starlette-example).\n\n## Dependencies\n\nStarlette only requires `anyio`, and the following are optional:\n\n* [`httpx`][httpx] - Required if you want to use the `TestClient`.\n* [`jinja2`][jinja2] - Required if you want to use `Jinja2Templates`.\n* [`python-multipart`][python-multipart] - Required if you want to support form parsing, with `request.form()`.\n* [`itsdangerous`][itsdangerous] - Required for `SessionMiddleware` support.\n* [`pyyaml`][pyyaml] - Required for `SchemaGenerator` support.\n\nYou can install all of these with `pip3 install starlette[full]`.\n\n## Framework or Toolkit\n\nStarlette is designed to be used either as a complete framework, or as\nan ASGI toolkit. You can use any of its components independently.\n\n```python\nfrom starlette.responses import PlainTextResponse\n\n\nasync def app(scope, receive, send):\n    assert scope[\'type\'] == \'http\'\n    response = PlainTextResponse(\'Hello, world!\')\n    await response(scope, receive, send)\n```\n\nRun the `app` application in `example.py`:\n\n```shell\n$ uvicorn example:app\nINFO: Started server process [11509]\nINFO: Uvicorn running on http://127.0.0.1:8000 (Press CTRL+C to quit)\n```\n\nRun uvicorn with `--reload` to enable auto-reloading on code changes.\n\n## Modularity\n\nThe modularity that Starlette is designed on promotes building re-usable\ncomponents that can be shared between any ASGI framework. This should enable\nan ecosystem of shared middleware and mountable applications.\n\nThe clean API separation also means it\'s easier to understand each component\nin isolation.\n\n---\n\n<p align="center"><i>Starlette is <a href="https://github.com/encode/starlette/blob/master/LICENSE.md">BSD licensed</a> code.<br/>Designed & crafted with care.</i></br>&mdash; ⭐️ &mdash;</p>\n\n[asgi]: https://asgi.readthedocs.io/en/latest/\n[httpx]: https://www.python-httpx.org/\n[jinja2]: http://jinja.pocoo.org/\n[python-multipart]: https://andrew-d.github.io/python-multipart/\n[itsdangerous]: https://pythonhosted.org/itsdangerous/\n[sqlalchemy]: https://www.sqlalchemy.org\n[pyyaml]: https://pyyaml.org/wiki/PyYAMLDocumentation\n[techempower]: https://www.techempower.com/benchmarks/#hw=ph&test=fortune&l=zijzen-sf\n',
    author_email='Tom Christie <tom@tomchristie.com>',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Environment :: Web Environment',
        'Framework :: AnyIO',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Topic :: Internet :: WWW/HTTP',
    ],
    install_requires=[
        'anyio<5,>=3.4.0',
        'typing-extensions>=3.10.0; python_version < "3.10"',
    ],
    extras_require={
        'full': [
            'httpx>=0.22.0',
            'itsdangerous',
            'jinja2',
            'python-multipart',
            'pyyaml',
        ],
    },
    packages=[
        'starlette',
        'starlette.middleware',
    ],
)
