PORTNAME=	python-lsp-black
DISTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Black plugin for the Python LSP Server
WWW=		https://github.com/python-lsp/python-lsp-black

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-lsp-server>=1.4.0:textproc/py-python-lsp-server@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
