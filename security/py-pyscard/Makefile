# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	pyscard
PORTVERSION=	1.7.0
CATEGORIES=	security python
## request has been submitted to the developers to host sources on PyPI; check
## this on the next update and change SF to CHEESEHOP (see bug #197834)
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mp39590@gmail.com
COMMENT=	Smartcard module for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13 \
		pcsc-lite>0:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS=	pcsc-lite>0:${PORTSDIR}/devel/pcsc-lite

USES=		python:2
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=       build_ext
PYDISTUTILS_BUILDARGS+=         --include-dirs=${LOCALBASE}/include/PCSC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/smartcard/scard/_scard.so

.include <bsd.port.mk>
