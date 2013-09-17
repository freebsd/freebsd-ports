# Created by: arved
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	2.0.17
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/eigen/eigen/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	2

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

USE_BZIP2=	yes
USES=		cmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-b23437e61a07

post-patch:
	@${REINPLACE_CMD} -e 's|share/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
