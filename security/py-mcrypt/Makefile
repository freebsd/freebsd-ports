# Created by: ijliao
# $FreeBSD$

PORTNAME=	mcrypt
PORTVERSION=	1.1
CATEGORIES=	security python
MASTER_SITES=	SF/python-${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-mcrypt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive Python interface to the mcrypt library

LIB_DEPENDS=	libmcrypt.so:${PORTSDIR}/security/libmcrypt

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib
PYDISTUTILS_BUILD_TARGET=	build_ext
CFLAGS+=	-I${LOCALBASE}/include

pre-patch:
	# put a missed terminating quote
	${REINPLACE_CMD} -e '1136s,$$,\\,g' -e '1678s,$$,\\,g' ${WRKSRC}/mcrypt.c

.include <bsd.port.mk>
