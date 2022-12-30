# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='uvicorn',
    version='%%PORTVERSION%%',
    description='The lightning-fast ASGI server.',
    long_description='<p align="center">\n  <img width="320" height="320" src="https://raw.githubusercontent.com/tomchristie/uvicorn/master/docs/uvicorn.png" alt=\'uvicorn\'>\n</p>\n\n<p align="center">\n<em>An ASGI web server, for Python.</em>\n</p>\n\n---\n\n[![Build Status](https://github.com/encode/uvicorn/workflows/Test%20Suite/badge.svg)](https://github.com/encode/uvicorn/actions)\n[![Package version](https://badge.fury.io/py/uvicorn.svg)](https://pypi.python.org/pypi/uvicorn)\n\n**Documentation**: [https://www.uvicorn.org](https://www.uvicorn.org)\n\n**Requirements**: Python 3.7+ (For Python 3.6 support, install version 0.16.0.)\n\nUvicorn is an ASGI web server implementation for Python.\n\nUntil recently Python has lacked a minimal low-level server/application interface for\nasync frameworks. The [ASGI specification][asgi] fills this gap, and means we\'re now able to\nstart building a common set of tooling usable across all async frameworks.\n\nUvicorn supports HTTP/1.1 and WebSockets.\n\n## Quickstart\n\nInstall using `pip`:\n\n```shell\n$ pip install uvicorn\n```\n\nThis will install uvicorn with minimal (pure Python) dependencies.\n\n```shell\n$ pip install uvicorn[standard]\n```\n\nThis will install uvicorn with "Cython-based" dependencies (where possible) and other "optional extras".\n\nIn this context, "Cython-based" means the following:\n\n- the event loop `uvloop` will be installed and used if possible.\n- the http protocol will be handled by `httptools` if possible.\n\nMoreover, "optional extras" means that:\n\n- the websocket protocol will be handled by `websockets` (should you want to use `wsproto` you\'d need to install it manually) if possible.\n- the `--reload` flag in development mode will use `watchfiles`.\n- windows users will have `colorama` installed for the colored logs.\n- `python-dotenv` will be installed should you want to use the `--env-file` option.\n- `PyYAML` will be installed to allow you to provide a `.yaml` file to `--log-config`, if desired.\n\nCreate an application, in `example.py`:\n\n```python\nasync def app(scope, receive, send):\n    assert scope[\'type\'] == \'http\'\n\n    await send({\n        \'type\': \'http.response.start\',\n        \'status\': 200,\n        \'headers\': [\n            [b\'content-type\', b\'text/plain\'],\n        ],\n    })\n    await send({\n        \'type\': \'http.response.body\',\n        \'body\': b\'Hello, world!\',\n    })\n```\n\nRun the server:\n\n```shell\n$ uvicorn example:app\n```\n\n---\n\n## Why ASGI?\n\nMost well established Python Web frameworks started out as WSGI-based frameworks.\n\nWSGI applications are a single, synchronous callable that takes a request and returns a response.\nThis doesn’t allow for long-lived connections, like you get with long-poll HTTP or WebSocket connections,\nwhich WSGI doesn\'t support well.\n\nHaving an async concurrency model also allows for options such as lightweight background tasks,\nand can be less of a limiting factor for endpoints that have long periods being blocked on network\nI/O such as dealing with slow HTTP requests.\n\n---\n\n## Alternative ASGI servers\n\nA strength of the ASGI protocol is that it decouples the server implementation\nfrom the application framework. This allows for an ecosystem of interoperating\nwebservers and application frameworks.\n\n### Daphne\n\nThe first ASGI server implementation, originally developed to power Django Channels, is [the Daphne webserver][daphne].\n\nIt is run widely in production, and supports HTTP/1.1, HTTP/2, and WebSockets.\n\nAny of the example applications given here can equally well be run using `daphne` instead.\n\n```\n$ pip install daphne\n$ daphne app:App\n```\n\n### Hypercorn\n\n[Hypercorn][hypercorn] was initially part of the Quart web framework, before\nbeing separated out into a standalone ASGI server.\n\nHypercorn supports HTTP/1.1, HTTP/2, and WebSockets.\n\nIt also supports [the excellent `trio` async framework][trio], as an alternative to `asyncio`.\n\n```\n$ pip install hypercorn\n$ hypercorn app:App\n```\n\n### Mangum\n\n[Mangum][mangum] is an adapter for using ASGI applications with AWS Lambda & API Gateway.\n\n---\n\n<p align="center"><i>Uvicorn is <a href="https://github.com/encode/uvicorn/blob/master/LICENSE.md">BSD licensed</a> code.<br/>Designed & crafted with care.</i><br/>&mdash; 🦄  &mdash;</p>\n\n[asgi]: https://asgi.readthedocs.io/en/latest/\n[daphne]: https://github.com/django/daphne\n[hypercorn]: https://gitlab.com/pgjones/hypercorn\n[mangum]: https://mangum.io\n[trio]: https://trio.readthedocs.io\n',
    author_email='Tom Christie <tom@tomchristie.com>',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Environment :: Web Environment',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
        'Topic :: Internet :: WWW/HTTP',
    ],
    install_requires=[
        'click>=7.0',
        'h11>=0.8',
        'typing-extensions; python_version < "3.8"',
    ],
    extras_require={
        'standard': [
            'colorama>=0.4; sys_platform == "win32"',
            'httptools>=0.5.0',
            'python-dotenv>=0.13',
            'pyyaml>=5.1',
            'uvloop!=0.15.0,!=0.15.1,>=0.14.0; sys_platform != "win32" and (sys_platform != "cygwin" and platform_python_implementation != "PyPy")',
            'watchfiles>=0.13',
            'websockets>=10.4',
        ],
    },
    entry_points={
        'console_scripts': [
            'uvicorn = uvicorn.main:main',
        ],
    },
    packages=[
        'uvicorn',
        'uvicorn.lifespan',
        'uvicorn.loops',
        'uvicorn.middleware',
        'uvicorn.protocols',
        'uvicorn.protocols.http',
        'uvicorn.protocols.websockets',
        'uvicorn.supervisors',
    ],
)
