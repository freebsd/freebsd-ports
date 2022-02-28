PORTNAME=	docstring-parser
DISTVERSION=	0.13
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	docstring_parser-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parse Python docstrings in ReST, Google and Numpydoc format

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
