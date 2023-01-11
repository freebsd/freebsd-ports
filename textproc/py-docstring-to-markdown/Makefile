PORTNAME=	docstring-to-markdown
PORTVERSION=	0.11
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	On the fly conversion of Python docstrings to markdown
WWW=		https://github.com/python-lsp/docstring-to-markdown

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
