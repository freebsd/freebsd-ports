# $FreeBSD$

PORTNAME=	primme
DISTVERSION=	2.1.5.20181011 # need the latest changes, but github repo is mistagged, no regular github tag available
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
GH_TAGNAME=	6a0fa27
USE_PYTHON=	distutils autoplist
TEST_TARGET=	test

WRKSRC_SUBDIR=	Python
BINARY_ALIAS=	python2=${PYTHON_CMD}

post-test: # not sure why does the 'test' target tun examples and not tests
	@cd ${WRKSRC} && ${PYTHON_CMD} ${WRKSRC}/tests.py

.include <bsd.port.mk>
