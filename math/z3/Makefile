# $FreeBSD$

PORTNAME=	z3
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	4.6.0
CATEGORIES=	math

MAINTAINER=	6yearold@gmail.com
COMMENT=	Z3 Theorem Prover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_powerpc64=	Does not build
# compiler picks ${LOCALBASE}/include/dictionary.h from iniparser
CONFLICTS=		iniparser-*

USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover

OPTIONS_DEFINE=		DEBUG STATIC PYTHON GMP

OPTIONS_DEFAULT=	STATIC PYTHON
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--debug

PYTHON_DESC=		Enable python bindings
PYTHON_CONFIGURE_ON=	--python
PYTHON_USES=		python:2.7
PYTHON_USES_OFF=	python:2.7,build
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

STATIC_DESC=		Build static z3 library
STATIC_CONFIGURE_ON=	--staticlib

GMP_DESC=		Use GMP library for AP arithmetic
GMP_CONFIGURE_ON=	--gmp
GMP_CXXFLAGS=		-I${LOCALBASE}/include
GMP_LDFLAGS=		-L${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
USE_LDCONFIG=		yes
BUILD_WRKSRC=		${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/z3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libz3.so
	${LN} -s libz3.so ${STAGEDIR}${PREFIX}/lib/libz3.so.0

.include <bsd.port.mk>
