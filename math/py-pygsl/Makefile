# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	pygsl
PORTVERSION=	2.3.0
DISTVERSIONSUFFIX=	.1
PORTREVISION=	6
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to GNU Scientific Library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
