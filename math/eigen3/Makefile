# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	3.3.4
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${PORTNAME}/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	multi

CMAKE_ARGS=	-DPKGCONFIG_INSTALL_DIR:PATH="${PREFIX}/libdata/pkgconfig"
USES=		cmake:outsource tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-5a0156e40feb

.include <bsd.port.mk>
