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

LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${PYDISTUTILS_BUILDARGS})

.include <bsd.port.mk>
