# Created by: Antoine Brodin <antoine@FreeBSD.org>

PORTNAME=	pytsk
PORTVERSION=	20210327
CATEGORIES=	sysutils security devel python
MASTER_SITES=	https://github.com/py4n6/pytsk/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}3-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_TARGET=	# empty

.include <bsd.port.mk>
