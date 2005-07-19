# ex:ts=8
# Ports collection makefile for:	py-mcrypt
# Date created:			Jul 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mcrypt
PORTVERSION=	1.1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-mcrypt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-mcrypt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive Python interface to the mcrypt library

LIB_DEPENDS=	mcrypt:${PORTSDIR}/security/libmcrypt

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/mcrypt.so

pre-patch:
	# put a missed terminating quote
	${REINPLACE_CMD} -e '1136s,$$,\\,g' -e '1678s,$$,\\,g' ${WRKSRC}/mcrypt.c

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${PYDISTUTILS_BUILDARGS})

.include <bsd.port.mk>
