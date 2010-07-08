# Ports collection makefile for:	py-libtre
# Date created:				6 June 2007
# Whom:					bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.8.0
CATEGORIES=	textproc python
MASTER_SITES=	http://laurikari.net/tre/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Python interface for the tre regular expressions library

LIB_DEPENDS=	tre.5:${PORTSDIR}/textproc/libtre

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	tre

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

CFLAGS+=	-I${LOCALBASE}/include/ -L${LOCALBASE}/lib/

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations \
		-fforce-mem -fforce-addr -O3
.endif

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/tre.so

.include <bsd.port.mk>
