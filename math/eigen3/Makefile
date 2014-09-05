# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	3.2.2
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${PORTNAME}/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL21 MPL
LICENSE_COMB=	multi

USES=		cmake:outsource tar:bzip2
CMAKE_ENV+=	PKG_CONFIG_LIBDIR="${LOCALBASE}/libdata"
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-1306d75b4a21

.include <bsd.port.mk>
