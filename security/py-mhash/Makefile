# ex:ts=8
# Ports collection makefile for:	py-mhash
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	1.0
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mhash
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-mhash-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python mhash module

LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/mhash.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

pre-patch:
	${REINPLACE_CMD} -e '227s,$$,\\,' ${WRKSRC}/mhash.c # put a missed terminating quote

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${PYDISTUTILS_BUILDARGS})

.include <bsd.port.mk>
