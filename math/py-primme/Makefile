# $FreeBSD$

PORTNAME=	primme
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PRIMME wrapper for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING.txt

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libprimme.so:math/primme
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		fortran gmake localbase:ldflags python shebangfix
SHEBANG_FILES=	examples.py tests.py
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist
TEST_TARGET=	test

WRKSRC_SUBDIR=	Python
BINARY_ALIAS=	python2=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} "s|\['../lib/libprimme.a'\]|['${LOCALBASE}/lib/libprimme.so']|" ${WRKSRC}/setup.py

post-test: # not sure why does the 'test' target run examples and not tests
	@cd ${WRKSRC} && ${PYTHON_CMD} ${WRKSRC}/tests.py

.include <bsd.port.mk>
