# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	pyscard
PORTVERSION=	1.9.6
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mp39590@gmail.com
COMMENT=	Smartcard module for Python

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		pcsc-lite>0:devel/pcsc-lite
RUN_DEPENDS=	pcsc-lite>0:devel/pcsc-lite

## Python3 is supported
USES=		python:2.7+
USE_PYTHON=	autoplist distutils
BINARY_ALIAS=	swig=swig3.0

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=	--include-dirs=${LOCALBASE}/include/PCSC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/smartcard/scard/_scard.so

.include <bsd.port.mk>
