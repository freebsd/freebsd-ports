# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	3.2.7
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${PORTNAME}/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL21 MPL
LICENSE_COMB=	multi

USES=		cmake:outsource tar:bzip2
CONFIGURE_ENV+=	PKG_CONFIG_LIBDIR="${PREFIX}/libdata"
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-b30b87236a1b

.include <bsd.port.mk>
